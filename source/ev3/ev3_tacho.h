
/*  ev3_tacho.h was generated by yup.py (yupp) 0.8b2
    out of ev3_tacho.yu-h at 2015-04-27 16:59
 *//**
 *  \file  ev3_tacho.h (ev3_tacho.yu-h)
 *  \brief  EV3 Tacho Motors.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef EV3_TACHO_H
#define EV3_TACHO_H

#ifdef  EV3_TACHO_IMPLEMENT
#define EV3_TACHO_EXT
#define EV3_TACHO_EXT_INIT( dec, init ) \
	dec = init
#else
#define EV3_TACHO_EXT extern
#define EV3_TACHO_EXT_INIT( dec, init ) \
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
 *  \defgroup ev3_tacho Tacho Motors
 *  \brief Access to EV3 Tacho Motors.
 *  \see http://www.ev3dev.org/docs/motors/
 *  \see http://www.ev3dev.org/docs/drivers/tacho-motor-class/
 *  \{
 */

#define TACHO_DIR  "/sys/class/tacho-motor"  /**< Directory of tachos. */

/**
 *  \brief Structure of a tacho descriptor.
 */
typedef struct {
	uint8_t type_inx;  /**< Tacho type. */
	uint8_t port;  /**< Tacho EV3 port. */
	uint8_t extport;  /**< Tacho extended port. */

} EV3_TACHO;

#define TACHO_DESC__LIMIT_  64  /**< Limit of tacho descriptors. */

#define TACHO__NONE_  TACHO_DESC__LIMIT_  /**< Tacho is not found. */

/**
 *  \brief Vector of tacho descriptors (filled by \ref ev3_tacho_init).
 */
EV3_TACHO_EXT EV3_TACHO ev3_tacho[ TACHO_DESC__LIMIT_ ];

/**
 *  \brief Identifiers of tacho types.
 */
enum {
	TACHO_TYPE__NONE_ = 0,  /* XXX: memset( 0 ) is used */

	LEGO_EV3_L_MOTOR,
	LEGO_EV3_M_MOTOR,
	FI_L12_EV3,

	TACHO_TYPE__COUNT_,  /**< Count of tacho types. */
	TACHO_TYPE__UNKNOWN_ = TACHO_TYPE__COUNT_
};

/**
 *  \brief Identifiers of tacho commands.
 */
enum {
	TACHO_COMMAND__NONE_ = 0,

	LEGO_EV3_L_MOTOR_RUN_FOREVER,
	LEGO_EV3_L_MOTOR_RUN_TO_ABS_POS,
	LEGO_EV3_L_MOTOR_RUN_TO_REL_POS,
	LEGO_EV3_L_MOTOR_RUN_TIMED,
	LEGO_EV3_L_MOTOR_RUN_DIRECT,
	LEGO_EV3_L_MOTOR_STOP,
	LEGO_EV3_L_MOTOR_RESET,

	LEGO_EV3_M_MOTOR_RUN_FOREVER,
	LEGO_EV3_M_MOTOR_RUN_TO_ABS_POS,
	LEGO_EV3_M_MOTOR_RUN_TO_REL_POS,
	LEGO_EV3_M_MOTOR_RUN_TIMED,
	LEGO_EV3_M_MOTOR_RUN_DIRECT,
	LEGO_EV3_M_MOTOR_STOP,
	LEGO_EV3_M_MOTOR_RESET,

	FI_L12_EV3_RUN_FOREVER,
	FI_L12_EV3_RUN_TO_ABS_POS,
	FI_L12_EV3_RUN_TO_REL_POS,
	FI_L12_EV3_RUN_TIMED,
	FI_L12_EV3_RUN_DIRECT,
	FI_L12_EV3_STOP,
	FI_L12_EV3_RESET,

	TACHO_COMMAND__COUNT_,  /**< Count of tacho commands. */
	TACHO_COMMAND__UNKNOWN_ = TACHO_COMMAND__COUNT_
};

/**
 *  \brief Identifiers of tacho stop_commands.
 */
enum {
	TACHO_STOP_COMMAND__NONE_ = 0,

	LEGO_EV3_L_MOTOR_COAST,
	LEGO_EV3_L_MOTOR_BRAKE,
	LEGO_EV3_L_MOTOR_HOLD,

	LEGO_EV3_M_MOTOR_COAST,
	LEGO_EV3_M_MOTOR_BRAKE,
	LEGO_EV3_M_MOTOR_HOLD,

	FI_L12_EV3_COAST,
	FI_L12_EV3_BRAKE,
	FI_L12_EV3_HOLD,

	TACHO_STOP_COMMAND__COUNT_,  /**< Count of tacho stop_commands. */
	TACHO_STOP_COMMAND__UNKNOWN_ = TACHO_STOP_COMMAND__COUNT_
};

/**
 *  \brief Set "command" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_command( uint8_t sn, char *value );

/**
 *  \brief Get "commands" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_commands( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "count_per_rot" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_count_per_rot( uint8_t sn, int *buf );

/**
 *  \brief Get "driver_name" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_driver_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "duty_cycle" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_duty_cycle( uint8_t sn, int *buf );

/**
 *  \brief Get "duty_cycle_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_duty_cycle_sp( uint8_t sn, int *buf );

/**
 *  \brief Set "duty_cycle_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_duty_cycle_sp( uint8_t sn, int value );

/**
 *  \brief Get "encoder_polarity" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_encoder_polarity( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Set "encoder_polarity" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_encoder_polarity( uint8_t sn, char *value );

/**
 *  \brief Get "hold_pid/Kd" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_hold_pid_Kd( uint8_t sn, int *buf );

/**
 *  \brief Set "hold_pid/Kd" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_hold_pid_Kd( uint8_t sn, int value );

/**
 *  \brief Get "hold_pid/Ki" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_hold_pid_Ki( uint8_t sn, int *buf );

/**
 *  \brief Set "hold_pid/Ki" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_hold_pid_Ki( uint8_t sn, int value );

/**
 *  \brief Get "hold_pid/Kp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_hold_pid_Kp( uint8_t sn, int *buf );

/**
 *  \brief Set "hold_pid/Kp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_hold_pid_Kp( uint8_t sn, int value );

/**
 *  \brief Get "polarity" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_polarity( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Set "polarity" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_polarity( uint8_t sn, char *value );

/**
 *  \brief Get "port_name" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_port_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "position" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_position( uint8_t sn, int *buf );

/**
 *  \brief Set "position" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_position( uint8_t sn, int value );

/**
 *  \brief Get "position_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_position_sp( uint8_t sn, int *buf );

/**
 *  \brief Set "position_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_position_sp( uint8_t sn, int value );

/**
 *  \brief Get "ramp_down_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_ramp_down_sp( uint8_t sn, int *buf );

/**
 *  \brief Set "ramp_down_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_ramp_down_sp( uint8_t sn, int value );

/**
 *  \brief Get "ramp_up_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_ramp_up_sp( uint8_t sn, int *buf );

/**
 *  \brief Set "ramp_up_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_ramp_up_sp( uint8_t sn, int value );

/**
 *  \brief Get "speed" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_speed( uint8_t sn, int *buf );

/**
 *  \brief Get "speed_pid/Kd" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_speed_pid_Kd( uint8_t sn, int *buf );

/**
 *  \brief Set "speed_pid/Kd" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_speed_pid_Kd( uint8_t sn, int value );

/**
 *  \brief Get "speed_pid/Ki" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_speed_pid_Ki( uint8_t sn, int *buf );

/**
 *  \brief Set "speed_pid/Ki" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_speed_pid_Ki( uint8_t sn, int value );

/**
 *  \brief Get "speed_pid/Kp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_speed_pid_Kp( uint8_t sn, int *buf );

/**
 *  \brief Set "speed_pid/Kp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_speed_pid_Kp( uint8_t sn, int value );

/**
 *  \brief Get "speed_regulation" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_speed_regulation( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Set "speed_regulation" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_speed_regulation( uint8_t sn, char *value );

/**
 *  \brief Get "speed_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_speed_sp( uint8_t sn, int *buf );

/**
 *  \brief Set "speed_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_speed_sp( uint8_t sn, int value );

/**
 *  \brief Get "state" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_state( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "stop_command" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_stop_command( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Set "stop_command" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_stop_command( uint8_t sn, char *value );

/**
 *  \brief Get "stop_commands" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_stop_commands( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "time_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
		 
 *  \return Count of read bytes.
 */
EV3_TACHO_EXT size_t get_tacho_time_sp( uint8_t sn, int *buf );

/**
 *  \brief Set "time_sp" attribute of the tacho.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_time_sp( uint8_t sn, int value );

/**
 *  \brief Get name of the specified tacho type.
 *  \param type_inx Index of the tacho type.
 *  \return Requested value.
 */
EV3_TACHO_EXT const char *ev3_tacho_type( uint8_t type_inx );

/**
 *  \brief Get index of the tacho type.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_TACHO_EXT uint8_t get_tacho_type_inx( uint8_t sn );

/**
 *  \brief Get indexes of the EV3 port and the extended port of the tacho.
 *  \param sn Sequence number.
 *  \param port_type_inx Port type.
 *  \param extport Buffer for the extended port index.
 *  \return EV3 port index.
 */
EV3_TACHO_EXT uint8_t get_tacho_port_inx( uint8_t sn, uint8_t port_type_inx, uint8_t *extport );

/**
 *  \brief Get descriptor of the tacho.
 *  \param sn Sequence number.
 *  \return Pointer to the tacho descriptor.
 */
EV3_TACHO_EXT EV3_TACHO *ev3_tacho_desc( uint8_t sn );

/**
 *  \brief Get type from the tacho descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_TACHO_EXT uint8_t ev3_tacho_desc_type_inx( uint8_t sn );
/**
 *  \brief Get EV3 port from the tacho descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_TACHO_EXT uint8_t ev3_tacho_desc_port( uint8_t sn );
/**
 *  \brief Get extended port from the tacho descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_TACHO_EXT uint8_t ev3_tacho_desc_extport( uint8_t sn );

/**
 *  \brief Search of a sequence number of the specified tacho type.
 *  \param type_inx The tacho type.
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the tacho is found.
 */
EV3_TACHO_EXT bool ev3_search_tacho( uint8_t type_inx, uint8_t *sn, uint8_t from );

/**
 *  \brief Search of a sequence number the tacho by plug-in attributes.
 *  \param port EV3 port.
 *  \param extport Extended port.
 
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the tacho is found.
 */
EV3_TACHO_EXT bool ev3_search_tacho_plugged_in( uint8_t port, uint8_t extport, uint8_t *sn, uint8_t from );

/**
 *  \brief Get name of the specified tacho command.
 *  \param command_inx Index of the tacho command.
 *  \return Requested value.
 */
EV3_TACHO_EXT const char *ev3_tacho_command( uint8_t command_inx );

/**
 *  \brief Set command of the tacho by index.
 *  \param sn Sequence number.
 *  \param command_inx Index of the tacho command.
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_command_inx( uint8_t sn, uint8_t command_inx );

/**
 *  \brief Get name of the specified tacho stop_command.
 *  \param stop_command_inx Index of the tacho stop_command.
 *  \return Requested value.
 */
EV3_TACHO_EXT const char *ev3_tacho_stop_command( uint8_t stop_command_inx );

/**
 *  \brief Get index of the tacho stop_command.
 *  \param sn Sequence number.
 *  \param type_inx Index of the tacho type.
 *  \return Requested value.
 */
EV3_TACHO_EXT uint8_t get_tacho_stop_command_inx( uint8_t sn, uint8_t type_inx );

/**
 *  \brief Set stop_command of the tacho by index.
 *  \param sn Sequence number.
 *  \param stop_command_inx Index of the tacho stop_command.
 *  \return Count of written bytes.
 */
EV3_TACHO_EXT size_t set_tacho_stop_command_inx( uint8_t sn, uint8_t stop_command_inx );

/**
 *  \brief Detect connected tachos.
 *  \return The number of found tachos or -1 in case of an error.
 */
EV3_TACHO_EXT int ev3_tacho_init( void );

/**
 *  \brief Common identifiers of tacho commands.
 */
enum {
	TACHO_COMMAND__NULL_ = 0,

	TACHO_RUN_FOREVER,
	TACHO_RUN_TO_ABS_POS,
	TACHO_RUN_TO_REL_POS,
	TACHO_RUN_TIMED,
	TACHO_RUN_DIRECT,
	TACHO_STOP,
	TACHO_RESET,

};

/**
 *  \brief Common identifiers of tacho stop commands.
 */
enum {
	TACHO_STOP_COMMAND__NULL_ = 0,

	TACHO_COAST,
	TACHO_BRAKE,
	TACHO_HOLD,

};

/** \} */

#ifdef __cplusplus
}
#endif

#endif

