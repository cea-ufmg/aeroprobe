#include "ds3231.hpp"
#include <avr/pgmspace.h>

// Based on code by JeeLabs http://news.jeelabs.org/code/ that was released
// in the public domain.


static const uint8_t days_in_month [] PROGMEM = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

// number of days since 2000/01/01, valid for 2001..2099
static uint16_t date_to_days(uint16_t y, uint8_t m, uint8_t d) {
    uint16_t days = d;
    for (uint8_t i = 1; i < m; ++i)
        days += pgm_read_byte(days_in_month + i - 1);
    if (m > 2 && y % 4 == 0)
        ++days;
    return days + 365 * y + (y + 3) / 4 - 1;
}


static uint32_t DS3231::unix_time() {
  constexpr uint32_t min_in_sec = 60;
  constexpr uint32_t hour_in_sec = 60 * min_in_sec;
  constexpr uint32_t day_in_sec = 24 * hour_in_sec;
  constexpr uint32_t secs_from_1970_to_2000 = 946684800;
  
  uint8_t sec, min, hour, day, month, year;
  DS3231::read_all(&sec, &min, &hour, nullptr, &day, &month, &year);
  
  return sec + min*min_in_sec + hour*hour_in_sec
      + date_to_days(year - 100, month, day)*day_in_sec
      + secs_from_1970_to_2000;
}
