// MESSAGE DATA_DOUBLE PACKING

#define MAVLINK_MSG_ID_DATA_DOUBLE 202

typedef struct MAVLINK_PACKED __mavlink_data_double_t
{
 uint64_t time_usec; /*< Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)*/
 double value; /*< measurement value*/
 uint16_t id; /*< measurement source identifier*/
} mavlink_data_double_t;

#define MAVLINK_MSG_ID_DATA_DOUBLE_LEN 18
#define MAVLINK_MSG_ID_DATA_DOUBLE_MIN_LEN 18
#define MAVLINK_MSG_ID_202_LEN 18
#define MAVLINK_MSG_ID_202_MIN_LEN 18

#define MAVLINK_MSG_ID_DATA_DOUBLE_CRC 247
#define MAVLINK_MSG_ID_202_CRC 247



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DATA_DOUBLE { \
	202, \
	"DATA_DOUBLE", \
	3, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_data_double_t, time_usec) }, \
         { "value", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_data_double_t, value) }, \
         { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_data_double_t, id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DATA_DOUBLE { \
	"DATA_DOUBLE", \
	3, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_data_double_t, time_usec) }, \
         { "value", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_data_double_t, value) }, \
         { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_data_double_t, id) }, \
         } \
}
#endif

/**
 * @brief Pack a data_double message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param id measurement source identifier
 * @param value measurement value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data_double_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, uint16_t id, double value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_DOUBLE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_double(buf, 8, value);
	_mav_put_uint16_t(buf, 16, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA_DOUBLE_LEN);
#else
	mavlink_data_double_t packet;
	packet.time_usec = time_usec;
	packet.value = value;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA_DOUBLE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DATA_DOUBLE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DATA_DOUBLE_MIN_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_CRC);
}

/**
 * @brief Pack a data_double message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param id measurement source identifier
 * @param value measurement value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data_double_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,uint16_t id,double value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_DOUBLE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_double(buf, 8, value);
	_mav_put_uint16_t(buf, 16, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA_DOUBLE_LEN);
#else
	mavlink_data_double_t packet;
	packet.time_usec = time_usec;
	packet.value = value;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA_DOUBLE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DATA_DOUBLE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DATA_DOUBLE_MIN_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_CRC);
}

/**
 * @brief Encode a data_double struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param data_double C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data_double_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_data_double_t* data_double)
{
	return mavlink_msg_data_double_pack(system_id, component_id, msg, data_double->time_usec, data_double->id, data_double->value);
}

/**
 * @brief Encode a data_double struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param data_double C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data_double_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_data_double_t* data_double)
{
	return mavlink_msg_data_double_pack_chan(system_id, component_id, chan, msg, data_double->time_usec, data_double->id, data_double->value);
}

/**
 * @brief Send a data_double message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param id measurement source identifier
 * @param value measurement value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_data_double_send(mavlink_channel_t chan, uint64_t time_usec, uint16_t id, double value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_DOUBLE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_double(buf, 8, value);
	_mav_put_uint16_t(buf, 16, id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_DOUBLE, buf, MAVLINK_MSG_ID_DATA_DOUBLE_MIN_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_CRC);
#else
	mavlink_data_double_t packet;
	packet.time_usec = time_usec;
	packet.value = value;
	packet.id = id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_DOUBLE, (const char *)&packet, MAVLINK_MSG_ID_DATA_DOUBLE_MIN_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_CRC);
#endif
}

/**
 * @brief Send a data_double message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_data_double_send_struct(mavlink_channel_t chan, const mavlink_data_double_t* data_double)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_data_double_send(chan, data_double->time_usec, data_double->id, data_double->value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_DOUBLE, (const char *)data_double, MAVLINK_MSG_ID_DATA_DOUBLE_MIN_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_CRC);
#endif
}

#if MAVLINK_MSG_ID_DATA_DOUBLE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_data_double_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint16_t id, double value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_double(buf, 8, value);
	_mav_put_uint16_t(buf, 16, id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_DOUBLE, buf, MAVLINK_MSG_ID_DATA_DOUBLE_MIN_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_CRC);
#else
	mavlink_data_double_t *packet = (mavlink_data_double_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->value = value;
	packet->id = id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_DOUBLE, (const char *)packet, MAVLINK_MSG_ID_DATA_DOUBLE_MIN_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_LEN, MAVLINK_MSG_ID_DATA_DOUBLE_CRC);
#endif
}
#endif

#endif

// MESSAGE DATA_DOUBLE UNPACKING


/**
 * @brief Get field time_usec from data_double message
 *
 * @return Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 */
static inline uint64_t mavlink_msg_data_double_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field id from data_double message
 *
 * @return measurement source identifier
 */
static inline uint16_t mavlink_msg_data_double_get_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field value from data_double message
 *
 * @return measurement value
 */
static inline double mavlink_msg_data_double_get_value(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Decode a data_double message into a struct
 *
 * @param msg The message to decode
 * @param data_double C-struct to decode the message contents into
 */
static inline void mavlink_msg_data_double_decode(const mavlink_message_t* msg, mavlink_data_double_t* data_double)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	data_double->time_usec = mavlink_msg_data_double_get_time_usec(msg);
	data_double->value = mavlink_msg_data_double_get_value(msg);
	data_double->id = mavlink_msg_data_double_get_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DATA_DOUBLE_LEN? msg->len : MAVLINK_MSG_ID_DATA_DOUBLE_LEN;
        memset(data_double, 0, MAVLINK_MSG_ID_DATA_DOUBLE_LEN);
	memcpy(data_double, _MAV_PAYLOAD(msg), len);
#endif
}
