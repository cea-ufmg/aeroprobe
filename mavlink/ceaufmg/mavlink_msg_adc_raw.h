// MESSAGE ADC_RAW PACKING

#define MAVLINK_MSG_ID_ADC_RAW 160

typedef struct MAVLINK_PACKED __mavlink_adc_raw_t
{
 uint64_t time_usec; /*< Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)*/
 int16_t data[16]; /*< Raw data from the ADC*/
} mavlink_adc_raw_t;

#define MAVLINK_MSG_ID_ADC_RAW_LEN 40
#define MAVLINK_MSG_ID_ADC_RAW_MIN_LEN 40
#define MAVLINK_MSG_ID_160_LEN 40
#define MAVLINK_MSG_ID_160_MIN_LEN 40

#define MAVLINK_MSG_ID_ADC_RAW_CRC 126
#define MAVLINK_MSG_ID_160_CRC 126

#define MAVLINK_MSG_ADC_RAW_FIELD_DATA_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ADC_RAW { \
	160, \
	"ADC_RAW", \
	2, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_adc_raw_t, time_usec) }, \
         { "data", NULL, MAVLINK_TYPE_INT16_T, 16, 8, offsetof(mavlink_adc_raw_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ADC_RAW { \
	"ADC_RAW", \
	2, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_adc_raw_t, time_usec) }, \
         { "data", NULL, MAVLINK_TYPE_INT16_T, 16, 8, offsetof(mavlink_adc_raw_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a adc_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param data Raw data from the ADC
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_adc_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, const int16_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ADC_RAW_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int16_t_array(buf, 8, data, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ADC_RAW_LEN);
#else
	mavlink_adc_raw_t packet;
	packet.time_usec = time_usec;
	mav_array_memcpy(packet.data, data, sizeof(int16_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ADC_RAW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ADC_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ADC_RAW_MIN_LEN, MAVLINK_MSG_ID_ADC_RAW_LEN, MAVLINK_MSG_ID_ADC_RAW_CRC);
}

/**
 * @brief Pack a adc_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param data Raw data from the ADC
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_adc_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,const int16_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ADC_RAW_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int16_t_array(buf, 8, data, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ADC_RAW_LEN);
#else
	mavlink_adc_raw_t packet;
	packet.time_usec = time_usec;
	mav_array_memcpy(packet.data, data, sizeof(int16_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ADC_RAW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_ADC_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ADC_RAW_MIN_LEN, MAVLINK_MSG_ID_ADC_RAW_LEN, MAVLINK_MSG_ID_ADC_RAW_CRC);
}

/**
 * @brief Encode a adc_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param adc_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_adc_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_adc_raw_t* adc_raw)
{
	return mavlink_msg_adc_raw_pack(system_id, component_id, msg, adc_raw->time_usec, adc_raw->data);
}

/**
 * @brief Encode a adc_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param adc_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_adc_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_adc_raw_t* adc_raw)
{
	return mavlink_msg_adc_raw_pack_chan(system_id, component_id, chan, msg, adc_raw->time_usec, adc_raw->data);
}

/**
 * @brief Send a adc_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param data Raw data from the ADC
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_adc_raw_send(mavlink_channel_t chan, uint64_t time_usec, const int16_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ADC_RAW_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int16_t_array(buf, 8, data, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_RAW, buf, MAVLINK_MSG_ID_ADC_RAW_MIN_LEN, MAVLINK_MSG_ID_ADC_RAW_LEN, MAVLINK_MSG_ID_ADC_RAW_CRC);
#else
	mavlink_adc_raw_t packet;
	packet.time_usec = time_usec;
	mav_array_memcpy(packet.data, data, sizeof(int16_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_RAW, (const char *)&packet, MAVLINK_MSG_ID_ADC_RAW_MIN_LEN, MAVLINK_MSG_ID_ADC_RAW_LEN, MAVLINK_MSG_ID_ADC_RAW_CRC);
#endif
}

/**
 * @brief Send a adc_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_adc_raw_send_struct(mavlink_channel_t chan, const mavlink_adc_raw_t* adc_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_adc_raw_send(chan, adc_raw->time_usec, adc_raw->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_RAW, (const char *)adc_raw, MAVLINK_MSG_ID_ADC_RAW_MIN_LEN, MAVLINK_MSG_ID_ADC_RAW_LEN, MAVLINK_MSG_ID_ADC_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_ADC_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_adc_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const int16_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int16_t_array(buf, 8, data, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_RAW, buf, MAVLINK_MSG_ID_ADC_RAW_MIN_LEN, MAVLINK_MSG_ID_ADC_RAW_LEN, MAVLINK_MSG_ID_ADC_RAW_CRC);
#else
	mavlink_adc_raw_t *packet = (mavlink_adc_raw_t *)msgbuf;
	packet->time_usec = time_usec;
	mav_array_memcpy(packet->data, data, sizeof(int16_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_RAW, (const char *)packet, MAVLINK_MSG_ID_ADC_RAW_MIN_LEN, MAVLINK_MSG_ID_ADC_RAW_LEN, MAVLINK_MSG_ID_ADC_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE ADC_RAW UNPACKING


/**
 * @brief Get field time_usec from adc_raw message
 *
 * @return Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 */
static inline uint64_t mavlink_msg_adc_raw_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field data from adc_raw message
 *
 * @return Raw data from the ADC
 */
static inline uint16_t mavlink_msg_adc_raw_get_data(const mavlink_message_t* msg, int16_t *data)
{
	return _MAV_RETURN_int16_t_array(msg, data, 16,  8);
}

/**
 * @brief Decode a adc_raw message into a struct
 *
 * @param msg The message to decode
 * @param adc_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_adc_raw_decode(const mavlink_message_t* msg, mavlink_adc_raw_t* adc_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	adc_raw->time_usec = mavlink_msg_adc_raw_get_time_usec(msg);
	mavlink_msg_adc_raw_get_data(msg, adc_raw->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ADC_RAW_LEN? msg->len : MAVLINK_MSG_ID_ADC_RAW_LEN;
        memset(adc_raw, 0, MAVLINK_MSG_ID_ADC_RAW_LEN);
	memcpy(adc_raw, _MAV_PAYLOAD(msg), len);
#endif
}
