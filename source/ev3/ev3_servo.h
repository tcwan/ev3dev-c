
/*  ev3_servo.h was generated by yup.py (yupp) 0.7b7
    out of ev3_servo.yu-h at 2014-11-14 18:11
 *//**
 *  \file  ev3_servo.h (ev3_servo.yu-h)
 *  \brief  EV3 Servo Motors.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef EV3_SERVO_H
#define EV3_SERVO_H

#ifdef  EV3_SERVO_IMPLEMENT
#define EV3_SERVO_EXT
#define EV3_SERVO_EXT_INIT( dec, init ) \
	dec = init
#else
#define EV3_SERVO_EXT extern
#define EV3_SERVO_EXT_INIT( dec, init ) \
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
 *  \defgroup ev3_servo Servo Motors
 *  \brief Access to EV3 Servo Motors.
 *  \see http://www.ev3dev.org/docs/drivers/servo-motor-class/
 *  \{
 */

#define SERVO_DIR  "/sys/class/servo-motor"  /**< Directory of servo motors. */

/**
 *  \brief Structure of a servo motor descriptor.
 */
typedef struct {
	uint8_t type_inx;  /**< Servo motor type. */
	uint8_t port;  /**< Servo motor EV3 port. */
	uint8_t extport;  /**< Servo motor extended port. */
	uint8_t addr;  /**< Servo motor channel. */

} EV3_SERVO;

#define SERVO_DESC__LIMIT_  64  /**< Limit of servo motor descriptors. */

#define SERVO__NONE_  SERVO_DESC__LIMIT_  /**< Servo motor is not found. */

/**
 *  \brief Vector of servo motor descriptors (filled by \ref ev3_servo_init).
 */
EV3_SERVO_EXT EV3_SERVO ev3_servo[ SERVO_DESC__LIMIT_ ];

/**
 *  \brief Types of servo motors.
 */
enum {
	SERVO_TYPE__NONE_ = 0,

	SERVO_MOTOR,

	SERVO_TYPE__COUNT_
};

/**
 *  \brief Get "command" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_command( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Set "command" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_command( uint8_t sn, char *value );

/**
 *  \brief Get "max_pulse_ms" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_max_pulse_ms( uint8_t sn, dword *buf );

/**
 *  \brief Set "max_pulse_ms" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_max_pulse_ms( uint8_t sn, dword value );

/**
 *  \brief Get "mid_pulse_ms" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_mid_pulse_ms( uint8_t sn, dword *buf );

/**
 *  \brief Set "mid_pulse_ms" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_mid_pulse_ms( uint8_t sn, dword value );

/**
 *  \brief Get "min_pulse_ms" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_min_pulse_ms( uint8_t sn, dword *buf );

/**
 *  \brief Set "min_pulse_ms" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_min_pulse_ms( uint8_t sn, dword value );

/**
 *  \brief Get "name" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "polarity" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_polarity( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Set "polarity" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_polarity( uint8_t sn, char *value );

/**
 *  \brief Get "port_name" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_port_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "position" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_position( uint8_t sn, int *buf );

/**
 *  \brief Set "position" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_position( uint8_t sn, int value );

/**
 *  \brief Get "rate" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.

 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_rate( uint8_t sn, dword *buf );

/**
 *  \brief Set "rate" attribute of the servo motor.
 *  \param sn Sequence number.
 *  \param value Attribute value.

 *  \return Count of written bytes.
 */
EV3_SERVO_EXT size_t set_servo_rate( uint8_t sn, dword value );

/**
 *  \brief Get name of the specified servo motor type.
 *  \param type_inx The servo motor type.
 *  \return Requested value.
 */
EV3_SERVO_EXT const char *ev3_servo_type( uint8_t type_inx );

/**
 *  \brief Get index of the servo motor type.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT uint8_t get_servo_type_inx( uint8_t sn );

/**
 *  \brief Get indexes of the EV3 port and the extended port of the servo motor.
 *  \param sn Sequence number.
 *  \param extport Buffer for the extended port index.
 *  \return EV3 port index.
 */
EV3_SERVO_EXT uint8_t get_servo_port_inx( uint8_t sn, uint8_t *extport );

/**
 *  \brief Get descriptor of the servo motor.
 *  \param sn Sequence number.
 *  \return Pointer to the servo motor descriptor.
 */
EV3_SERVO_EXT EV3_SERVO *ev3_servo_desc( uint8_t sn );

/**
 *  \brief Get type from the servo motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT uint8_t ev3_servo_desc_type_inx( uint8_t sn );
/**
 *  \brief Get EV3 port from the servo motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT uint8_t ev3_servo_desc_port( uint8_t sn );
/**
 *  \brief Get extended port from the servo motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT uint8_t ev3_servo_desc_extport( uint8_t sn );
/**
 *  \brief Get channel from the servo motor descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_SERVO_EXT uint8_t ev3_servo_desc_addr( uint8_t sn );

/**
 *  \brief Search of the specified servo motor type.
 *  \param type_inx The servo motor type.
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the servo motor is found.
 */
EV3_SERVO_EXT bool ev3_search_servo( uint8_t type_inx, uint8_t *sn, uint8_t from );

/**
 *  \brief Search of the servo motor by plug-in attributes.
 *  \param port EV3 port.
 *  \param extport Extended port.
 *  \param addr Address.
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the servo motor is found.
 */
EV3_SERVO_EXT bool ev3_search_servo_plugged_in( uint8_t port, uint8_t extport, uint8_t addr, uint8_t *sn, uint8_t from );

/**
 *  \brief Detect connected servo motors.
 *  \return The number of found servo motors or -1 in case of an error.
 */
EV3_SERVO_EXT int ev3_servo_init( void );

/**
 *  \brief Get the channel of the servo motor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \return Count of read bytes.
 */
EV3_SERVO_EXT size_t get_servo_address( uint8_t sn, uint8_t *buf );

/**
 *  \brief Get name of the specified servo motor port.
 *  \param port Port index.
 *  \param extport Extended port index.
 *  \param addr Servo motor channel.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 */
EV3_SERVO_EXT void ev3_servo_port_name( uint8_t port, uint8_t extport, uint8_t addr, char *buf, size_t sz );

/** \} */

#ifdef __cplusplus
}
#endif

#endif

