// MESSAGE GPS_GGA PACKING

#define MAVLINK_MSG_ID_GPS_GGA 165

typedef struct MAVLINK_PACKED __mavlink_gps_gga_t
{
 uint64_t time_usec; /*< Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)*/
 double latitude; /*< Latitude (WGS84) in degrees*/
 double longitude; /*< Longitude (WGS84) in degrees*/
 double altitude; /*< Altitude in meters above mean sea level*/
 float fix_time; /*< UTC time of GPS fix in seconds from start of day.*/
 float hdop; /*< Horizontal dilution of precision*/
 float geoid_height; /*< Height in meters of the geoid (mean sea level) above WGS84 ellipsoid*/
 float age_dgps; /*< Time in seconds since last DGPS update*/
 uint8_t quality; /*< GPS quality indication*/
 uint8_t num_sats; /*< Number of satellites in use*/
 char dgps_id[4]; /*< DGPS station ID.*/
} mavlink_gps_gga_t;

#define MAVLINK_MSG_ID_GPS_GGA_LEN 54
#define MAVLINK_MSG_ID_GPS_GGA_MIN_LEN 54
#define MAVLINK_MSG_ID_165_LEN 54
#define MAVLINK_MSG_ID_165_MIN_LEN 54

#define MAVLINK_MSG_ID_GPS_GGA_CRC 83
#define MAVLINK_MSG_ID_165_CRC 83

#define MAVLINK_MSG_GPS_GGA_FIELD_DGPS_ID_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_GGA { \
	165, \
	"GPS_GGA", \
	11, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_gga_t, time_usec) }, \
         { "latitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_gps_gga_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_gps_gga_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_gps_gga_t, altitude) }, \
         { "fix_time", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_gps_gga_t, fix_time) }, \
         { "hdop", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_gps_gga_t, hdop) }, \
         { "geoid_height", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_gps_gga_t, geoid_height) }, \
         { "age_dgps", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_gps_gga_t, age_dgps) }, \
         { "quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_gps_gga_t, quality) }, \
         { "num_sats", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_gps_gga_t, num_sats) }, \
         { "dgps_id", NULL, MAVLINK_TYPE_CHAR, 4, 50, offsetof(mavlink_gps_gga_t, dgps_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_GGA { \
	"GPS_GGA", \
	11, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_gga_t, time_usec) }, \
         { "latitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_gps_gga_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_gps_gga_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_gps_gga_t, altitude) }, \
         { "fix_time", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_gps_gga_t, fix_time) }, \
         { "hdop", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_gps_gga_t, hdop) }, \
         { "geoid_height", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_gps_gga_t, geoid_height) }, \
         { "age_dgps", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_gps_gga_t, age_dgps) }, \
         { "quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_gps_gga_t, quality) }, \
         { "num_sats", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_gps_gga_t, num_sats) }, \
         { "dgps_id", NULL, MAVLINK_TYPE_CHAR, 4, 50, offsetof(mavlink_gps_gga_t, dgps_id) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_gga message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param fix_time UTC time of GPS fix in seconds from start of day.
 * @param latitude Latitude (WGS84) in degrees
 * @param longitude Longitude (WGS84) in degrees
 * @param quality GPS quality indication
 * @param num_sats Number of satellites in use
 * @param hdop Horizontal dilution of precision
 * @param altitude Altitude in meters above mean sea level
 * @param geoid_height Height in meters of the geoid (mean sea level) above WGS84 ellipsoid
 * @param age_dgps Time in seconds since last DGPS update
 * @param dgps_id DGPS station ID.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_gga_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, float fix_time, double latitude, double longitude, uint8_t quality, uint8_t num_sats, float hdop, double altitude, float geoid_height, float age_dgps, const char *dgps_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_GGA_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_double(buf, 8, latitude);
	_mav_put_double(buf, 16, longitude);
	_mav_put_double(buf, 24, altitude);
	_mav_put_float(buf, 32, fix_time);
	_mav_put_float(buf, 36, hdop);
	_mav_put_float(buf, 40, geoid_height);
	_mav_put_float(buf, 44, age_dgps);
	_mav_put_uint8_t(buf, 48, quality);
	_mav_put_uint8_t(buf, 49, num_sats);
	_mav_put_char_array(buf, 50, dgps_id, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_GGA_LEN);
#else
	mavlink_gps_gga_t packet;
	packet.time_usec = time_usec;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.fix_time = fix_time;
	packet.hdop = hdop;
	packet.geoid_height = geoid_height;
	packet.age_dgps = age_dgps;
	packet.quality = quality;
	packet.num_sats = num_sats;
	mav_array_memcpy(packet.dgps_id, dgps_id, sizeof(char)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_GGA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_GGA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_GGA_MIN_LEN, MAVLINK_MSG_ID_GPS_GGA_LEN, MAVLINK_MSG_ID_GPS_GGA_CRC);
}

/**
 * @brief Pack a gps_gga message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param fix_time UTC time of GPS fix in seconds from start of day.
 * @param latitude Latitude (WGS84) in degrees
 * @param longitude Longitude (WGS84) in degrees
 * @param quality GPS quality indication
 * @param num_sats Number of satellites in use
 * @param hdop Horizontal dilution of precision
 * @param altitude Altitude in meters above mean sea level
 * @param geoid_height Height in meters of the geoid (mean sea level) above WGS84 ellipsoid
 * @param age_dgps Time in seconds since last DGPS update
 * @param dgps_id DGPS station ID.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_gga_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,float fix_time,double latitude,double longitude,uint8_t quality,uint8_t num_sats,float hdop,double altitude,float geoid_height,float age_dgps,const char *dgps_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_GGA_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_double(buf, 8, latitude);
	_mav_put_double(buf, 16, longitude);
	_mav_put_double(buf, 24, altitude);
	_mav_put_float(buf, 32, fix_time);
	_mav_put_float(buf, 36, hdop);
	_mav_put_float(buf, 40, geoid_height);
	_mav_put_float(buf, 44, age_dgps);
	_mav_put_uint8_t(buf, 48, quality);
	_mav_put_uint8_t(buf, 49, num_sats);
	_mav_put_char_array(buf, 50, dgps_id, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_GGA_LEN);
#else
	mavlink_gps_gga_t packet;
	packet.time_usec = time_usec;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.fix_time = fix_time;
	packet.hdop = hdop;
	packet.geoid_height = geoid_height;
	packet.age_dgps = age_dgps;
	packet.quality = quality;
	packet.num_sats = num_sats;
	mav_array_memcpy(packet.dgps_id, dgps_id, sizeof(char)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_GGA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_GGA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_GGA_MIN_LEN, MAVLINK_MSG_ID_GPS_GGA_LEN, MAVLINK_MSG_ID_GPS_GGA_CRC);
}

/**
 * @brief Encode a gps_gga struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps_gga C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_gga_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_gga_t* gps_gga)
{
	return mavlink_msg_gps_gga_pack(system_id, component_id, msg, gps_gga->time_usec, gps_gga->fix_time, gps_gga->latitude, gps_gga->longitude, gps_gga->quality, gps_gga->num_sats, gps_gga->hdop, gps_gga->altitude, gps_gga->geoid_height, gps_gga->age_dgps, gps_gga->dgps_id);
}

/**
 * @brief Encode a gps_gga struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps_gga C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_gga_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps_gga_t* gps_gga)
{
	return mavlink_msg_gps_gga_pack_chan(system_id, component_id, chan, msg, gps_gga->time_usec, gps_gga->fix_time, gps_gga->latitude, gps_gga->longitude, gps_gga->quality, gps_gga->num_sats, gps_gga->hdop, gps_gga->altitude, gps_gga->geoid_height, gps_gga->age_dgps, gps_gga->dgps_id);
}

/**
 * @brief Send a gps_gga message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 * @param fix_time UTC time of GPS fix in seconds from start of day.
 * @param latitude Latitude (WGS84) in degrees
 * @param longitude Longitude (WGS84) in degrees
 * @param quality GPS quality indication
 * @param num_sats Number of satellites in use
 * @param hdop Horizontal dilution of precision
 * @param altitude Altitude in meters above mean sea level
 * @param geoid_height Height in meters of the geoid (mean sea level) above WGS84 ellipsoid
 * @param age_dgps Time in seconds since last DGPS update
 * @param dgps_id DGPS station ID.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps_gga_send(mavlink_channel_t chan, uint64_t time_usec, float fix_time, double latitude, double longitude, uint8_t quality, uint8_t num_sats, float hdop, double altitude, float geoid_height, float age_dgps, const char *dgps_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_GGA_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_double(buf, 8, latitude);
	_mav_put_double(buf, 16, longitude);
	_mav_put_double(buf, 24, altitude);
	_mav_put_float(buf, 32, fix_time);
	_mav_put_float(buf, 36, hdop);
	_mav_put_float(buf, 40, geoid_height);
	_mav_put_float(buf, 44, age_dgps);
	_mav_put_uint8_t(buf, 48, quality);
	_mav_put_uint8_t(buf, 49, num_sats);
	_mav_put_char_array(buf, 50, dgps_id, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_GGA, buf, MAVLINK_MSG_ID_GPS_GGA_MIN_LEN, MAVLINK_MSG_ID_GPS_GGA_LEN, MAVLINK_MSG_ID_GPS_GGA_CRC);
#else
	mavlink_gps_gga_t packet;
	packet.time_usec = time_usec;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.fix_time = fix_time;
	packet.hdop = hdop;
	packet.geoid_height = geoid_height;
	packet.age_dgps = age_dgps;
	packet.quality = quality;
	packet.num_sats = num_sats;
	mav_array_memcpy(packet.dgps_id, dgps_id, sizeof(char)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_GGA, (const char *)&packet, MAVLINK_MSG_ID_GPS_GGA_MIN_LEN, MAVLINK_MSG_ID_GPS_GGA_LEN, MAVLINK_MSG_ID_GPS_GGA_CRC);
#endif
}

/**
 * @brief Send a gps_gga message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gps_gga_send_struct(mavlink_channel_t chan, const mavlink_gps_gga_t* gps_gga)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gps_gga_send(chan, gps_gga->time_usec, gps_gga->fix_time, gps_gga->latitude, gps_gga->longitude, gps_gga->quality, gps_gga->num_sats, gps_gga->hdop, gps_gga->altitude, gps_gga->geoid_height, gps_gga->age_dgps, gps_gga->dgps_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_GGA, (const char *)gps_gga, MAVLINK_MSG_ID_GPS_GGA_MIN_LEN, MAVLINK_MSG_ID_GPS_GGA_LEN, MAVLINK_MSG_ID_GPS_GGA_CRC);
#endif
}

#if MAVLINK_MSG_ID_GPS_GGA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gps_gga_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, float fix_time, double latitude, double longitude, uint8_t quality, uint8_t num_sats, float hdop, double altitude, float geoid_height, float age_dgps, const char *dgps_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_double(buf, 8, latitude);
	_mav_put_double(buf, 16, longitude);
	_mav_put_double(buf, 24, altitude);
	_mav_put_float(buf, 32, fix_time);
	_mav_put_float(buf, 36, hdop);
	_mav_put_float(buf, 40, geoid_height);
	_mav_put_float(buf, 44, age_dgps);
	_mav_put_uint8_t(buf, 48, quality);
	_mav_put_uint8_t(buf, 49, num_sats);
	_mav_put_char_array(buf, 50, dgps_id, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_GGA, buf, MAVLINK_MSG_ID_GPS_GGA_MIN_LEN, MAVLINK_MSG_ID_GPS_GGA_LEN, MAVLINK_MSG_ID_GPS_GGA_CRC);
#else
	mavlink_gps_gga_t *packet = (mavlink_gps_gga_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->latitude = latitude;
	packet->longitude = longitude;
	packet->altitude = altitude;
	packet->fix_time = fix_time;
	packet->hdop = hdop;
	packet->geoid_height = geoid_height;
	packet->age_dgps = age_dgps;
	packet->quality = quality;
	packet->num_sats = num_sats;
	mav_array_memcpy(packet->dgps_id, dgps_id, sizeof(char)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_GGA, (const char *)packet, MAVLINK_MSG_ID_GPS_GGA_MIN_LEN, MAVLINK_MSG_ID_GPS_GGA_LEN, MAVLINK_MSG_ID_GPS_GGA_CRC);
#endif
}
#endif

#endif

// MESSAGE GPS_GGA UNPACKING


/**
 * @brief Get field time_usec from gps_gga message
 *
 * @return Unix timestamp of receipt in microseconds or since system boot if smaller than MAVLink epoch (1.1.2009)
 */
static inline uint64_t mavlink_msg_gps_gga_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field fix_time from gps_gga message
 *
 * @return UTC time of GPS fix in seconds from start of day.
 */
static inline float mavlink_msg_gps_gga_get_fix_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field latitude from gps_gga message
 *
 * @return Latitude (WGS84) in degrees
 */
static inline double mavlink_msg_gps_gga_get_latitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field longitude from gps_gga message
 *
 * @return Longitude (WGS84) in degrees
 */
static inline double mavlink_msg_gps_gga_get_longitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field quality from gps_gga message
 *
 * @return GPS quality indication
 */
static inline uint8_t mavlink_msg_gps_gga_get_quality(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  48);
}

/**
 * @brief Get field num_sats from gps_gga message
 *
 * @return Number of satellites in use
 */
static inline uint8_t mavlink_msg_gps_gga_get_num_sats(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  49);
}

/**
 * @brief Get field hdop from gps_gga message
 *
 * @return Horizontal dilution of precision
 */
static inline float mavlink_msg_gps_gga_get_hdop(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field altitude from gps_gga message
 *
 * @return Altitude in meters above mean sea level
 */
static inline double mavlink_msg_gps_gga_get_altitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  24);
}

/**
 * @brief Get field geoid_height from gps_gga message
 *
 * @return Height in meters of the geoid (mean sea level) above WGS84 ellipsoid
 */
static inline float mavlink_msg_gps_gga_get_geoid_height(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field age_dgps from gps_gga message
 *
 * @return Time in seconds since last DGPS update
 */
static inline float mavlink_msg_gps_gga_get_age_dgps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field dgps_id from gps_gga message
 *
 * @return DGPS station ID.
 */
static inline uint16_t mavlink_msg_gps_gga_get_dgps_id(const mavlink_message_t* msg, char *dgps_id)
{
	return _MAV_RETURN_char_array(msg, dgps_id, 4,  50);
}

/**
 * @brief Decode a gps_gga message into a struct
 *
 * @param msg The message to decode
 * @param gps_gga C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_gga_decode(const mavlink_message_t* msg, mavlink_gps_gga_t* gps_gga)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	gps_gga->time_usec = mavlink_msg_gps_gga_get_time_usec(msg);
	gps_gga->latitude = mavlink_msg_gps_gga_get_latitude(msg);
	gps_gga->longitude = mavlink_msg_gps_gga_get_longitude(msg);
	gps_gga->altitude = mavlink_msg_gps_gga_get_altitude(msg);
	gps_gga->fix_time = mavlink_msg_gps_gga_get_fix_time(msg);
	gps_gga->hdop = mavlink_msg_gps_gga_get_hdop(msg);
	gps_gga->geoid_height = mavlink_msg_gps_gga_get_geoid_height(msg);
	gps_gga->age_dgps = mavlink_msg_gps_gga_get_age_dgps(msg);
	gps_gga->quality = mavlink_msg_gps_gga_get_quality(msg);
	gps_gga->num_sats = mavlink_msg_gps_gga_get_num_sats(msg);
	mavlink_msg_gps_gga_get_dgps_id(msg, gps_gga->dgps_id);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GPS_GGA_LEN? msg->len : MAVLINK_MSG_ID_GPS_GGA_LEN;
        memset(gps_gga, 0, MAVLINK_MSG_ID_GPS_GGA_LEN);
	memcpy(gps_gga, _MAV_PAYLOAD(msg), len);
#endif
}
