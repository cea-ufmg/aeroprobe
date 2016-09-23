// MESSAGE AHRS400_ANGLE_RAW PACKING

#define MAVLINK_MSG_ID_AHRS400_ANGLE_RAW 150

typedef struct MAVLINK_PACKED __mavlink_ahrs400_angle_raw_t
{
 uint64_t time_usec; /*< Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)*/
 int16_t xacc; /*< X acceleration (G range*1.5/2^15)*/
 int16_t yacc; /*< Y acceleration (G range*1.5/2^15)*/
 int16_t zacc; /*< Z acceleration (G range*1.5/2^15)*/
 int16_t xgyro; /*< Angular speed around X axis (angular rate range*1.5/2^15)*/
 int16_t ygyro; /*< Angular speed around Y axis (angular rate range*1.5/2^15)*/
 int16_t zgyro; /*< Angular speed around Z axis (angular rate range*1.5/2^15)*/
 int16_t xmag; /*< X magnetic field (magnetic field range*1.5/2^15)*/
 int16_t ymag; /*< Y magnetic field (magnetic field range*1.5/2^15)*/
 int16_t zmag; /*< Z magnetic field (magnetic field range*1.5/2^15)*/
 int16_t roll; /*< Roll angle (180degrees/2^15)*/
 int16_t pitch; /*< Pitch angle (180degrees/2^15)*/
 int16_t yaw; /*< Yaw angle (180degrees/2^15)*/
 uint16_t temperature; /*< temperature*/
 uint16_t sensor_time; /*< internal time of the DMU*/
} mavlink_ahrs400_angle_raw_t;

#define MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN 36
#define MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_MIN_LEN 36
#define MAVLINK_MSG_ID_150_LEN 36
#define MAVLINK_MSG_ID_150_MIN_LEN 36

#define MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_CRC 185
#define MAVLINK_MSG_ID_150_CRC 185



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AHRS400_ANGLE_RAW { \
	150, \
	"AHRS400_ANGLE_RAW", \
	15, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ahrs400_angle_raw_t, time_usec) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_ahrs400_angle_raw_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_ahrs400_angle_raw_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_ahrs400_angle_raw_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_ahrs400_angle_raw_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_ahrs400_angle_raw_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_ahrs400_angle_raw_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_ahrs400_angle_raw_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_ahrs400_angle_raw_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_ahrs400_angle_raw_t, zmag) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_ahrs400_angle_raw_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_ahrs400_angle_raw_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_ahrs400_angle_raw_t, yaw) }, \
         { "temperature", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_ahrs400_angle_raw_t, temperature) }, \
         { "sensor_time", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_ahrs400_angle_raw_t, sensor_time) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AHRS400_ANGLE_RAW { \
	"AHRS400_ANGLE_RAW", \
	15, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ahrs400_angle_raw_t, time_usec) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_ahrs400_angle_raw_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_ahrs400_angle_raw_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_ahrs400_angle_raw_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_ahrs400_angle_raw_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_ahrs400_angle_raw_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_ahrs400_angle_raw_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_ahrs400_angle_raw_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_ahrs400_angle_raw_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_ahrs400_angle_raw_t, zmag) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_ahrs400_angle_raw_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_ahrs400_angle_raw_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_ahrs400_angle_raw_t, yaw) }, \
         { "temperature", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_ahrs400_angle_raw_t, temperature) }, \
         { "sensor_time", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_ahrs400_angle_raw_t, sensor_time) }, \
         } \
}
#endif

/**
 * @brief Pack a ahrs400_angle_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param xacc X acceleration (G range*1.5/2^15)
 * @param yacc Y acceleration (G range*1.5/2^15)
 * @param zacc Z acceleration (G range*1.5/2^15)
 * @param xgyro Angular speed around X axis (angular rate range*1.5/2^15)
 * @param ygyro Angular speed around Y axis (angular rate range*1.5/2^15)
 * @param zgyro Angular speed around Z axis (angular rate range*1.5/2^15)
 * @param xmag X magnetic field (magnetic field range*1.5/2^15)
 * @param ymag Y magnetic field (magnetic field range*1.5/2^15)
 * @param zmag Z magnetic field (magnetic field range*1.5/2^15)
 * @param roll Roll angle (180degrees/2^15)
 * @param pitch Pitch angle (180degrees/2^15)
 * @param yaw Yaw angle (180degrees/2^15)
 * @param temperature temperature
 * @param sensor_time internal time of the DMU
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ahrs400_angle_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t xmag, int16_t ymag, int16_t zmag, int16_t roll, int16_t pitch, int16_t yaw, uint16_t temperature, uint16_t sensor_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int16_t(buf, 8, xacc);
	_mav_put_int16_t(buf, 10, yacc);
	_mav_put_int16_t(buf, 12, zacc);
	_mav_put_int16_t(buf, 14, xgyro);
	_mav_put_int16_t(buf, 16, ygyro);
	_mav_put_int16_t(buf, 18, zgyro);
	_mav_put_int16_t(buf, 20, xmag);
	_mav_put_int16_t(buf, 22, ymag);
	_mav_put_int16_t(buf, 24, zmag);
	_mav_put_int16_t(buf, 26, roll);
	_mav_put_int16_t(buf, 28, pitch);
	_mav_put_int16_t(buf, 30, yaw);
	_mav_put_uint16_t(buf, 32, temperature);
	_mav_put_uint16_t(buf, 34, sensor_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN);
#else
	mavlink_ahrs400_angle_raw_t packet;
	packet.time_usec = time_usec;
	packet.xacc = xacc;
	packet.yacc = yacc;
	packet.zacc = zacc;
	packet.xgyro = xgyro;
	packet.ygyro = ygyro;
	packet.zgyro = zgyro;
	packet.xmag = xmag;
	packet.ymag = ymag;
	packet.zmag = zmag;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.temperature = temperature;
	packet.sensor_time = sensor_time;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AHRS400_ANGLE_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_CRC);
}

/**
 * @brief Pack a ahrs400_angle_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param xacc X acceleration (G range*1.5/2^15)
 * @param yacc Y acceleration (G range*1.5/2^15)
 * @param zacc Z acceleration (G range*1.5/2^15)
 * @param xgyro Angular speed around X axis (angular rate range*1.5/2^15)
 * @param ygyro Angular speed around Y axis (angular rate range*1.5/2^15)
 * @param zgyro Angular speed around Z axis (angular rate range*1.5/2^15)
 * @param xmag X magnetic field (magnetic field range*1.5/2^15)
 * @param ymag Y magnetic field (magnetic field range*1.5/2^15)
 * @param zmag Z magnetic field (magnetic field range*1.5/2^15)
 * @param roll Roll angle (180degrees/2^15)
 * @param pitch Pitch angle (180degrees/2^15)
 * @param yaw Yaw angle (180degrees/2^15)
 * @param temperature temperature
 * @param sensor_time internal time of the DMU
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ahrs400_angle_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,int16_t xacc,int16_t yacc,int16_t zacc,int16_t xgyro,int16_t ygyro,int16_t zgyro,int16_t xmag,int16_t ymag,int16_t zmag,int16_t roll,int16_t pitch,int16_t yaw,uint16_t temperature,uint16_t sensor_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int16_t(buf, 8, xacc);
	_mav_put_int16_t(buf, 10, yacc);
	_mav_put_int16_t(buf, 12, zacc);
	_mav_put_int16_t(buf, 14, xgyro);
	_mav_put_int16_t(buf, 16, ygyro);
	_mav_put_int16_t(buf, 18, zgyro);
	_mav_put_int16_t(buf, 20, xmag);
	_mav_put_int16_t(buf, 22, ymag);
	_mav_put_int16_t(buf, 24, zmag);
	_mav_put_int16_t(buf, 26, roll);
	_mav_put_int16_t(buf, 28, pitch);
	_mav_put_int16_t(buf, 30, yaw);
	_mav_put_uint16_t(buf, 32, temperature);
	_mav_put_uint16_t(buf, 34, sensor_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN);
#else
	mavlink_ahrs400_angle_raw_t packet;
	packet.time_usec = time_usec;
	packet.xacc = xacc;
	packet.yacc = yacc;
	packet.zacc = zacc;
	packet.xgyro = xgyro;
	packet.ygyro = ygyro;
	packet.zgyro = zgyro;
	packet.xmag = xmag;
	packet.ymag = ymag;
	packet.zmag = zmag;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.temperature = temperature;
	packet.sensor_time = sensor_time;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AHRS400_ANGLE_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_CRC);
}

/**
 * @brief Encode a ahrs400_angle_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ahrs400_angle_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ahrs400_angle_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ahrs400_angle_raw_t* ahrs400_angle_raw)
{
	return mavlink_msg_ahrs400_angle_raw_pack(system_id, component_id, msg, ahrs400_angle_raw->time_usec, ahrs400_angle_raw->xacc, ahrs400_angle_raw->yacc, ahrs400_angle_raw->zacc, ahrs400_angle_raw->xgyro, ahrs400_angle_raw->ygyro, ahrs400_angle_raw->zgyro, ahrs400_angle_raw->xmag, ahrs400_angle_raw->ymag, ahrs400_angle_raw->zmag, ahrs400_angle_raw->roll, ahrs400_angle_raw->pitch, ahrs400_angle_raw->yaw, ahrs400_angle_raw->temperature, ahrs400_angle_raw->sensor_time);
}

/**
 * @brief Encode a ahrs400_angle_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ahrs400_angle_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ahrs400_angle_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ahrs400_angle_raw_t* ahrs400_angle_raw)
{
	return mavlink_msg_ahrs400_angle_raw_pack_chan(system_id, component_id, chan, msg, ahrs400_angle_raw->time_usec, ahrs400_angle_raw->xacc, ahrs400_angle_raw->yacc, ahrs400_angle_raw->zacc, ahrs400_angle_raw->xgyro, ahrs400_angle_raw->ygyro, ahrs400_angle_raw->zgyro, ahrs400_angle_raw->xmag, ahrs400_angle_raw->ymag, ahrs400_angle_raw->zmag, ahrs400_angle_raw->roll, ahrs400_angle_raw->pitch, ahrs400_angle_raw->yaw, ahrs400_angle_raw->temperature, ahrs400_angle_raw->sensor_time);
}

/**
 * @brief Send a ahrs400_angle_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param xacc X acceleration (G range*1.5/2^15)
 * @param yacc Y acceleration (G range*1.5/2^15)
 * @param zacc Z acceleration (G range*1.5/2^15)
 * @param xgyro Angular speed around X axis (angular rate range*1.5/2^15)
 * @param ygyro Angular speed around Y axis (angular rate range*1.5/2^15)
 * @param zgyro Angular speed around Z axis (angular rate range*1.5/2^15)
 * @param xmag X magnetic field (magnetic field range*1.5/2^15)
 * @param ymag Y magnetic field (magnetic field range*1.5/2^15)
 * @param zmag Z magnetic field (magnetic field range*1.5/2^15)
 * @param roll Roll angle (180degrees/2^15)
 * @param pitch Pitch angle (180degrees/2^15)
 * @param yaw Yaw angle (180degrees/2^15)
 * @param temperature temperature
 * @param sensor_time internal time of the DMU
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ahrs400_angle_raw_send(mavlink_channel_t chan, uint64_t time_usec, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t xmag, int16_t ymag, int16_t zmag, int16_t roll, int16_t pitch, int16_t yaw, uint16_t temperature, uint16_t sensor_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int16_t(buf, 8, xacc);
	_mav_put_int16_t(buf, 10, yacc);
	_mav_put_int16_t(buf, 12, zacc);
	_mav_put_int16_t(buf, 14, xgyro);
	_mav_put_int16_t(buf, 16, ygyro);
	_mav_put_int16_t(buf, 18, zgyro);
	_mav_put_int16_t(buf, 20, xmag);
	_mav_put_int16_t(buf, 22, ymag);
	_mav_put_int16_t(buf, 24, zmag);
	_mav_put_int16_t(buf, 26, roll);
	_mav_put_int16_t(buf, 28, pitch);
	_mav_put_int16_t(buf, 30, yaw);
	_mav_put_uint16_t(buf, 32, temperature);
	_mav_put_uint16_t(buf, 34, sensor_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW, buf, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_CRC);
#else
	mavlink_ahrs400_angle_raw_t packet;
	packet.time_usec = time_usec;
	packet.xacc = xacc;
	packet.yacc = yacc;
	packet.zacc = zacc;
	packet.xgyro = xgyro;
	packet.ygyro = ygyro;
	packet.zgyro = zgyro;
	packet.xmag = xmag;
	packet.ymag = ymag;
	packet.zmag = zmag;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.temperature = temperature;
	packet.sensor_time = sensor_time;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW, (const char *)&packet, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_CRC);
#endif
}

/**
 * @brief Send a ahrs400_angle_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ahrs400_angle_raw_send_struct(mavlink_channel_t chan, const mavlink_ahrs400_angle_raw_t* ahrs400_angle_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ahrs400_angle_raw_send(chan, ahrs400_angle_raw->time_usec, ahrs400_angle_raw->xacc, ahrs400_angle_raw->yacc, ahrs400_angle_raw->zacc, ahrs400_angle_raw->xgyro, ahrs400_angle_raw->ygyro, ahrs400_angle_raw->zgyro, ahrs400_angle_raw->xmag, ahrs400_angle_raw->ymag, ahrs400_angle_raw->zmag, ahrs400_angle_raw->roll, ahrs400_angle_raw->pitch, ahrs400_angle_raw->yaw, ahrs400_angle_raw->temperature, ahrs400_angle_raw->sensor_time);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW, (const char *)ahrs400_angle_raw, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ahrs400_angle_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t xmag, int16_t ymag, int16_t zmag, int16_t roll, int16_t pitch, int16_t yaw, uint16_t temperature, uint16_t sensor_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_int16_t(buf, 8, xacc);
	_mav_put_int16_t(buf, 10, yacc);
	_mav_put_int16_t(buf, 12, zacc);
	_mav_put_int16_t(buf, 14, xgyro);
	_mav_put_int16_t(buf, 16, ygyro);
	_mav_put_int16_t(buf, 18, zgyro);
	_mav_put_int16_t(buf, 20, xmag);
	_mav_put_int16_t(buf, 22, ymag);
	_mav_put_int16_t(buf, 24, zmag);
	_mav_put_int16_t(buf, 26, roll);
	_mav_put_int16_t(buf, 28, pitch);
	_mav_put_int16_t(buf, 30, yaw);
	_mav_put_uint16_t(buf, 32, temperature);
	_mav_put_uint16_t(buf, 34, sensor_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW, buf, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_CRC);
#else
	mavlink_ahrs400_angle_raw_t *packet = (mavlink_ahrs400_angle_raw_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->xacc = xacc;
	packet->yacc = yacc;
	packet->zacc = zacc;
	packet->xgyro = xgyro;
	packet->ygyro = ygyro;
	packet->zgyro = zgyro;
	packet->xmag = xmag;
	packet->ymag = ymag;
	packet->zmag = zmag;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->yaw = yaw;
	packet->temperature = temperature;
	packet->sensor_time = sensor_time;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW, (const char *)packet, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE AHRS400_ANGLE_RAW UNPACKING


/**
 * @brief Get field time_usec from ahrs400_angle_raw message
 *
 * @return Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 */
static inline uint64_t mavlink_msg_ahrs400_angle_raw_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field xacc from ahrs400_angle_raw message
 *
 * @return X acceleration (G range*1.5/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_xacc(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field yacc from ahrs400_angle_raw message
 *
 * @return Y acceleration (G range*1.5/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_yacc(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field zacc from ahrs400_angle_raw message
 *
 * @return Z acceleration (G range*1.5/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_zacc(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field xgyro from ahrs400_angle_raw message
 *
 * @return Angular speed around X axis (angular rate range*1.5/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_xgyro(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field ygyro from ahrs400_angle_raw message
 *
 * @return Angular speed around Y axis (angular rate range*1.5/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_ygyro(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field zgyro from ahrs400_angle_raw message
 *
 * @return Angular speed around Z axis (angular rate range*1.5/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_zgyro(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field xmag from ahrs400_angle_raw message
 *
 * @return X magnetic field (magnetic field range*1.5/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_xmag(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field ymag from ahrs400_angle_raw message
 *
 * @return Y magnetic field (magnetic field range*1.5/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_ymag(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field zmag from ahrs400_angle_raw message
 *
 * @return Z magnetic field (magnetic field range*1.5/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_zmag(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field roll from ahrs400_angle_raw message
 *
 * @return Roll angle (180degrees/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field pitch from ahrs400_angle_raw message
 *
 * @return Pitch angle (180degrees/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field yaw from ahrs400_angle_raw message
 *
 * @return Yaw angle (180degrees/2^15)
 */
static inline int16_t mavlink_msg_ahrs400_angle_raw_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field temperature from ahrs400_angle_raw message
 *
 * @return temperature
 */
static inline uint16_t mavlink_msg_ahrs400_angle_raw_get_temperature(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field sensor_time from ahrs400_angle_raw message
 *
 * @return internal time of the DMU
 */
static inline uint16_t mavlink_msg_ahrs400_angle_raw_get_sensor_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Decode a ahrs400_angle_raw message into a struct
 *
 * @param msg The message to decode
 * @param ahrs400_angle_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_ahrs400_angle_raw_decode(const mavlink_message_t* msg, mavlink_ahrs400_angle_raw_t* ahrs400_angle_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	ahrs400_angle_raw->time_usec = mavlink_msg_ahrs400_angle_raw_get_time_usec(msg);
	ahrs400_angle_raw->xacc = mavlink_msg_ahrs400_angle_raw_get_xacc(msg);
	ahrs400_angle_raw->yacc = mavlink_msg_ahrs400_angle_raw_get_yacc(msg);
	ahrs400_angle_raw->zacc = mavlink_msg_ahrs400_angle_raw_get_zacc(msg);
	ahrs400_angle_raw->xgyro = mavlink_msg_ahrs400_angle_raw_get_xgyro(msg);
	ahrs400_angle_raw->ygyro = mavlink_msg_ahrs400_angle_raw_get_ygyro(msg);
	ahrs400_angle_raw->zgyro = mavlink_msg_ahrs400_angle_raw_get_zgyro(msg);
	ahrs400_angle_raw->xmag = mavlink_msg_ahrs400_angle_raw_get_xmag(msg);
	ahrs400_angle_raw->ymag = mavlink_msg_ahrs400_angle_raw_get_ymag(msg);
	ahrs400_angle_raw->zmag = mavlink_msg_ahrs400_angle_raw_get_zmag(msg);
	ahrs400_angle_raw->roll = mavlink_msg_ahrs400_angle_raw_get_roll(msg);
	ahrs400_angle_raw->pitch = mavlink_msg_ahrs400_angle_raw_get_pitch(msg);
	ahrs400_angle_raw->yaw = mavlink_msg_ahrs400_angle_raw_get_yaw(msg);
	ahrs400_angle_raw->temperature = mavlink_msg_ahrs400_angle_raw_get_temperature(msg);
	ahrs400_angle_raw->sensor_time = mavlink_msg_ahrs400_angle_raw_get_sensor_time(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN? msg->len : MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN;
        memset(ahrs400_angle_raw, 0, MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_LEN);
	memcpy(ahrs400_angle_raw, _MAV_PAYLOAD(msg), len);
#endif
}
