#ifndef MAVLINK_BRIDGE_H
#define MAVLINK_BRIDGE_H

#define MAVLINK_USE_CONVENIENCE_FUNCTIONS

#include "mavlink/mavlink_types.h"

mavlink_system_t mavlink_system {.sysid=10, .compid=10};

static inline void comm_send_ch(mavlink_channel_t chan, uint8_t ch) {
  if (chan == MAVLINK_COMM_0)
    Serial.write(ch);
}


#endif//MAVLINK_BRIDGE_H
