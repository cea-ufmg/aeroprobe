/** 5 Hole aerodynamic probe
 *  CEA-UFMG
 *  Joel Laguardia / Dimas Abreu Dutra
 */


#include <Wire.h>

#include "hx711.hpp"
#include "ds3231.hpp"

#include "mavlink_bridge.h"
#include "mavlink/ceaufmg/mavlink.h"


constexpr uint32_t ANGLES_PERIOD_US = 120000;
constexpr uint32_t QBAR_PERIOD_US = 12500;
constexpr uint32_t PSTAT_PERIOD_US = 25000;

constexpr int LED_PIN = 2;

constexpr int ANGLES_HX711_DATA = 10;
constexpr int ANGLES_HX711_CLK = 9;
HX711 angles_hx711(ANGLES_HX711_DATA, ANGLES_HX711_CLK);

constexpr int QBAR_HX711_DATA = 11;
constexpr int QBAR_HX711_CLK = 12;
HX711 qbar_hx711(QBAR_HX711_DATA, QBAR_HX711_CLK, HX711::CHANNEL_A_64);

constexpr int PSTAT_PIN = A0;
constexpr int BATT_MON_PIN = A1;

static uint64_t last_angle_meas;
static uint64_t last_qbar_meas;
static uint64_t last_pstat_meas = 0;
static enum {
  ALPHA,
  BETA
} last_angle_channel;


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


inline void send_data(uint64_t time_usec, uint16_t data_source_id,
                      int32_t value) {
#ifndef TEXTUAL_DEBUG_PROTOCOL
  mavlink_msg_data_int_send(MAVLINK_COMM_0, time_usec, data_source_id, value);
#else
  Serial.print((uint32_t) time_usec);
  Serial.print("\t");

  Serial.print(data_source_id);
  Serial.print("\t");

  Serial.println(value);
#endif
}


inline void toggle_led() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}


void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  
  Serial.begin(230400);
  Wire.begin();

  
  qbar_hx711.begin();
  last_qbar_meas = micros64();
  qbar_hx711.read();

  angles_hx711.begin();
  last_angle_meas = micros64();
  angles_hx711.read(HX711::CHANNEL_A_64);
  last_angle_channel = ALPHA;
}


void loop() {
  uint64_t now;

  // Dynamic pressure measurement
  now = micros64();
  if (now - last_qbar_meas >= QBAR_PERIOD_US) {
    int32_t qbar_value = qbar_hx711.read();
    send_data(now, CEAFDAS_DATA_SOUCE_QBAR_RAW, qbar_value);
    
    last_qbar_meas = now;
    toggle_led();
  }

  // Angle of attack pressure measurement
  now = micros64();
  if (now - last_angle_meas >= ANGLES_PERIOD_US &&
      last_angle_channel == ALPHA) {
    int32_t angle_value = angles_hx711.read(HX711::CHANNEL_B_32);
    send_data(now, CEAFDAS_DATA_SOUCE_ALPHA_RAW, angle_value);
    
    last_angle_channel = BETA;
    last_angle_meas = now;
    toggle_led();
  }

  // Sideslip pressure measurement
  now = micros64();
  if (now - last_angle_meas >= ANGLES_PERIOD_US &&
      last_angle_channel == BETA) {
    int32_t angle_value = angles_hx711.read(HX711::CHANNEL_A_64);
    send_data(now, CEAFDAS_DATA_SOUCE_BETA_RAW, angle_value);
    
    last_angle_channel = ALPHA;
    last_angle_meas = now;
    toggle_led();
  }
  
  // Static pressure measurement
  now = micros64();
  if (now - last_pstat_meas >= PSTAT_PERIOD_US) {
    uint16_t pstat_value = analogRead(PSTAT_PIN);
    send_data(now, CEAFDAS_DATA_SOUCE_PRESSURE_RAW, pstat_value);
    
    last_pstat_meas = now;
    toggle_led();
  }
}
