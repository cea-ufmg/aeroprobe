// MESSAGE GPS_RMC PACKING

#define MAVLINK_MSG_ID_GPS_RMC 166

typedef struct MAVLINK_PACKED __mavlink_gps_rmc_t
{
 uint64_t time_usec; /*< Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)*/
 uint64_t fix_time_usec; /*< Unix timestamp of GPS fix in microseconds.*/
 double latitude; /*< Latitude (WGS84) in degrees*/
 double longitude; /*< Longitude (WGS84) in degrees*/
 float speed; /*< Speed over ground (knots)*/
 float course; /*< Course over ground in degrees*/
 float mag_var; /*< Magnetic variation in degrees*/
 char warning; /*< Navigation receiver warning (A = OK, V = warning)*/
 char mode; /*< Mode indicator (A=autonomous, D=differential, E=Estimated, N=not valid, S=Simulator)*/
} mavlink_gps_rmc_t;

#define MAVLINK_MSG_ID_GPS_RMC_LEN 46
#define MAVLINK_MSG_ID_GPS_RMC_MIN_LEN 46
#define MAVLINK_MSG_ID_166_LEN 46
#define MAVLINK_MSG_ID_166_MIN_LEN 46

#define MAVLINK_MSG_ID_GPS_RMC_CRC 38
#define MAVLINK_MSG_ID_166_CRC 38



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_RMC { \
	166, \
	"GPS_RMC", \
	9, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_rmc_t, time_usec) }, \
         { "fix_time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_gps_rmc_t, fix_time_usec) }, \
         { "latitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_gps_rmc_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_gps_rmc_t, longitude) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_gps_rmc_t, speed) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_gps_rmc_t, course) }, \
         { "mag_var", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_gps_rmc_t, mag_var) }, \
         { "warning", NULL, MAVLINK_TYPE_CHAR, 0, 44, offsetof(mavlink_gps_rmc_t, warning) }, \
         { "mode", NULL, MAVLINK_TYPE_CHAR, 0, 45, offsetof(mavlink_gps_rmc_t, mode) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_RMC { \
	"GPS_RMC", \
	9, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_rmc_t, time_usec) }, \
         { "fix_time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_gps_rmc_t, fix_time_usec) }, \
         { "latitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_gps_rmc_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_gps_rmc_t, longitude) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_gps_rmc_t, speed) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_gps_rmc_t, course) }, \
         { "mag_var", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_gps_rmc_t, mag_var) }, \
         { "warning", NULL, MAVLINK_TYPE_CHAR, 0, 44, offsetof(mavlink_gps_rmc_t, warning) }, \
         { "mode", NULL, MAVLINK_TYPE_CHAR, 0, 45, offsetof(mavlink_gps_rmc_t, mode) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_rmc message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param fix_time_usec Unix timestamp of GPS fix in microseconds.
 * @param warning Navigation receiver warning (A = OK, V = warning)
 * @param latitude Latitude (WGS84) in degrees
 * @param longitude Longitude (WGS84) in degrees
 * @param speed Speed over ground (knots)
 * @param course Course over ground in degrees
 * @param mag_var Magnetic variation in degrees
 * @param mode Mode indicator (A=autonomous, D=differential, E=Estimated, N=not valid, S=Simulator)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_rmc_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, uint64_t fix_time_usec, char warning, double latitude, double longitude, float speed, float course, float mag_var, char mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_RMC_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint64_t(buf, 8, fix_time_usec);
	_mav_put_double(buf, 16, latitude);
	_mav_put_double(buf, 24, longitude);
	_mav_put_float(buf, 32, speed);
	_mav_put_float(buf, 36, course);
	_mav_put_float(buf, 40, mag_var);
	_mav_put_char(buf, 44, warning);
	_mav_put_char(buf, 45, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_RMC_LEN);
#else
	mavlink_gps_rmc_t packet;
	packet.time_usec = time_usec;
	packet.fix_time_usec = fix_time_usec;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.speed = speed;
	packet.course = course;
	packet.mag_var = mag_var;
	packet.warning = warning;
	packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_RMC_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_RMC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_RMC_MIN_LEN, MAVLINK_MSG_ID_GPS_RMC_LEN, MAVLINK_MSG_ID_GPS_RMC_CRC);
}

/**
 * @brief Pack a gps_rmc message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param fix_time_usec Unix timestamp of GPS fix in microseconds.
 * @param warning Navigation receiver warning (A = OK, V = warning)
 * @param latitude Latitude (WGS84) in degrees
 * @param longitude Longitude (WGS84) in degrees
 * @param speed Speed over ground (knots)
 * @param course Course over ground in degrees
 * @param mag_var Magnetic variation in degrees
 * @param mode Mode indicator (A=autonomous, D=differential, E=Estimated, N=not valid, S=Simulator)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_rmc_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,uint64_t fix_time_usec,char warning,double latitude,double longitude,float speed,float course,float mag_var,char mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_RMC_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint64_t(buf, 8, fix_time_usec);
	_mav_put_double(buf, 16, latitude);
	_mav_put_double(buf, 24, longitude);
	_mav_put_float(buf, 32, speed);
	_mav_put_float(buf, 36, course);
	_mav_put_float(buf, 40, mag_var);
	_mav_put_char(buf, 44, warning);
	_mav_put_char(buf, 45, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_RMC_LEN);
#else
	mavlink_gps_rmc_t packet;
	packet.time_usec = time_usec;
	packet.fix_time_usec = fix_time_usec;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.speed = speed;
	packet.course = course;
	packet.mag_var = mag_var;
	packet.warning = warning;
	packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_RMC_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_RMC;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_RMC_MIN_LEN, MAVLINK_MSG_ID_GPS_RMC_LEN, MAVLINK_MSG_ID_GPS_RMC_CRC);
}

/**
 * @brief Encode a gps_rmc struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps_rmc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_rmc_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_rmc_t* gps_rmc)
{
	return mavlink_msg_gps_rmc_pack(system_id, component_id, msg, gps_rmc->time_usec, gps_rmc->fix_time_usec, gps_rmc->warning, gps_rmc->latitude, gps_rmc->longitude, gps_rmc->speed, gps_rmc->course, gps_rmc->mag_var, gps_rmc->mode);
}

/**
 * @brief Encode a gps_rmc struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps_rmc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_rmc_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps_rmc_t* gps_rmc)
{
	return mavlink_msg_gps_rmc_pack_chan(system_id, component_id, chan, msg, gps_rmc->time_usec, gps_rmc->fix_time_usec, gps_rmc->warning, gps_rmc->latitude, gps_rmc->longitude, gps_rmc->speed, gps_rmc->course, gps_rmc->mag_var, gps_rmc->mode);
}

/**
 * @brief Send a gps_rmc message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param fix_time_usec Unix timestamp of GPS fix in microseconds.
 * @param warning Navigation receiver warning (A = OK, V = warning)
 * @param latitude Latitude (WGS84) in degrees
 * @param longitude Longitude (WGS84) in degrees
 * @param speed Speed over ground (knots)
 * @param course Course over ground in degrees
 * @param mag_var Magnetic variation in degrees
 * @param mode Mode indicator (A=autonomous, D=differential, E=Estimated, N=not valid, S=Simulator)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps_rmc_send(mavlink_channel_t chan, uint64_t time_usec, uint64_t fix_time_usec, char warning, double latitude, double longitude, float speed, float course, float mag_var, char mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_RMC_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint64_t(buf, 8, fix_time_usec);
	_mav_put_double(buf, 16, latitude);
	_mav_put_double(buf, 24, longitude);
	_mav_put_float(buf, 32, speed);
	_mav_put_float(buf, 36, course);
	_mav_put_float(buf, 40, mag_var);
	_mav_put_char(buf, 44, warning);
	_mav_put_char(buf, 45, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RMC, buf, MAVLINK_MSG_ID_GPS_RMC_MIN_LEN, MAVLINK_MSG_ID_GPS_RMC_LEN, MAVLINK_MSG_ID_GPS_RMC_CRC);
#else
	mavlink_gps_rmc_t packet;
	packet.time_usec = time_usec;
	packet.fix_time_usec = fix_time_usec;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.speed = speed;
	packet.course = course;
	packet.mag_var = mag_var;
	packet.warning = warning;
	packet.mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RMC, (const char *)&packet, MAVLINK_MSG_ID_GPS_RMC_MIN_LEN, MAVLINK_MSG_ID_GPS_RMC_LEN, MAVLINK_MSG_ID_GPS_RMC_CRC);
#endif
}

/**
 * @brief Send a gps_rmc message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gps_rmc_send_struct(mavlink_channel_t chan, const mavlink_gps_rmc_t* gps_rmc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gps_rmc_send(chan, gps_rmc->time_usec, gps_rmc->fix_time_usec, gps_rmc->warning, gps_rmc->latitude, gps_rmc->longitude, gps_rmc->speed, gps_rmc->course, gps_rmc->mag_var, gps_rmc->mode);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RMC, (const char *)gps_rmc, MAVLINK_MSG_ID_GPS_RMC_MIN_LEN, MAVLINK_MSG_ID_GPS_RMC_LEN, MAVLINK_MSG_ID_GPS_RMC_CRC);
#endif
}

#if MAVLINK_MSG_ID_GPS_RMC_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gps_rmc_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint64_t fix_time_usec, char warning, double latitude, double longitude, float speed, float course, float mag_var, char mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint64_t(buf, 8, fix_time_usec);
	_mav_put_double(buf, 16, latitude);
	_mav_put_double(buf, 24, longitude);
	_mav_put_float(buf, 32, speed);
	_mav_put_float(buf, 36, course);
	_mav_put_float(buf, 40, mag_var);
	_mav_put_char(buf, 44, warning);
	_mav_put_char(buf, 45, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RMC, buf, MAVLINK_MSG_ID_GPS_RMC_MIN_LEN, MAVLINK_MSG_ID_GPS_RMC_LEN, MAVLINK_MSG_ID_GPS_RMC_CRC);
#else
	mavlink_gps_rmc_t *packet = (mavlink_gps_rmc_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->fix_time_usec = fix_time_usec;
	packet->latitude = latitude;
	packet->longitude = longitude;
	packet->speed = speed;
	packet->course = course;
	packet->mag_var = mag_var;
	packet->warning = warning;
	packet->mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_RMC, (const char *)packet, MAVLINK_MSG_ID_GPS_RMC_MIN_LEN, MAVLINK_MSG_ID_GPS_RMC_LEN, MAVLINK_MSG_ID_GPS_RMC_CRC);
#endif
}
#endif

#endif

// MESSAGE GPS_RMC UNPACKING


/**
 * @brief Get field time_usec from gps_rmc message
 *
 * @return Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 */
static inline uint64_t mavlink_msg_gps_rmc_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field fix_time_usec from gps_rmc message
 *
 * @return Unix timestamp of GPS fix in microseconds.
 */
static inline uint64_t mavlink_msg_gps_rmc_get_fix_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field warning from gps_rmc message
 *
 * @return Navigation receiver warning (A = OK, V = warning)
 */
static inline char mavlink_msg_gps_rmc_get_warning(const mavlink_message_t* msg)
{
	return _MAV_RETURN_char(msg,  44);
}

/**
 * @brief Get field latitude from gps_rmc message
 *
 * @return Latitude (WGS84) in degrees
 */
static inline double mavlink_msg_gps_rmc_get_latitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field longitude from gps_rmc message
 *
 * @return Longitude (WGS84) in degrees
 */
static inline double mavlink_msg_gps_rmc_get_longitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  24);
}

/**
 * @brief Get field speed from gps_rmc message
 *
 * @return Speed over ground (knots)
 */
static inline float mavlink_msg_gps_rmc_get_speed(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field course from gps_rmc message
 *
 * @return Course over ground in degrees
 */
static inline float mavlink_msg_gps_rmc_get_course(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field mag_var from gps_rmc message
 *
 * @return Magnetic variation in degrees
 */
static inline float mavlink_msg_gps_rmc_get_mag_var(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field mode from gps_rmc message
 *
 * @return Mode indicator (A=autonomous, D=differential, E=Estimated, N=not valid, S=Simulator)
 */
static inline char mavlink_msg_gps_rmc_get_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_char(msg,  45);
}

/**
 * @brief Decode a gps_rmc message into a struct
 *
 * @param msg The message to decode
 * @param gps_rmc C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_rmc_decode(const mavlink_message_t* msg, mavlink_gps_rmc_t* gps_rmc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	gps_rmc->time_usec = mavlink_msg_gps_rmc_get_time_usec(msg);
	gps_rmc->fix_time_usec = mavlink_msg_gps_rmc_get_fix_time_usec(msg);
	gps_rmc->latitude = mavlink_msg_gps_rmc_get_latitude(msg);
	gps_rmc->longitude = mavlink_msg_gps_rmc_get_longitude(msg);
	gps_rmc->speed = mavlink_msg_gps_rmc_get_speed(msg);
	gps_rmc->course = mavlink_msg_gps_rmc_get_course(msg);
	gps_rmc->mag_var = mavlink_msg_gps_rmc_get_mag_var(msg);
	gps_rmc->warning = mavlink_msg_gps_rmc_get_warning(msg);
	gps_rmc->mode = mavlink_msg_gps_rmc_get_mode(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GPS_RMC_LEN? msg->len : MAVLINK_MSG_ID_GPS_RMC_LEN;
        memset(gps_rmc, 0, MAVLINK_MSG_ID_GPS_RMC_LEN);
	memcpy(gps_rmc, _MAV_PAYLOAD(msg), len);
#endif
}
