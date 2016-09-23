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
  
  uint32_t now = millis();
  
  if (now - last_qbar_meas > QBAR_PERIOD_MS) {
    uint32_t qbar_raw = hx711.read();

    mavlink_msg_data_int_send(MAVLINK_COMM_0, 0, 
                              CEAFDAS_DATA_SOUCE_QBAR_RAW, qbar_raw);
    last_qbar_meas = now;
  }
  
  if (now - last_alpha_meas > ALPHA_PERIOD_MS) {
    uint16_t alpha_raw = analogRead(A1);
    uint16_t beta_raw = analogRead(A0);

    mavlink_msg_data_int_send(MAVLINK_COMM_0, 0, 
                              CEAFDAS_DATA_SOUCE_ALPHA_RAW, alpha_raw);
    mavlink_msg_data_int_send(MAVLINK_COMM_0, 0, 
                              CEAFDAS_DATA_SOUCE_BETA_RAW, beta_raw);
    last_alpha_meas = now;
  }
}
