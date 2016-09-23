/** 5 Hole aerodynamic probe
 *  CEA-UFMG
 *  Joel Laguardia / Dimas Abreu Dutra
 */


#include <Wire.h>

#include "BMP180.h"
#include "mavlink_bridge.h"
#include "mavlink/ceaufmg/mavlink.h"


#define ALPHA_PERIOD_MS 5
#define QBAR_PERIOD_MS 100
#define PRESS_PERIOD_MS 10
#define TEMP_PERIOD_MS 500

#define PRESS_CONV_MS 5
#define TEMP_CONV_MS 5


class HX711 {
  uint8_t dataPin;
  uint8_t clockPin;
  uint8_t gain_ch_pulses=2;
  
public:
  HX711(uint8_t dataPin, uint8_t clockPin):
    dataPin(dataPin), clockPin(clockPin) {
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

void setup() {
  Serial.begin(57600);
  Wire.begin();
  
  hx711.begin();
  bmp180.begin(BMP180_ULTRALOWPOWER);
}



void loop() {
  static uint32_t last_alpha_meas = 0;
  static uint32_t last_qbar_meas = 0;
  static uint32_t last_press_meas = 0;
  static uint32_t last_temp_meas = 0;
  static bool converting_temp = false;
  static bool converting_press = false;
  
  uint32_t now = millis();

  // Temperature measurement
  if (!converting_temp && (now - last_temp_meas) > TEMP_PERIOD_MS) {
    bmp180.triggerTemperatureMeasurement();
    converting_temp = true;
    last_temp_meas = now;
  } else if (converting_temp && (now - last_temp_meas) > TEMP_CONV_MS) {
    converting_temp = false;
    int32_t temp = bmp180.readTemperature();
    mavlink_msg_data_int_send(MAVLINK_COMM_0, 0, 
                              CEAFDAS_DATA_SOUCE_TEMPERATURE_RAW, temp);
  }
  
  // Pressure measurement
  if (!converting_temp && !converting_press &&
      (now - last_press_meas) > PRESS_PERIOD_MS) {
    bmp180.triggerPressureMeasurement();
    converting_press = true;
    last_press_meas = now;
  } else if (converting_press && (now - last_press_meas) > PRESS_CONV_MS) {
    converting_press = false;
    int32_t press = bmp180.readPressure();
    mavlink_msg_data_int_send(MAVLINK_COMM_0, 0, 
                              CEAFDAS_DATA_SOUCE_PRESSURE_RAW, press);
  }

  // Dynamic pressure measurement
  if (now - last_qbar_meas > QBAR_PERIOD_MS) {
    uint32_t qbar = hx711.read();

    mavlink_msg_data_int_send(MAVLINK_COMM_0, 0,
                              CEAFDAS_DATA_SOUCE_QBAR_RAW, qbar);
    last_qbar_meas = now;
  }
  
  // Aerodynamic angles measurement
  if (now - last_alpha_meas > ALPHA_PERIOD_MS) {
    uint16_t alpha = analogRead(A1);
    uint16_t beta = analogRead(A0);

    mavlink_msg_data_int_send(MAVLINK_COMM_0, 0, 
                              CEAFDAS_DATA_SOUCE_ALPHA_RAW, alpha);
    mavlink_msg_data_int_send(MAVLINK_COMM_0, 0, 
                              CEAFDAS_DATA_SOUCE_BETA_RAW, beta);
    last_alpha_meas = now;
  }
}
