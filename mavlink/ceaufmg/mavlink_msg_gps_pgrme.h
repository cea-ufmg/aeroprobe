// MESSAGE GPS_PGRME PACKING

#define MAVLINK_MSG_ID_GPS_PGRME 171

typedef struct MAVLINK_PACKED __mavlink_gps_pgrme_t
{
 uint64_t time_usec; /*< Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)*/
 float hpe; /*< Estimated horizontal position error (m)*/
 float vpe; /*< Estimated vertical position error (m)*/
 float epe; /*< Estimated position error (m)*/
} mavlink_gps_pgrme_t;

#define MAVLINK_MSG_ID_GPS_PGRME_LEN 20
#define MAVLINK_MSG_ID_GPS_PGRME_MIN_LEN 20
#define MAVLINK_MSG_ID_171_LEN 20
#define MAVLINK_MSG_ID_171_MIN_LEN 20

#define MAVLINK_MSG_ID_GPS_PGRME_CRC 49
#define MAVLINK_MSG_ID_171_CRC 49



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_PGRME { \
	171, \
	"GPS_PGRME", \
	4, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_pgrme_t, time_usec) }, \
         { "hpe", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gps_pgrme_t, hpe) }, \
         { "vpe", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gps_pgrme_t, vpe) }, \
         { "epe", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gps_pgrme_t, epe) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_PGRME { \
	"GPS_PGRME", \
	4, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_pgrme_t, time_usec) }, \
         { "hpe", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gps_pgrme_t, hpe) }, \
         { "vpe", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gps_pgrme_t, vpe) }, \
         { "epe", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gps_pgrme_t, epe) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_pgrme message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param hpe Estimated horizontal position error (m)
 * @param vpe Estimated vertical position error (m)
 * @param epe Estimated position error (m)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_pgrme_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, float hpe, float vpe, float epe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_PGRME_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, hpe);
	_mav_put_float(buf, 12, vpe);
	_mav_put_float(buf, 16, epe);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_PGRME_LEN);
#else
	mavlink_gps_pgrme_t packet;
	packet.time_usec = time_usec;
	packet.hpe = hpe;
	packet.vpe = vpe;
	packet.epe = epe;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_PGRME_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_PGRME;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_PGRME_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRME_LEN, MAVLINK_MSG_ID_GPS_PGRME_CRC);
}

/**
 * @brief Pack a gps_pgrme message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param hpe Estimated horizontal position error (m)
 * @param vpe Estimated vertical position error (m)
 * @param epe Estimated position error (m)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_pgrme_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,float hpe,float vpe,float epe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_PGRME_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, hpe);
	_mav_put_float(buf, 12, vpe);
	_mav_put_float(buf, 16, epe);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_PGRME_LEN);
#else
	mavlink_gps_pgrme_t packet;
	packet.time_usec = time_usec;
	packet.hpe = hpe;
	packet.vpe = vpe;
	packet.epe = epe;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_PGRME_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_PGRME;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_PGRME_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRME_LEN, MAVLINK_MSG_ID_GPS_PGRME_CRC);
}

/**
 * @brief Encode a gps_pgrme struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps_pgrme C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_pgrme_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_pgrme_t* gps_pgrme)
{
	return mavlink_msg_gps_pgrme_pack(system_id, component_id, msg, gps_pgrme->time_usec, gps_pgrme->hpe, gps_pgrme->vpe, gps_pgrme->epe);
}

/**
 * @brief Encode a gps_pgrme struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps_pgrme C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_pgrme_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps_pgrme_t* gps_pgrme)
{
	return mavlink_msg_gps_pgrme_pack_chan(system_id, component_id, chan, msg, gps_pgrme->time_usec, gps_pgrme->hpe, gps_pgrme->vpe, gps_pgrme->epe);
}

/**
 * @brief Send a gps_pgrme message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param hpe Estimated horizontal position error (m)
 * @param vpe Estimated vertical position error (m)
 * @param epe Estimated position error (m)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps_pgrme_send(mavlink_channel_t chan, uint64_t time_usec, float hpe, float vpe, float epe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_PGRME_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, hpe);
	_mav_put_float(buf, 12, vpe);
	_mav_put_float(buf, 16, epe);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_PGRME, buf, MAVLINK_MSG_ID_GPS_PGRME_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRME_LEN, MAVLINK_MSG_ID_GPS_PGRME_CRC);
#else
	mavlink_gps_pgrme_t packet;
	packet.time_usec = time_usec;
	packet.hpe = hpe;
	packet.vpe = vpe;
	packet.epe = epe;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_PGRME, (const char *)&packet, MAVLINK_MSG_ID_GPS_PGRME_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRME_LEN, MAVLINK_MSG_ID_GPS_PGRME_CRC);
#endif
}

/**
 * @brief Send a gps_pgrme message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gps_pgrme_send_struct(mavlink_channel_t chan, const mavlink_gps_pgrme_t* gps_pgrme)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gps_pgrme_send(chan, gps_pgrme->time_usec, gps_pgrme->hpe, gps_pgrme->vpe, gps_pgrme->epe);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_PGRME, (const char *)gps_pgrme, MAVLINK_MSG_ID_GPS_PGRME_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRME_LEN, MAVLINK_MSG_ID_GPS_PGRME_CRC);
#endif
}

#if MAVLINK_MSG_ID_GPS_PGRME_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gps_pgrme_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, float hpe, float vpe, float epe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, hpe);
	_mav_put_float(buf, 12, vpe);
	_mav_put_float(buf, 16, epe);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_PGRME, buf, MAVLINK_MSG_ID_GPS_PGRME_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRME_LEN, MAVLINK_MSG_ID_GPS_PGRME_CRC);
#else
	mavlink_gps_pgrme_t *packet = (mavlink_gps_pgrme_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->hpe = hpe;
	packet->vpe = vpe;
	packet->epe = epe;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_PGRME, (const char *)packet, MAVLINK_MSG_ID_GPS_PGRME_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRME_LEN, MAVLINK_MSG_ID_GPS_PGRME_CRC);
#endif
}
#endif

#endif

// MESSAGE GPS_PGRME UNPACKING


/**
 * @brief Get field time_usec from gps_pgrme message
 *
 * @return Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 */
static inline uint64_t mavlink_msg_gps_pgrme_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field hpe from gps_pgrme message
 *
 * @return Estimated horizontal position error (m)
 */
static inline float mavlink_msg_gps_pgrme_get_hpe(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field vpe from gps_pgrme message
 *
 * @return Estimated vertical position error (m)
 */
static inline float mavlink_msg_gps_pgrme_get_vpe(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field epe from gps_pgrme message
 *
 * @return Estimated position error (m)
 */
static inline float mavlink_msg_gps_pgrme_get_epe(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Decode a gps_pgrme message into a struct
 *
 * @param msg The message to decode
 * @param gps_pgrme C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_pgrme_decode(const mavlink_message_t* msg, mavlink_gps_pgrme_t* gps_pgrme)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	gps_pgrme->time_usec = mavlink_msg_gps_pgrme_get_time_usec(msg);
	gps_pgrme->hpe = mavlink_msg_gps_pgrme_get_hpe(msg);
	gps_pgrme->vpe = mavlink_msg_gps_pgrme_get_vpe(msg);
	gps_pgrme->epe = mavlink_msg_gps_pgrme_get_epe(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GPS_PGRME_LEN? msg->len : MAVLINK_MSG_ID_GPS_PGRME_LEN;
        memset(gps_pgrme, 0, MAVLINK_MSG_ID_GPS_PGRME_LEN);
	memcpy(gps_pgrme, _MAV_PAYLOAD(msg), len);
#endif
}
