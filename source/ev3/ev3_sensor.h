
/*  ev3_sensor.h was generated by yup.py (yupp) 0.7b6
    out of ev3_sensor.yu-h at 2014-09-29 13:06
 *//**
 *  \file  ev3_sensor.h (ev3_sensor.yu-h)
 *  \brief  EV3 sensors.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef EV3_SENSOR_H
#define EV3_SENSOR_H

#ifdef  EV3_SENSOR_IMPLEMENT
#define EV3_SENSOR_EXT
#define EV3_SENSOR_EXT_INIT( dec, init ) \
	dec = init
#else
#define EV3_SENSOR_EXT extern
#define EV3_SENSOR_EXT_INIT( dec, init ) \
	extern dec
#endif

#ifndef COMMA
#define COMMA   ,
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \defgroup ev3_sensor Sensors
 *  \brief Access to EV3 sensors.
 *  \{
 */

/**
 *  \brief EV3 ports to plug in a sensor.
 */
enum {
	INPUT_1,
	INPUT_2,
	INPUT_3,
	INPUT_4,

	INPUT__COUNT_  /**< Count of EV3 "in" ports. */
};

/**
 *  \brief Structure of a sensor descriptor.
 */
typedef struct {
	bool     connected;  /**< Flag - the sensor is connected. */
	uint32_t id;         /**< Identifier of the sensor. */
	uint32_t type_id;    /**< The sensor type. */

} EV3_SENSOR;

/**
 *  \brief Vector of sensor descriptors for each port (filled by \ref ev3_sensor_init).
 */
EV3_SENSOR_EXT EV3_SENSOR ev3_sensor[ INPUT__COUNT_ ];

/**
 *  \brief Types of sensors.
 */
enum {
	EV3_TOUCH = 16,
	EV3_COLOR = 29,
	EV3_ULTRASONIC = 30,
	EV3_GYRO = 32,
	EV3_INFRARED = 33,

};

/**
 *  \brief Get "bin_data" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_bin_data( uint8_t id, byte *buf, size_t sz );

/**
 *  \brief Set "bin_data" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param value Attribute value.
 *  \param sz Size of attribute value.
 *  \return Count of written bytes.
 */
EV3_SENSOR_EXT size_t set_sensor_bin_data( uint8_t id, byte *value, size_t sz );

/**
 *  \brief Get "bin_data_format" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_bin_data_format( uint8_t id, char *buf, size_t sz );

/**
 *  \brief Get "dp" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_dp( uint8_t id, dword *buf );

/**
 *  \brief Get "fw_version" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_fw_version( uint8_t id, char *buf, size_t sz );

/**
 *  \brief Get "i2c_addr" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_i2c_addr( uint8_t id, int *buf );

/**
 *  \brief Get "mode" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_mode( uint8_t id, char *buf, size_t sz );

/**
 *  \brief Set "mode" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_SENSOR_EXT size_t set_sensor_mode( uint8_t id, char *value );

/**
 *  \brief Get "modes" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_modes( uint8_t id, char *buf, size_t sz );

/**
 *  \brief Get "num_values" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_num_values( uint8_t id, dword *buf );

/**
 *  \brief Get "poll_ms" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_poll_ms( uint8_t id, dword *buf );

/**
 *  \brief Set "poll_ms" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_SENSOR_EXT size_t set_sensor_poll_ms( uint8_t id, dword value );

/**
 *  \brief Get "port_name" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_port_name( uint8_t id, char *buf, size_t sz );

/**
 *  \brief Get "units" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_units( uint8_t id, char *buf, size_t sz );

/**
 *  \brief Get "type_id" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_type_id( uint8_t id, dword *buf );

/**
 *  \brief Get "value0" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_value0( uint8_t id, float *buf );

/**
 *  \brief Get "value1" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_value1( uint8_t id, float *buf );

/**
 *  \brief Get "value2" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_value2( uint8_t id, float *buf );

/**
 *  \brief Get "value3" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_value3( uint8_t id, float *buf );

/**
 *  \brief Get "value4" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_value4( uint8_t id, float *buf );

/**
 *  \brief Get "value5" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_value5( uint8_t id, float *buf );

/**
 *  \brief Get "value6" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_value6( uint8_t id, float *buf );

/**
 *  \brief Get "value7" attribute of the sensor.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_value7( uint8_t id, float *buf );

/**
 *  \brief Get "value" attribute of the sensor.
 *  \param inx Attribute index.
 *  \param id Identifier of the sensor.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SENSOR_EXT size_t get_sensor_value( uint8_t inx, uint8_t id, int *buf );

/**
 *  \brief Get the name of the specified sensor type.
 *  \param type_id The sensor type.
 *  \return Name of the sensor type.
 */
EV3_SENSOR_EXT char *ev3_sensor_type( uint8_t type_id );

/**
 *  \brief Search the port of the specified sensor type.
 *  \param type_id The sensor type.
 *  \return EV3 port.
 */
EV3_SENSOR_EXT int ev3_sensor_port( uint8_t type_id );

/**
 *  \brief Get the descriptor of a sensor connected to the specified port.
 *  \param port EV3 port.
 *  \return Pointer to the sensor descriptor.
 */
EV3_SENSOR_EXT EV3_SENSOR *ev3_get_sensor( uint8_t port );

/**
 *  \brief Auto-detection of connected sensors.
 *  \return The number of found sensors or EV3_NONE in case of an error.
 */
EV3_SENSOR_EXT int ev3_sensor_init( void );

/** \} */

#ifdef __cplusplus
}
#endif

#endif

