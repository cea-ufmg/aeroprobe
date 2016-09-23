// MESSAGE DATA_INT PACKING

#define MAVLINK_MSG_ID_DATA_INT 200

typedef struct MAVLINK_PACKED __mavlink_data_int_t
{
 uint64_t time_usec; /*< Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)*/
 int64_t value; /*< measurement value*/
 uint16_t id; /*< data source identifier*/
} mavlink_data_int_t;

#define MAVLINK_MSG_ID_DATA_INT_LEN 18
#define MAVLINK_MSG_ID_DATA_INT_MIN_LEN 18
#define MAVLINK_MSG_ID_200_LEN 18
#define MAVLINK_MSG_ID_200_MIN_LEN 18

#define MAVLINK_MSG_ID_DATA_INT_CRC 115
#define MAVLINK_MSG_ID_200_CRC 115



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DATA_INT { \
	200, \
	"DATA_INT", \
	3, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_data_int_t, time_usec) }, \
         { "value", NULL, MAVLINK_TYPE_INT64_T, 0, 8, offsetof(mavlink_data_int_t, value) }, \
         { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_data_int_t, id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DATA_INT { \
	"DATA_INT", \
	3, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_data_int_t, time_usec) }, \
         { "value", NULL, MAVLINK_TYPE_INT64_T, 0, 8, offsetof(mavlink_data_int_t, value) }, \
         { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_data_int_t, id) }, \
         } \
}
#endif

/**
 * @brief Pack a data_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param id data source identifier
 * @param value measurement value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, uint16_t id, int64_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_INT_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int64_t(buf, 8, value);
	_mav_put_uint16_t(buf, 16, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA_INT_LEN);
#else
	mavlink_data_int_t packet;
	packet.time_usec = time_usec;
	packet.value = value;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA_INT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DATA_INT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DATA_INT_MIN_LEN, MAVLINK_MSG_ID_DATA_INT_LEN, MAVLINK_MSG_ID_DATA_INT_CRC);
}

/**
 * @brief Pack a data_int message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param id data source identifier
 * @param value measurement value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data_int_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,uint16_t id,int64_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_INT_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int64_t(buf, 8, value);
	_mav_put_uint16_t(buf, 16, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA_INT_LEN);
#else
	mavlink_data_int_t packet;
	packet.time_usec = time_usec;
	packet.value = value;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA_INT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DATA_INT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DATA_INT_MIN_LEN, MAVLINK_MSG_ID_DATA_INT_LEN, MAVLINK_MSG_ID_DATA_INT_CRC);
}

/**
 * @brief Encode a data_int struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param data_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data_int_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_data_int_t* data_int)
{
	return mavlink_msg_data_int_pack(system_id, component_id, msg, data_int->time_usec, data_int->id, data_int->value);
}

/**
 * @brief Encode a data_int struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param data_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data_int_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_data_int_t* data_int)
{
	return mavlink_msg_data_int_pack_chan(system_id, component_id, chan, msg, data_int->time_usec, data_int->id, data_int->value);
}

/**
 * @brief Send a data_int message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param id data source identifier
 * @param value measurement value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_data_int_send(mavlink_channel_t chan, uint64_t time_usec, uint16_t id, int64_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_INT_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int64_t(buf, 8, value);
	_mav_put_uint16_t(buf, 16, id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_INT, buf, MAVLINK_MSG_ID_DATA_INT_MIN_LEN, MAVLINK_MSG_ID_DATA_INT_LEN, MAVLINK_MSG_ID_DATA_INT_CRC);
#else
	mavlink_data_int_t packet;
	packet.time_usec = time_usec;
	packet.value = value;
	packet.id = id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_INT, (const char *)&packet, MAVLINK_MSG_ID_DATA_INT_MIN_LEN, MAVLINK_MSG_ID_DATA_INT_LEN, MAVLINK_MSG_ID_DATA_INT_CRC);
#endif
}

/**
 * @brief Send a data_int message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_data_int_send_struct(mavlink_channel_t chan, const mavlink_data_int_t* data_int)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_data_int_send(chan, data_int->time_usec, data_int->id, data_int->value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_INT, (const char *)data_int, MAVLINK_MSG_ID_DATA_INT_MIN_LEN, MAVLINK_MSG_ID_DATA_INT_LEN, MAVLINK_MSG_ID_DATA_INT_CRC);
#endif
}

#if MAVLINK_MSG_ID_DATA_INT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_data_int_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint16_t id, int64_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int64_t(buf, 8, value);
	_mav_put_uint16_t(buf, 16, id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_INT, buf, MAVLINK_MSG_ID_DATA_INT_MIN_LEN, MAVLINK_MSG_ID_DATA_INT_LEN, MAVLINK_MSG_ID_DATA_INT_CRC);
#else
	mavlink_data_int_t *packet = (mavlink_data_int_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->value = value;
	packet->id = id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_INT, (const char *)packet, MAVLINK_MSG_ID_DATA_INT_MIN_LEN, MAVLINK_MSG_ID_DATA_INT_LEN, MAVLINK_MSG_ID_DATA_INT_CRC);
#endif
}
#endif

#endif

// MESSAGE DATA_INT UNPACKING


/**
 * @brief Get field time_usec from data_int message
 *
 * @return Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 */
static inline uint64_t mavlink_msg_data_int_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field id from data_int message
 *
 * @return data source identifier
 */
static inline uint16_t mavlink_msg_data_int_get_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field value from data_int message
 *
 * @return measurement value
 */
static inline int64_t mavlink_msg_data_int_get_value(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int64_t(msg,  8);
}

/**
 * @brief Decode a data_int message into a struct
 *
 * @param msg The message to decode
 * @param data_int C-struct to decode the message contents into
 */
static inline void mavlink_msg_data_int_decode(const mavlink_message_t* msg, mavlink_data_int_t* data_int)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	data_int->time_usec = mavlink_msg_data_int_get_time_usec(msg);
	data_int->value = mavlink_msg_data_int_get_value(msg);
	data_int->id = mavlink_msg_data_int_get_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DATA_INT_LEN? msg->len : MAVLINK_MSG_ID_DATA_INT_LEN;
        memset(data_int, 0, MAVLINK_MSG_ID_DATA_INT_LEN);
	memcpy(data_int, _MAV_PAYLOAD(msg), len);
#endif
}
