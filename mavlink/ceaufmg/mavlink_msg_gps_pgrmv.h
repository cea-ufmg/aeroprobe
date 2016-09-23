// MESSAGE GPS_PGRMV PACKING

#define MAVLINK_MSG_ID_GPS_PGRMV 170

typedef struct MAVLINK_PACKED __mavlink_gps_pgrmv_t
{
 uint64_t time_usec; /*< Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)*/
 float veast; /*< Geographic east velocity in m/s*/
 float vnorth; /*< Geographic north velocity in m/s*/
 float vup; /*< Up velocity in m/s*/
} mavlink_gps_pgrmv_t;

#define MAVLINK_MSG_ID_GPS_PGRMV_LEN 20
#define MAVLINK_MSG_ID_GPS_PGRMV_MIN_LEN 20
#define MAVLINK_MSG_ID_170_LEN 20
#define MAVLINK_MSG_ID_170_MIN_LEN 20

#define MAVLINK_MSG_ID_GPS_PGRMV_CRC 20
#define MAVLINK_MSG_ID_170_CRC 20



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_PGRMV { \
	170, \
	"GPS_PGRMV", \
	4, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_pgrmv_t, time_usec) }, \
         { "veast", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gps_pgrmv_t, veast) }, \
         { "vnorth", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gps_pgrmv_t, vnorth) }, \
         { "vup", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gps_pgrmv_t, vup) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_PGRMV { \
	"GPS_PGRMV", \
	4, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_pgrmv_t, time_usec) }, \
         { "veast", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gps_pgrmv_t, veast) }, \
         { "vnorth", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gps_pgrmv_t, vnorth) }, \
         { "vup", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gps_pgrmv_t, vup) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_pgrmv message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param veast Geographic east velocity in m/s
 * @param vnorth Geographic north velocity in m/s
 * @param vup Up velocity in m/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_pgrmv_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, float veast, float vnorth, float vup)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_PGRMV_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, veast);
	_mav_put_float(buf, 12, vnorth);
	_mav_put_float(buf, 16, vup);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_PGRMV_LEN);
#else
	mavlink_gps_pgrmv_t packet;
	packet.time_usec = time_usec;
	packet.veast = veast;
	packet.vnorth = vnorth;
	packet.vup = vup;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_PGRMV_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_PGRMV;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_PGRMV_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRMV_LEN, MAVLINK_MSG_ID_GPS_PGRMV_CRC);
}

/**
 * @brief Pack a gps_pgrmv message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param veast Geographic east velocity in m/s
 * @param vnorth Geographic north velocity in m/s
 * @param vup Up velocity in m/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_pgrmv_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,float veast,float vnorth,float vup)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_PGRMV_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, veast);
	_mav_put_float(buf, 12, vnorth);
	_mav_put_float(buf, 16, vup);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_PGRMV_LEN);
#else
	mavlink_gps_pgrmv_t packet;
	packet.time_usec = time_usec;
	packet.veast = veast;
	packet.vnorth = vnorth;
	packet.vup = vup;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_PGRMV_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_PGRMV;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_PGRMV_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRMV_LEN, MAVLINK_MSG_ID_GPS_PGRMV_CRC);
}

/**
 * @brief Encode a gps_pgrmv struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps_pgrmv C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_pgrmv_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_pgrmv_t* gps_pgrmv)
{
	return mavlink_msg_gps_pgrmv_pack(system_id, component_id, msg, gps_pgrmv->time_usec, gps_pgrmv->veast, gps_pgrmv->vnorth, gps_pgrmv->vup);
}

/**
 * @brief Encode a gps_pgrmv struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps_pgrmv C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_pgrmv_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps_pgrmv_t* gps_pgrmv)
{
	return mavlink_msg_gps_pgrmv_pack_chan(system_id, component_id, chan, msg, gps_pgrmv->time_usec, gps_pgrmv->veast, gps_pgrmv->vnorth, gps_pgrmv->vup);
}

/**
 * @brief Send a gps_pgrmv message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param veast Geographic east velocity in m/s
 * @param vnorth Geographic north velocity in m/s
 * @param vup Up velocity in m/s
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps_pgrmv_send(mavlink_channel_t chan, uint64_t time_usec, float veast, float vnorth, float vup)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_PGRMV_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, veast);
	_mav_put_float(buf, 12, vnorth);
	_mav_put_float(buf, 16, vup);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_PGRMV, buf, MAVLINK_MSG_ID_GPS_PGRMV_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRMV_LEN, MAVLINK_MSG_ID_GPS_PGRMV_CRC);
#else
	mavlink_gps_pgrmv_t packet;
	packet.time_usec = time_usec;
	packet.veast = veast;
	packet.vnorth = vnorth;
	packet.vup = vup;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_PGRMV, (const char *)&packet, MAVLINK_MSG_ID_GPS_PGRMV_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRMV_LEN, MAVLINK_MSG_ID_GPS_PGRMV_CRC);
#endif
}

/**
 * @brief Send a gps_pgrmv message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gps_pgrmv_send_struct(mavlink_channel_t chan, const mavlink_gps_pgrmv_t* gps_pgrmv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gps_pgrmv_send(chan, gps_pgrmv->time_usec, gps_pgrmv->veast, gps_pgrmv->vnorth, gps_pgrmv->vup);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_PGRMV, (const char *)gps_pgrmv, MAVLINK_MSG_ID_GPS_PGRMV_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRMV_LEN, MAVLINK_MSG_ID_GPS_PGRMV_CRC);
#endif
}

#if MAVLINK_MSG_ID_GPS_PGRMV_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gps_pgrmv_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, float veast, float vnorth, float vup)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, veast);
	_mav_put_float(buf, 12, vnorth);
	_mav_put_float(buf, 16, vup);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_PGRMV, buf, MAVLINK_MSG_ID_GPS_PGRMV_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRMV_LEN, MAVLINK_MSG_ID_GPS_PGRMV_CRC);
#else
	mavlink_gps_pgrmv_t *packet = (mavlink_gps_pgrmv_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->veast = veast;
	packet->vnorth = vnorth;
	packet->vup = vup;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_PGRMV, (const char *)packet, MAVLINK_MSG_ID_GPS_PGRMV_MIN_LEN, MAVLINK_MSG_ID_GPS_PGRMV_LEN, MAVLINK_MSG_ID_GPS_PGRMV_CRC);
#endif
}
#endif

#endif

// MESSAGE GPS_PGRMV UNPACKING


/**
 * @brief Get field time_usec from gps_pgrmv message
 *
 * @return Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 */
static inline uint64_t mavlink_msg_gps_pgrmv_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field veast from gps_pgrmv message
 *
 * @return Geographic east velocity in m/s
 */
static inline float mavlink_msg_gps_pgrmv_get_veast(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field vnorth from gps_pgrmv message
 *
 * @return Geographic north velocity in m/s
 */
static inline float mavlink_msg_gps_pgrmv_get_vnorth(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field vup from gps_pgrmv message
 *
 * @return Up velocity in m/s
 */
static inline float mavlink_msg_gps_pgrmv_get_vup(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Decode a gps_pgrmv message into a struct
 *
 * @param msg The message to decode
 * @param gps_pgrmv C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_pgrmv_decode(const mavlink_message_t* msg, mavlink_gps_pgrmv_t* gps_pgrmv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	gps_pgrmv->time_usec = mavlink_msg_gps_pgrmv_get_time_usec(msg);
	gps_pgrmv->veast = mavlink_msg_gps_pgrmv_get_veast(msg);
	gps_pgrmv->vnorth = mavlink_msg_gps_pgrmv_get_vnorth(msg);
	gps_pgrmv->vup = mavlink_msg_gps_pgrmv_get_vup(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GPS_PGRMV_LEN? msg->len : MAVLINK_MSG_ID_GPS_PGRMV_LEN;
        memset(gps_pgrmv, 0, MAVLINK_MSG_ID_GPS_PGRMV_LEN);
	memcpy(gps_pgrmv, _MAV_PAYLOAD(msg), len);
#endif
}
