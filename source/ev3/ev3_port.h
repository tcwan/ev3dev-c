
/*  ev3_port.h was generated by yup.py (yupp) 0.8b2
    out of ev3_port.yu-h at 2015-04-27 16:53
 *//**
 *  \file  ev3_port.h (ev3_port.yu-h)
 *  \brief  EV3 Ports.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef EV3_PORT_H
#define EV3_PORT_H

#ifdef  EV3_PORT_IMPLEMENT
#define EV3_PORT_EXT
#define EV3_PORT_EXT_INIT( dec, init ) \
	dec = init
#else
#define EV3_PORT_EXT extern
#define EV3_PORT_EXT_INIT( dec, init ) \
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
 *  \defgroup ev3_port EV3 Ports and Extended Ports
 *  \brief Access to EV3 Ports and Extended Ports.
 *  \see http://www.ev3dev.org/docs/ports/
 *  \see http://www.ev3dev.org/docs/drivers/lego-port-class/
 *  \{
 */

#define PORT_DIR  "/sys/class/lego-port"  /**< Directory of EV3 ports. */

/**
 *  \brief Structure of a EV3 port descriptor.
 */
typedef struct {
	uint8_t type_inx;  /**< EV3 port type. */
	uint8_t port;  /**< EV3 port EV3 port. */
	uint8_t extport;  /**< EV3 port extended port. */

} EV3_PORT;

#define PORT_DESC__LIMIT_  64  /**< Limit of EV3 port descriptors. */

#define PORT__NONE_  PORT_DESC__LIMIT_  /**< EV3 port is not found. */

/**
 *  \brief Vector of EV3 port descriptors (filled by \ref ev3_port_init).
 */
EV3_PORT_EXT EV3_PORT ev3_port[ PORT_DESC__LIMIT_ ];

/**
 *  \brief Identifiers of EV3 port types.
 */
enum {
	PORT_TYPE__NONE_ = 0,  /* XXX: memset( 0 ) is used */

	HT_NXT_SMUX_PORT,
	LEGOEV3_INPUT_PORT,
	LEGOEV3_OUTPUT_PORT,
	MS_EV3_SMUX_PORT,
	WEDO_PORT,

	PORT_TYPE__COUNT_,  /**< Count of EV3 port types. */
	PORT_TYPE__UNKNOWN_ = PORT_TYPE__COUNT_
};

/**
 *  \brief Identifiers of EV3 port modes.
 */
enum {
	PORT_MODE__NONE_ = 0,

	HT_NXT_SMUX_PORT_ANALOG,
	HT_NXT_SMUX_PORT_I2C,

	LEGOEV3_INPUT_PORT_AUTO,
	LEGOEV3_INPUT_PORT_NXT_ANALOG,
	LEGOEV3_INPUT_PORT_NXT_COLOR,
	LEGOEV3_INPUT_PORT_NXT_I2C,
	LEGOEV3_INPUT_PORT_EV3_ANALOG,
	LEGOEV3_INPUT_PORT_EV3_UART,
	LEGOEV3_INPUT_PORT_OTHER_UART,
	LEGOEV3_INPUT_PORT_RAW,

	LEGOEV3_OUTPUT_PORT_AUTO,
	LEGOEV3_OUTPUT_PORT_EV3_TACHO_MOTOR,
	LEGOEV3_OUTPUT_PORT_RCX_MOTOR,
	LEGOEV3_OUTPUT_PORT_RCX_LED,
	LEGOEV3_OUTPUT_PORT_RAW,

	MS_EV3_SMUX_PORT_UART,
	MS_EV3_SMUX_PORT_ANALOG,

	WEDO_PORT_AUTO,

	PORT_MODE__COUNT_,  /**< Count of EV3 port modes. */
	PORT_MODE__UNKNOWN_ = PORT_MODE__COUNT_
};

/**
 *  \brief Get "driver_name" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_PORT_EXT size_t get_port_driver_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "mode" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_PORT_EXT size_t get_port_mode( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Set "mode" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_PORT_EXT size_t set_port_mode( uint8_t sn, char *value );

/**
 *  \brief Get "modes" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_PORT_EXT size_t get_port_modes( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get "port_name" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_PORT_EXT size_t get_port_port_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Set "set_device" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
EV3_PORT_EXT size_t set_port_set_device( uint8_t sn, char *value );

/**
 *  \brief Get "status" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
EV3_PORT_EXT size_t get_port_status( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get name of the specified EV3 port type.
 *  \param type_inx Index of the EV3 port type.
 *  \return Requested value.
 */
EV3_PORT_EXT const char *ev3_port_type( uint8_t type_inx );

/**
 *  \brief Get index of the EV3 port type.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_PORT_EXT uint8_t get_port_type_inx( uint8_t sn );

/**
 *  \brief Get indexes of the EV3 port and the extended port of the EV3 port.
 *  \param sn Sequence number.
 *  \param port_type_inx Port type.
 *  \param extport Buffer for the extended port index.
 *  \return EV3 port index.
 */
EV3_PORT_EXT uint8_t get_port_port_inx( uint8_t sn, uint8_t port_type_inx, uint8_t *extport );

/**
 *  \brief Get descriptor of the EV3 port.
 *  \param sn Sequence number.
 *  \return Pointer to the EV3 port descriptor.
 */
EV3_PORT_EXT EV3_PORT *ev3_port_desc( uint8_t sn );

/**
 *  \brief Get type from the EV3 port descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_PORT_EXT uint8_t ev3_port_desc_type_inx( uint8_t sn );
/**
 *  \brief Get EV3 port from the EV3 port descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_PORT_EXT uint8_t ev3_port_desc_port( uint8_t sn );
/**
 *  \brief Get extended port from the EV3 port descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
EV3_PORT_EXT uint8_t ev3_port_desc_extport( uint8_t sn );

/**
 *  \brief Search of a sequence number of the specified EV3 port type.
 *  \param type_inx The EV3 port type.
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the EV3 port is found.
 */
EV3_PORT_EXT bool ev3_search_port_type( uint8_t type_inx, uint8_t *sn, uint8_t from );

/**
 *  \brief Search of a sequence number the EV3 port by plug-in attributes.
 *  \param port EV3 port.
 *  \param extport Extended port.
 
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the EV3 port is found.
 */
EV3_PORT_EXT bool ev3_search_port_plugged_in( uint8_t port, uint8_t extport, uint8_t *sn, uint8_t from );

/**
 *  \brief Get name of the specified EV3 port mode.
 *  \param mode_inx Index of the EV3 port mode.
 *  \return Requested value.
 */
EV3_PORT_EXT const char *ev3_port_mode( uint8_t mode_inx );

/**
 *  \brief Get index of the EV3 port mode.
 *  \param sn Sequence number.
 *  \param type_inx Index of the EV3 port type.
 *  \return Requested value.
 */
EV3_PORT_EXT uint8_t get_port_mode_inx( uint8_t sn, uint8_t type_inx );

/**
 *  \brief Set mode of the EV3 port by index.
 *  \param sn Sequence number.
 *  \param mode_inx Index of the EV3 port mode.
 *  \return Count of written bytes.
 */
EV3_PORT_EXT size_t set_port_mode_inx( uint8_t sn, uint8_t mode_inx );

/**
 *  \brief Detect connected EV3 ports.
 *  \return The number of found EV3 ports or -1 in case of an error.
 */
EV3_PORT_EXT int ev3_port_init( void );

/**
 *  \brief Identifiers of EV3 ports and extended ports.
 */
enum {
	EV3_PORT__NONE_ = 0,  /* XXX: memset( 0 ) is used */
	EXT_PORT__NONE_ = EV3_PORT__NONE_,

	HT_NXT_SMUX_PORT__BASE_,
					
	HT_NXT_SMUX_PORT_1 = HT_NXT_SMUX_PORT__BASE_ + 0,
			
	HT_NXT_SMUX_PORT_2 = HT_NXT_SMUX_PORT__BASE_ + 1,
			
	HT_NXT_SMUX_PORT_3 = HT_NXT_SMUX_PORT__BASE_ + 2,
			
	HT_NXT_SMUX_PORT_4 = HT_NXT_SMUX_PORT__BASE_ + 3,
			
	LEGOEV3_INPUT_PORT__BASE_,
					
	LEGOEV3_INPUT_PORT_1 = LEGOEV3_INPUT_PORT__BASE_ + 0,
	INPUT_1 = LEGOEV3_INPUT_PORT_1,
			
	LEGOEV3_INPUT_PORT_2 = LEGOEV3_INPUT_PORT__BASE_ + 1,
	INPUT_2 = LEGOEV3_INPUT_PORT_2,
			
	LEGOEV3_INPUT_PORT_3 = LEGOEV3_INPUT_PORT__BASE_ + 2,
	INPUT_3 = LEGOEV3_INPUT_PORT_3,
			
	LEGOEV3_INPUT_PORT_4 = LEGOEV3_INPUT_PORT__BASE_ + 3,
	INPUT_4 = LEGOEV3_INPUT_PORT_4,

	LEGOEV3_OUTPUT_PORT__BASE_,
					
	LEGOEV3_OUTPUT_PORT_A = LEGOEV3_OUTPUT_PORT__BASE_ + 0,
	OUTPUT_A = LEGOEV3_OUTPUT_PORT_A,
			
	LEGOEV3_OUTPUT_PORT_B = LEGOEV3_OUTPUT_PORT__BASE_ + 1,
	OUTPUT_B = LEGOEV3_OUTPUT_PORT_B,
			
	LEGOEV3_OUTPUT_PORT_C = LEGOEV3_OUTPUT_PORT__BASE_ + 2,
	OUTPUT_C = LEGOEV3_OUTPUT_PORT_C,
			
	LEGOEV3_OUTPUT_PORT_D = LEGOEV3_OUTPUT_PORT__BASE_ + 3,
	OUTPUT_D = LEGOEV3_OUTPUT_PORT_D,

	MS_EV3_SMUX_PORT__BASE_,
					
	MS_EV3_SMUX_PORT_1 = MS_EV3_SMUX_PORT__BASE_ + 0,
			
	MS_EV3_SMUX_PORT_2 = MS_EV3_SMUX_PORT__BASE_ + 1,
			
	MS_EV3_SMUX_PORT_3 = MS_EV3_SMUX_PORT__BASE_ + 2,
			
	MS_EV3_SMUX_PORT_4 = MS_EV3_SMUX_PORT__BASE_ + 3,
			
	WEDO_PORT__BASE_,
					
	WEDO_PORT_1 = WEDO_PORT__BASE_ + 0,
			
	WEDO_PORT_2 = WEDO_PORT__BASE_ + 1,
			
	WEDO_PORT_3 = WEDO_PORT__BASE_ + 2,
			
	WEDO_PORT_4 = WEDO_PORT__BASE_ + 3,
			
};

#define INPUT_AUTO  LEGOEV3_INPUT_PORT_AUTO
#define INPUT_NXT_ANALOG  LEGOEV3_INPUT_PORT_NXT_ANALOG
#define INPUT_NXT_COLOR  LEGOEV3_INPUT_PORT_NXT_COLOR
#define INPUT_NXT_I2C  LEGOEV3_INPUT_PORT_NXT_I2C
#define INPUT_EV3_ANALOG  LEGOEV3_INPUT_PORT_EV3_ANALOG
#define INPUT_EV3_UART  LEGOEV3_INPUT_PORT_EV3_UART
#define INPUT_OTHER_UART  LEGOEV3_INPUT_PORT_OTHER_UART
#define INPUT_RAW  LEGOEV3_INPUT_PORT_RAW

#define OUTPUT_AUTO  LEGOEV3_OUTPUT_PORT_AUTO
#define OUTPUT_EV3_TACHO_MOTOR  LEGOEV3_OUTPUT_PORT_EV3_TACHO_MOTOR
#define OUTPUT_RCX_MOTOR  LEGOEV3_OUTPUT_PORT_RCX_MOTOR
#define OUTPUT_RCX_LED  LEGOEV3_OUTPUT_PORT_RCX_LED
#define OUTPUT_RAW  LEGOEV3_OUTPUT_PORT_RAW

/**
 *  \brief Count of ht-nxt-smux-ports.
 */
#define HT_NXT_SMUX_PORT__COUNT_  4

/**
 *  \brief Count of legoev3-input-ports.
 */
#define LEGOEV3_INPUT_PORT__COUNT_  4

/**
 *  \brief Count of legoev3-output-ports.
 */
#define LEGOEV3_OUTPUT_PORT__COUNT_  4

/**
 *  \brief Count of ms-ev3-smux-ports.
 */
#define MS_EV3_SMUX_PORT__COUNT_  4

/**
 *  \brief Count of wedo-ports.
 */
#define WEDO_PORT__COUNT_  4

/**
 *  \brief Search of a port sequence number by the EV3 port and the extended port.
 *  \param port EV3 port.
 *  \param extport Extended port.
 *  \return Port sequence number.
 */
EV3_PORT_EXT uint8_t ev3_search_port( uint8_t port, uint8_t extport );

/**
 *  \brief Get indexes of the EV3 port and the extended port from the port name.
 *  \param name Port name.
 *  \param type_inx Port type.
 *  \param extport Buffer for the extended port index.
 *  \return EV3 port index.
 */
EV3_PORT_EXT uint8_t ev3_port_inx( uint8_t type_inx, const char *name, uint8_t *extport );

/**
 *  \brief Get name of the specified port.
 *  \param port EV3 port index.
 *  \param extport Extended port index.
 *  \return Requested value.
 */
EV3_PORT_EXT const char *ev3_port_name( uint8_t port, uint8_t extport );

/** \} */

#ifdef __cplusplus
}
#endif

#endif

