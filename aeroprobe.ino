/** 5 Hole aerodynamic probe
 *  CEA-UFMG
 *  Joel Laguardia / Dimas Abreu Dutra
 */


#include <Wire.h>

#include "BMP180.h"
#include "mavlink_bridge.h"
#include "mavlink/ceaufmg/mavlink.h"


#define ANGLES_PERIOD_US 30000
#define QBAR_PERIOD_US 100000L
#define PRESS_PERIOD_US 100000L
#define TEMP_PERIOD_US 1000000L

#define PRESS_CONV_US 4500
#define TEMP_CONV_US 4500


class HX711 {
  uint8_t dataPin;
  uint8_t clockPin;
  uint8_t gain_ch_pulses;
  
public:
  HX711(uint8_t dataPin, uint8_t clockPin):
    dataPin(dataPin), clockPin(clockPin), gain_ch_pulses(3) {
  }
  
  void begin() {
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);
  }

  bool is_ready() {
    return digitalRead(dataPin) == LOW;
  }
  
  uint32_t read() {
    // Wait for chip to become ready
    while (!is_ready());

    // Read the data
    uint32_t data = (uint32_t)shiftIn(dataPin, clockPin, MSBFIRST) << 16
      | (uint32_t)shiftIn(dataPin, clockPin, MSBFIRST) << 8
      | shiftIn(dataPin, clockPin, MSBFIRST);

    // Configure the next measurement channel and gain
    for (uint8_t i = 0; i < gain_ch_pulses; i++) {
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
    }

    // Extend the signal bit into the 4th data byte
    if (data & 0x800000ul)
      data |= 0xFF000000ul;
    return data;
  }
};

HX711 hx711(4, 3);
BMP180 bmp180;


/**
 * Microseconds since boot as an uint64_t.
 * Internally uses only 40 bits, so overflows roughly every 12 days.
 * To work, this function must be called at least once every 35 minutes.
 */
uint64_t micros64() {
  static uint8_t overflow_count = 0;
  static uint8_t last_micros_msb = false;

  // Get current time
  uint32_t now = micros();

  // Check for overflow
  uint8_t micros_msb = now >> 31;
  if (last_micros_msb && !micros_msb)
    overflow_count++;
  last_micros_msb = micros_msb;

  // Pack and return
  return ((uint64_t)overflow_count << 32) | now;
}


void setup() {
  Serial.begin(57600);
  Wire.begin();
  
  hx711.begin();
  bmp180.begin(BMP180_ULTRALOWPOWER);
}



void loop() {
  static uint64_t last_angles_meas = 0;
  static uint64_t last_qbar_meas = 0;
  static uint64_t last_press_meas = 0;
  static uint64_t last_temp_meas = 0;
  static bool converting_temp = false;
  static bool converting_press = false;

  uint64_t now = micros64();

  // Temperature measurement
  if (!converting_temp && !converting_press
      && (now - last_temp_meas) > TEMP_PERIOD_US) {
    bmp180.triggerTemperatureMeasurement();
    converting_temp = true;
    last_temp_meas = micros64();
  } else if (converting_temp && (now - last_temp_meas) > TEMP_CONV_US) {
    converting_temp = false;
    int32_t temp = bmp180.readTemperature();
    mavlink_msg_data_int_send(MAVLINK_COMM_0, last_temp_meas, 
                              CEAFDAS_DATA_SOUCE_TEMPERATURE_RAW, temp);
  }
  
  // Pressure measurement
  if (!converting_temp && !converting_press
      && (now - last_press_meas) > PRESS_PERIOD_US) {
    bmp180.triggerPressureMeasurement();
    converting_press = true;
    last_press_meas = micros64();
  } else if (converting_press && (now - last_press_meas) > PRESS_CONV_US) {
    converting_press = false;
    int32_t press = bmp180.readPressure();
    mavlink_msg_data_int_send(MAVLINK_COMM_0, last_press_meas,
                              CEAFDAS_DATA_SOUCE_PRESSURE_RAW, press);
  }

  // Dynamic pressure measurement
  if (now - last_qbar_meas > QBAR_PERIOD_US) {
    uint32_t qbar = hx711.read();

    mavlink_msg_data_int_send(MAVLINK_COMM_0, last_qbar_meas,
                              CEAFDAS_DATA_SOUCE_QBAR_RAW, qbar);
    last_qbar_meas = micros64();
  }
  
  // Aerodynamic angles measurement
  if (now - last_angles_meas > ANGLES_PERIOD_US) {
    last_angles_meas = micros64();
    uint16_t alpha = analogRead(A1);

    uint64_t beta_meas_time = micros64();
    uint16_t beta = analogRead(A0);

    mavlink_msg_data_int_send(MAVLINK_COMM_0, last_angles_meas,
                              CEAFDAS_DATA_SOUCE_ALPHA_RAW, alpha);
    mavlink_msg_data_int_send(MAVLINK_COMM_0, beta_meas_time,
                              CEAFDAS_DATA_SOUCE_BETA_RAW, beta);
  }
}
