#ifndef HX711_HPP_
#define HX711_HPP_


#include <stdint.h>


class HX711 {
  uint8_t dataPin;
  uint8_t clockPin;
  uint8_t gain_ch_pulses;

 public:
  enum gain_pulses {
    CHANNEL_A_128 = 1,
    CHANNEL_A_64 = 3,
    CHANNEL_B_32 = 2,
  };
  
  HX711(uint8_t dataPin, uint8_t clockPin, uint8_t gain_ch_pulses=CHANNEL_A_64):
      dataPin(dataPin), clockPin(clockPin), gain_ch_pulses(gain_ch_pulses) {
  }
  
  void begin() {
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);
  }

  bool is_ready() {
    return digitalRead(dataPin) == LOW;
  }
  
  int32_t read(int8_t pulses_next=-1) {
    // Define which channel will be read next (default or specified)
    int gain_ch_pulses = pulses_next < 0 ? this->gain_ch_pulses : pulses_next;
    
    // Wait for chip to become ready
    while (!is_ready());
    
    // Read the data
    int32_t data = (int32_t)shiftIn(dataPin, clockPin, MSBFIRST) << 16
      | (int32_t)shiftIn(dataPin, clockPin, MSBFIRST) << 8
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

#endif//HX711_HPP_
