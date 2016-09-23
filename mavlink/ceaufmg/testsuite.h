/** @file
 *	@brief MAVLink comm protocol testsuite generated from ceaufmg.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef CEAUFMG_TESTSUITE_H
#define CEAUFMG_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ceaufmg(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_ceaufmg(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_ahrs400_angle_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AHRS400_ANGLE_RAW >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ahrs400_angle_raw_t packet_in = {
		93372036854775807ULL,17651,17755,17859,17963,18067,18171,18275,18379,18483,18587,18691,18795,18899,19003
    };
	mavlink_ahrs400_angle_raw_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.xacc = packet_in.xacc;
        packet1.yacc = packet_in.yacc;
        packet1.zacc = packet_in.zacc;
        packet1.xgyro = packet_in.xgyro;
        packet1.ygyro = packet_in.ygyro;
        packet1.zgyro = packet_in.zgyro;
        packet1.xmag = packet_in.xmag;
        packet1.ymag = packet_in.ymag;
        packet1.zmag = packet_in.zmag;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.temperature = packet_in.temperature;
        packet1.sensor_time = packet_in.sensor_time;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AHRS400_ANGLE_RAW_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs400_angle_raw_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ahrs400_angle_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs400_angle_raw_pack(system_id, component_id, &msg , packet1.time_usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag , packet1.roll , packet1.pitch , packet1.yaw , packet1.temperature , packet1.sensor_time );
	mavlink_msg_ahrs400_angle_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs400_angle_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag , packet1.roll , packet1.pitch , packet1.yaw , packet1.temperature , packet1.sensor_time );
	mavlink_msg_ahrs400_angle_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ahrs400_angle_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs400_angle_raw_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag , packet1.roll , packet1.pitch , packet1.yaw , packet1.temperature , packet1.sensor_time );
	mavlink_msg_ahrs400_angle_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ahrs400_angle(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AHRS400_ANGLE >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ahrs400_angle_t packet_in = {
		93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,20355
    };
	mavlink_ahrs400_angle_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.xacc = packet_in.xacc;
        packet1.yacc = packet_in.yacc;
        packet1.zacc = packet_in.zacc;
        packet1.xgyro = packet_in.xgyro;
        packet1.ygyro = packet_in.ygyro;
        packet1.zgyro = packet_in.zgyro;
        packet1.xmag = packet_in.xmag;
        packet1.ymag = packet_in.ymag;
        packet1.zmag = packet_in.zmag;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.temperature = packet_in.temperature;
        packet1.sensor_time = packet_in.sensor_time;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AHRS400_ANGLE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AHRS400_ANGLE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs400_angle_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ahrs400_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs400_angle_pack(system_id, component_id, &msg , packet1.time_usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag , packet1.roll , packet1.pitch , packet1.yaw , packet1.temperature , packet1.sensor_time );
	mavlink_msg_ahrs400_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs400_angle_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag , packet1.roll , packet1.pitch , packet1.yaw , packet1.temperature , packet1.sensor_time );
	mavlink_msg_ahrs400_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ahrs400_angle_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs400_angle_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.xmag , packet1.ymag , packet1.zmag , packet1.roll , packet1.pitch , packet1.yaw , packet1.temperature , packet1.sensor_time );
	mavlink_msg_ahrs400_angle_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_adc_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ADC_RAW >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_adc_raw_t packet_in = {
		93372036854775807ULL,{ 17651, 17652, 17653, 17654, 17655, 17656, 17657, 17658, 17659, 17660, 17661, 17662, 17663, 17664, 17665, 17666 }
    };
	mavlink_adc_raw_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        
        mav_array_memcpy(packet1.data, packet_in.data, sizeof(int16_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ADC_RAW_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ADC_RAW_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_raw_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_adc_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_raw_pack(system_id, component_id, &msg , packet1.time_usec , packet1.data );
	mavlink_msg_adc_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.data );
	mavlink_msg_adc_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_adc_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_raw_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.data );
	mavlink_msg_adc_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gps_gga(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GPS_GGA >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_gps_gga_t packet_in = {
		93372036854775807ULL,179.0,235.0,291.0,241.0,269.0,297.0,325.0,149,216,"YZA"
    };
	mavlink_gps_gga_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.altitude = packet_in.altitude;
        packet1.fix_time = packet_in.fix_time;
        packet1.hdop = packet_in.hdop;
        packet1.geoid_height = packet_in.geoid_height;
        packet1.age_dgps = packet_in.age_dgps;
        packet1.quality = packet_in.quality;
        packet1.num_sats = packet_in.num_sats;
        
        mav_array_memcpy(packet1.dgps_id, packet_in.dgps_id, sizeof(char)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GPS_GGA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GPS_GGA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_gga_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gps_gga_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_gga_pack(system_id, component_id, &msg , packet1.time_usec , packet1.fix_time , packet1.latitude , packet1.longitude , packet1.quality , packet1.num_sats , packet1.hdop , packet1.altitude , packet1.geoid_height , packet1.age_dgps , packet1.dgps_id );
	mavlink_msg_gps_gga_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_gga_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.fix_time , packet1.latitude , packet1.longitude , packet1.quality , packet1.num_sats , packet1.hdop , packet1.altitude , packet1.geoid_height , packet1.age_dgps , packet1.dgps_id );
	mavlink_msg_gps_gga_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gps_gga_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_gga_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.fix_time , packet1.latitude , packet1.longitude , packet1.quality , packet1.num_sats , packet1.hdop , packet1.altitude , packet1.geoid_height , packet1.age_dgps , packet1.dgps_id );
	mavlink_msg_gps_gga_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gps_rmc(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GPS_RMC >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_gps_rmc_t packet_in = {
		93372036854775807ULL,93372036854776311ULL,235.0,291.0,241.0,269.0,297.0,'S','T'
    };
	mavlink_gps_rmc_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.fix_time_usec = packet_in.fix_time_usec;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.speed = packet_in.speed;
        packet1.course = packet_in.course;
        packet1.mag_var = packet_in.mag_var;
        packet1.warning = packet_in.warning;
        packet1.mode = packet_in.mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GPS_RMC_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GPS_RMC_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_rmc_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gps_rmc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_rmc_pack(system_id, component_id, &msg , packet1.time_usec , packet1.fix_time_usec , packet1.warning , packet1.latitude , packet1.longitude , packet1.speed , packet1.course , packet1.mag_var , packet1.mode );
	mavlink_msg_gps_rmc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_rmc_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.fix_time_usec , packet1.warning , packet1.latitude , packet1.longitude , packet1.speed , packet1.course , packet1.mag_var , packet1.mode );
	mavlink_msg_gps_rmc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gps_rmc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_rmc_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.fix_time_usec , packet1.warning , packet1.latitude , packet1.longitude , packet1.speed , packet1.course , packet1.mag_var , packet1.mode );
	mavlink_msg_gps_rmc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gps_pgrmv(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GPS_PGRMV >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_gps_pgrmv_t packet_in = {
		93372036854775807ULL,73.0,101.0,129.0
    };
	mavlink_gps_pgrmv_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.veast = packet_in.veast;
        packet1.vnorth = packet_in.vnorth;
        packet1.vup = packet_in.vup;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GPS_PGRMV_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GPS_PGRMV_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_pgrmv_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gps_pgrmv_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_pgrmv_pack(system_id, component_id, &msg , packet1.time_usec , packet1.veast , packet1.vnorth , packet1.vup );
	mavlink_msg_gps_pgrmv_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_pgrmv_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.veast , packet1.vnorth , packet1.vup );
	mavlink_msg_gps_pgrmv_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gps_pgrmv_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_pgrmv_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.veast , packet1.vnorth , packet1.vup );
	mavlink_msg_gps_pgrmv_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gps_pgrme(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GPS_PGRME >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_gps_pgrme_t packet_in = {
		93372036854775807ULL,73.0,101.0,129.0
    };
	mavlink_gps_pgrme_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.hpe = packet_in.hpe;
        packet1.vpe = packet_in.vpe;
        packet1.epe = packet_in.epe;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GPS_PGRME_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GPS_PGRME_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_pgrme_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gps_pgrme_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_pgrme_pack(system_id, component_id, &msg , packet1.time_usec , packet1.hpe , packet1.vpe , packet1.epe );
	mavlink_msg_gps_pgrme_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_pgrme_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.hpe , packet1.vpe , packet1.epe );
	mavlink_msg_gps_pgrme_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gps_pgrme_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gps_pgrme_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.hpe , packet1.vpe , packet1.epe );
	mavlink_msg_gps_pgrme_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_data_int(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DATA_INT >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_data_int_t packet_in = {
		93372036854775807ULL,93372036854776311LL,18067
    };
	mavlink_data_int_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.value = packet_in.value;
        packet1.id = packet_in.id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DATA_INT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DATA_INT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_int_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_data_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_int_pack(system_id, component_id, &msg , packet1.time_usec , packet1.id , packet1.value );
	mavlink_msg_data_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_int_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.id , packet1.value );
	mavlink_msg_data_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_data_int_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_int_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.id , packet1.value );
	mavlink_msg_data_int_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_data_float(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DATA_FLOAT >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_data_float_t packet_in = {
		93372036854775807ULL,73.0,17859
    };
	mavlink_data_float_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.value = packet_in.value;
        packet1.id = packet_in.id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DATA_FLOAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DATA_FLOAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_float_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_data_float_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_float_pack(system_id, component_id, &msg , packet1.time_usec , packet1.id , packet1.value );
	mavlink_msg_data_float_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_float_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.id , packet1.value );
	mavlink_msg_data_float_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_data_float_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_float_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.id , packet1.value );
	mavlink_msg_data_float_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_data_double(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DATA_DOUBLE >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_data_double_t packet_in = {
		93372036854775807ULL,179.0,18067
    };
	mavlink_data_double_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.value = packet_in.value;
        packet1.id = packet_in.id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DATA_DOUBLE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DATA_DOUBLE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_double_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_data_double_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_double_pack(system_id, component_id, &msg , packet1.time_usec , packet1.id , packet1.value );
	mavlink_msg_data_double_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_double_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.id , packet1.value );
	mavlink_msg_data_double_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_data_double_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_double_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.id , packet1.value );
	mavlink_msg_data_double_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ceaufmg(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_ahrs400_angle_raw(system_id, component_id, last_msg);
	mavlink_test_ahrs400_angle(system_id, component_id, last_msg);
	mavlink_test_adc_raw(system_id, component_id, last_msg);
	mavlink_test_gps_gga(system_id, component_id, last_msg);
	mavlink_test_gps_rmc(system_id, component_id, last_msg);
	mavlink_test_gps_pgrmv(system_id, component_id, last_msg);
	mavlink_test_gps_pgrme(system_id, component_id, last_msg);
	mavlink_test_data_int(system_id, component_id, last_msg);
	mavlink_test_data_float(system_id, component_id, last_msg);
	mavlink_test_data_double(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // CEAUFMG_TESTSUITE_H
