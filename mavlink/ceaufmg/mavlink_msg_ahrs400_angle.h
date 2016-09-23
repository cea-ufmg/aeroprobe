// MESSAGE AHRS400_ANGLE PACKING

#define MAVLINK_MSG_ID_AHRS400_ANGLE 151

typedef struct MAVLINK_PACKED __mavlink_ahrs400_angle_t
{
 uint64_t time_usec; /*< Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)*/
 float xacc; /*< X acceleration (m/s^2)*/
 float yacc; /*< Y acceleration (m/s^2)*/
 float zacc; /*< Z acceleration (m/s^2)*/
 float xgyro; /*< Angular speed around X axis (rad/s)*/
 float ygyro; /*< Angular speed around Y axis (rad/s)*/
 float zgyro; /*< Angular speed around Z axis (rad/s)*/
 float xmag; /*< X magnetic field (gauss)*/
 float ymag; /*< Y magnetic field (gauss)*/
 float zmag; /*< Z magnetic field (gauss)*/
 float roll; /*< Roll angle (rad)*/
 float pitch; /*< Pitch angle (rad)*/
 float yaw; /*< Yaw angle (rad)*/
 float temperature; /*< temperature (degrees Celsius)*/
 uint16_t sensor_time; /*< internal time of the DMU*/
} mavlink_ahrs400_angle_t;

#define MAVLINK_MSG_ID_AHRS400_ANGLE_LEN 62
#define MAVLINK_MSG_ID_AHRS400_ANGLE_MIN_LEN 62
#define MAVLINK_MSG_ID_151_LEN 62
#define MAVLINK_MSG_ID_151_MIN_LEN 62

#define MAVLINK_MSG_ID_AHRS400_ANGLE_CRC 26
#define MAVLINK_MSG_ID_151_CRC 26



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AHRS400_ANGLE { \
	151, \
	"AHRS400_ANGLE", \
	15, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ahrs400_angle_t, time_usec) }, \
         { "xacc", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ahrs400_angle_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_ahrs400_angle_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_ahrs400_angle_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ahrs400_angle_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_ahrs400_angle_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_ahrs400_angle_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_ahrs400_angle_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_ahrs400_angle_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_ahrs400_angle_t, zmag) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_ahrs400_angle_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_ahrs400_angle_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_ahrs400_angle_t, yaw) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_ahrs400_angle_t, temperature) }, \
         { "sensor_time", NULL, MAVLINK_TYPE_UINT16_T, 0, 60, offsetof(mavlink_ahrs400_angle_t, sensor_time) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AHRS400_ANGLE { \
	"AHRS400_ANGLE", \
	15, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ahrs400_angle_t, time_usec) }, \
         { "xacc", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ahrs400_angle_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_ahrs400_angle_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_ahrs400_angle_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ahrs400_angle_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_ahrs400_angle_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_ahrs400_angle_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_ahrs400_angle_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_ahrs400_angle_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_ahrs400_angle_t, zmag) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_ahrs400_angle_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_ahrs400_angle_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_ahrs400_angle_t, yaw) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_ahrs400_angle_t, temperature) }, \
         { "sensor_time", NULL, MAVLINK_TYPE_UINT16_T, 0, 60, offsetof(mavlink_ahrs400_angle_t, sensor_time) }, \
         } \
}
#endif

/**
 * @brief Pack a ahrs400_angle message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param xacc X acceleration (m/s^2)
 * @param yacc Y acceleration (m/s^2)
 * @param zacc Z acceleration (m/s^2)
 * @param xgyro Angular speed around X axis (rad/s)
 * @param ygyro Angular speed around Y axis (rad/s)
 * @param zgyro Angular speed around Z axis (rad/s)
 * @param xmag X magnetic field (gauss)
 * @param ymag Y magnetic field (gauss)
 * @param zmag Z magnetic field (gauss)
 * @param roll Roll angle (rad)
 * @param pitch Pitch angle (rad)
 * @param yaw Yaw angle (rad)
 * @param temperature temperature (degrees Celsius)
 * @param sensor_time internal time of the DMU
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ahrs400_angle_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float roll, float pitch, float yaw, float temperature, uint16_t sensor_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AHRS400_ANGLE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, xacc);
	_mav_put_float(buf, 12, yacc);
	_mav_put_float(buf, 16, zacc);
	_mav_put_float(buf, 20, xgyro);
	_mav_put_float(buf, 24, ygyro);
	_mav_put_float(buf, 28, zgyro);
	_mav_put_float(buf, 32, xmag);
	_mav_put_float(buf, 36, ymag);
	_mav_put_float(buf, 40, zmag);
	_mav_put_float(buf, 44, roll);
	_mav_put_float(buf, 48, pitch);
	_mav_put_float(buf, 52, yaw);
	_mav_put_float(buf, 56, temperature);
	_mav_put_uint16_t(buf, 60, sensor_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN);
#else
	mavlink_ahrs400_angle_t packet;
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

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AHRS400_ANGLE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AHRS400_ANGLE_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_CRC);
}

/**
 * @brief Pack a ahrs400_angle message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param xacc X acceleration (m/s^2)
 * @param yacc Y acceleration (m/s^2)
 * @param zacc Z acceleration (m/s^2)
 * @param xgyro Angular speed around X axis (rad/s)
 * @param ygyro Angular speed around Y axis (rad/s)
 * @param zgyro Angular speed around Z axis (rad/s)
 * @param xmag X magnetic field (gauss)
 * @param ymag Y magnetic field (gauss)
 * @param zmag Z magnetic field (gauss)
 * @param roll Roll angle (rad)
 * @param pitch Pitch angle (rad)
 * @param yaw Yaw angle (rad)
 * @param temperature temperature (degrees Celsius)
 * @param sensor_time internal time of the DMU
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ahrs400_angle_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,float xacc,float yacc,float zacc,float xgyro,float ygyro,float zgyro,float xmag,float ymag,float zmag,float roll,float pitch,float yaw,float temperature,uint16_t sensor_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AHRS400_ANGLE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, xacc);
	_mav_put_float(buf, 12, yacc);
	_mav_put_float(buf, 16, zacc);
	_mav_put_float(buf, 20, xgyro);
	_mav_put_float(buf, 24, ygyro);
	_mav_put_float(buf, 28, zgyro);
	_mav_put_float(buf, 32, xmag);
	_mav_put_float(buf, 36, ymag);
	_mav_put_float(buf, 40, zmag);
	_mav_put_float(buf, 44, roll);
	_mav_put_float(buf, 48, pitch);
	_mav_put_float(buf, 52, yaw);
	_mav_put_float(buf, 56, temperature);
	_mav_put_uint16_t(buf, 60, sensor_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN);
#else
	mavlink_ahrs400_angle_t packet;
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

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AHRS400_ANGLE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AHRS400_ANGLE_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_CRC);
}

/**
 * @brief Encode a ahrs400_angle struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ahrs400_angle C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ahrs400_angle_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ahrs400_angle_t* ahrs400_angle)
{
	return mavlink_msg_ahrs400_angle_pack(system_id, component_id, msg, ahrs400_angle->time_usec, ahrs400_angle->xacc, ahrs400_angle->yacc, ahrs400_angle->zacc, ahrs400_angle->xgyro, ahrs400_angle->ygyro, ahrs400_angle->zgyro, ahrs400_angle->xmag, ahrs400_angle->ymag, ahrs400_angle->zmag, ahrs400_angle->roll, ahrs400_angle->pitch, ahrs400_angle->yaw, ahrs400_angle->temperature, ahrs400_angle->sensor_time);
}

/**
 * @brief Encode a ahrs400_angle struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ahrs400_angle C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ahrs400_angle_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ahrs400_angle_t* ahrs400_angle)
{
	return mavlink_msg_ahrs400_angle_pack_chan(system_id, component_id, chan, msg, ahrs400_angle->time_usec, ahrs400_angle->xacc, ahrs400_angle->yacc, ahrs400_angle->zacc, ahrs400_angle->xgyro, ahrs400_angle->ygyro, ahrs400_angle->zgyro, ahrs400_angle->xmag, ahrs400_angle->ymag, ahrs400_angle->zmag, ahrs400_angle->roll, ahrs400_angle->pitch, ahrs400_angle->yaw, ahrs400_angle->temperature, ahrs400_angle->sensor_time);
}

/**
 * @brief Send a ahrs400_angle message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param xacc X acceleration (m/s^2)
 * @param yacc Y acceleration (m/s^2)
 * @param zacc Z acceleration (m/s^2)
 * @param xgyro Angular speed around X axis (rad/s)
 * @param ygyro Angular speed around Y axis (rad/s)
 * @param zgyro Angular speed around Z axis (rad/s)
 * @param xmag X magnetic field (gauss)
 * @param ymag Y magnetic field (gauss)
 * @param zmag Z magnetic field (gauss)
 * @param roll Roll angle (rad)
 * @param pitch Pitch angle (rad)
 * @param yaw Yaw angle (rad)
 * @param temperature temperature (degrees Celsius)
 * @param sensor_time internal time of the DMU
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ahrs400_angle_send(mavlink_channel_t chan, uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float roll, float pitch, float yaw, float temperature, uint16_t sensor_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AHRS400_ANGLE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, xacc);
	_mav_put_float(buf, 12, yacc);
	_mav_put_float(buf, 16, zacc);
	_mav_put_float(buf, 20, xgyro);
	_mav_put_float(buf, 24, ygyro);
	_mav_put_float(buf, 28, zgyro);
	_mav_put_float(buf, 32, xmag);
	_mav_put_float(buf, 36, ymag);
	_mav_put_float(buf, 40, zmag);
	_mav_put_float(buf, 44, roll);
	_mav_put_float(buf, 48, pitch);
	_mav_put_float(buf, 52, yaw);
	_mav_put_float(buf, 56, temperature);
	_mav_put_uint16_t(buf, 60, sensor_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS400_ANGLE, buf, MAVLINK_MSG_ID_AHRS400_ANGLE_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_CRC);
#else
	mavlink_ahrs400_angle_t packet;
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

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS400_ANGLE, (const char *)&packet, MAVLINK_MSG_ID_AHRS400_ANGLE_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_CRC);
#endif
}

/**
 * @brief Send a ahrs400_angle message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ahrs400_angle_send_struct(mavlink_channel_t chan, const mavlink_ahrs400_angle_t* ahrs400_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ahrs400_angle_send(chan, ahrs400_angle->time_usec, ahrs400_angle->xacc, ahrs400_angle->yacc, ahrs400_angle->zacc, ahrs400_angle->xgyro, ahrs400_angle->ygyro, ahrs400_angle->zgyro, ahrs400_angle->xmag, ahrs400_angle->ymag, ahrs400_angle->zmag, ahrs400_angle->roll, ahrs400_angle->pitch, ahrs400_angle->yaw, ahrs400_angle->temperature, ahrs400_angle->sensor_time);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS400_ANGLE, (const char *)ahrs400_angle, MAVLINK_MSG_ID_AHRS400_ANGLE_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_CRC);
#endif
}

#if MAVLINK_MSG_ID_AHRS400_ANGLE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ahrs400_angle_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float roll, float pitch, float yaw, float temperature, uint16_t sensor_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, xacc);
	_mav_put_float(buf, 12, yacc);
	_mav_put_float(buf, 16, zacc);
	_mav_put_float(buf, 20, xgyro);
	_mav_put_float(buf, 24, ygyro);
	_mav_put_float(buf, 28, zgyro);
	_mav_put_float(buf, 32, xmag);
	_mav_put_float(buf, 36, ymag);
	_mav_put_float(buf, 40, zmag);
	_mav_put_float(buf, 44, roll);
	_mav_put_float(buf, 48, pitch);
	_mav_put_float(buf, 52, yaw);
	_mav_put_float(buf, 56, temperature);
	_mav_put_uint16_t(buf, 60, sensor_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS400_ANGLE, buf, MAVLINK_MSG_ID_AHRS400_ANGLE_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_CRC);
#else
	mavlink_ahrs400_angle_t *packet = (mavlink_ahrs400_angle_t *)msgbuf;
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

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AHRS400_ANGLE, (const char *)packet, MAVLINK_MSG_ID_AHRS400_ANGLE_MIN_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN, MAVLINK_MSG_ID_AHRS400_ANGLE_CRC);
#endif
}
#endif

#endif

// MESSAGE AHRS400_ANGLE UNPACKING


/**
 * @brief Get field time_usec from ahrs400_angle message
 *
 * @return Unix timestamp in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 */
static inline uint64_t mavlink_msg_ahrs400_angle_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field xacc from ahrs400_angle message
 *
 * @return X acceleration (m/s^2)
 */
static inline float mavlink_msg_ahrs400_angle_get_xacc(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field yacc from ahrs400_angle message
 *
 * @return Y acceleration (m/s^2)
 */
static inline float mavlink_msg_ahrs400_angle_get_yacc(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field zacc from ahrs400_angle message
 *
 * @return Z acceleration (m/s^2)
 */
static inline float mavlink_msg_ahrs400_angle_get_zacc(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field xgyro from ahrs400_angle message
 *
 * @return Angular speed around X axis (rad/s)
 */
static inline float mavlink_msg_ahrs400_angle_get_xgyro(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field ygyro from ahrs400_angle message
 *
 * @return Angular speed around Y axis (rad/s)
 */
static inline float mavlink_msg_ahrs400_angle_get_ygyro(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field zgyro from ahrs400_angle message
 *
 * @return Angular speed around Z axis (rad/s)
 */
static inline float mavlink_msg_ahrs400_angle_get_zgyro(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field xmag from ahrs400_angle message
 *
 * @return X magnetic field (gauss)
 */
static inline float mavlink_msg_ahrs400_angle_get_xmag(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field ymag from ahrs400_angle message
 *
 * @return Y magnetic field (gauss)
 */
static inline float mavlink_msg_ahrs400_angle_get_ymag(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field zmag from ahrs400_angle message
 *
 * @return Z magnetic field (gauss)
 */
static inline float mavlink_msg_ahrs400_angle_get_zmag(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field roll from ahrs400_angle message
 *
 * @return Roll angle (rad)
 */
static inline float mavlink_msg_ahrs400_angle_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field pitch from ahrs400_angle message
 *
 * @return Pitch angle (rad)
 */
static inline float mavlink_msg_ahrs400_angle_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field yaw from ahrs400_angle message
 *
 * @return Yaw angle (rad)
 */
static inline float mavlink_msg_ahrs400_angle_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field temperature from ahrs400_angle message
 *
 * @return temperature (degrees Celsius)
 */
static inline float mavlink_msg_ahrs400_angle_get_temperature(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field sensor_time from ahrs400_angle message
 *
 * @return internal time of the DMU
 */
static inline uint16_t mavlink_msg_ahrs400_angle_get_sensor_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  60);
}

/**
 * @brief Decode a ahrs400_angle message into a struct
 *
 * @param msg The message to decode
 * @param ahrs400_angle C-struct to decode the message contents into
 */
static inline void mavlink_msg_ahrs400_angle_decode(const mavlink_message_t* msg, mavlink_ahrs400_angle_t* ahrs400_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	ahrs400_angle->time_usec = mavlink_msg_ahrs400_angle_get_time_usec(msg);
	ahrs400_angle->xacc = mavlink_msg_ahrs400_angle_get_xacc(msg);
	ahrs400_angle->yacc = mavlink_msg_ahrs400_angle_get_yacc(msg);
	ahrs400_angle->zacc = mavlink_msg_ahrs400_angle_get_zacc(msg);
	ahrs400_angle->xgyro = mavlink_msg_ahrs400_angle_get_xgyro(msg);
	ahrs400_angle->ygyro = mavlink_msg_ahrs400_angle_get_ygyro(msg);
	ahrs400_angle->zgyro = mavlink_msg_ahrs400_angle_get_zgyro(msg);
	ahrs400_angle->xmag = mavlink_msg_ahrs400_angle_get_xmag(msg);
	ahrs400_angle->ymag = mavlink_msg_ahrs400_angle_get_ymag(msg);
	ahrs400_angle->zmag = mavlink_msg_ahrs400_angle_get_zmag(msg);
	ahrs400_angle->roll = mavlink_msg_ahrs400_angle_get_roll(msg);
	ahrs400_angle->pitch = mavlink_msg_ahrs400_angle_get_pitch(msg);
	ahrs400_angle->yaw = mavlink_msg_ahrs400_angle_get_yaw(msg);
	ahrs400_angle->temperature = mavlink_msg_ahrs400_angle_get_temperature(msg);
	ahrs400_angle->sensor_time = mavlink_msg_ahrs400_angle_get_sensor_time(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AHRS400_ANGLE_LEN? msg->len : MAVLINK_MSG_ID_AHRS400_ANGLE_LEN;
        memset(ahrs400_angle, 0, MAVLINK_MSG_ID_AHRS400_ANGLE_LEN);
	memcpy(ahrs400_angle, _MAV_PAYLOAD(msg), len);
#endif
}
