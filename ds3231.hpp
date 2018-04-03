#ifndef DS3231_HPP_
#define DS3231_HPP_


#include <stdint.h>
#include <Wire.h>


class DS3231 {
 public:
  static constexpr uint8_t address = 0x68;
  
  static bool read_all(uint8_t *sec, uint8_t *min, uint8_t *hour,
                       uint8_t *weekday, uint8_t *day, uint8_t *month,
                       uint8_t *year) {
    Wire.beginTransmission(address);
    Wire.write(0);
    Wire.endTransmission();
    Wire.requestFrom(address, 7);

    uint8_t reg;
    if (Wire.available() != 7)
      return false;
    
    reg = Wire.read();
    if (sec) {
      *sec = (reg & 0xF) + (reg >> 4) * 10;
    }
    
    reg = Wire.read();
    if (min) {
      reg = Wire.read();
      *min = (reg & 0xF) + (reg >> 4) * 10;
    }
    
    reg = Wire.read();
    if (hour) {
      reg = Wire.read();
      *hour = reg & 0xF;
      if (reg & 0x10)
        *hour += 10;
      
      // AM/PM and 24h handling
      if ((reg & 0x40) && (reg & 0x20)) {
        *hour += 12;
      } else if (reg >> 4) {
        *hour += 20;
      }
    }
    
    reg = Wire.read();
    if (weekday) {
      *weekday = reg;
    }
    
    reg = Wire.read();
    if (day) {
      *day = (reg & 0xF) + (reg >> 4) * 10;
    }
    
    reg = Wire.read();
    if (month) {
      *month = (reg & 0xF);
      if (reg & 0x10)
        *month += 10;
    }
    uint8_t century = (reg & 0x80 ? 100 : 0);
    
    reg = Wire.read();
    if (year) {
      *year = (reg & 0xF) + (reg >> 4) * 10 + century;
    }
    
    return true; 
  }
};
#endif//DS3231_HPP_
