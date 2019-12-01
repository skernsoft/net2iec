/*
 *
 * (c) by Alexander Neumann <alexander@bumpern.de>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License (either version 2 or
 * version 3) as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * For more information on the GPL, please go to:
 * http://www.gnu.org/copyleft/gpl.html
 */

#ifndef _CONFIG_H
#define _CONFIG_H

/* define these menu choices before including autoconf.h */
#define BMP085_OSS_0 0
#define BMP085_OSS_1 1
#define BMP085_OSS_2 2
#define BMP085_OSS_3 3

#include "autoconf.h"

#if CONFIG_HARDWARE_VARIANT==1
/* Configure for your own hardware                     */


/*** Device address selection ***/
/* DEVICE_SELECT should return the selected device number,   */
/* DEVICE_SELECT_SETUP() is called once to set up the ports. */
#  define DEVICE_SELECT       (15+!(PIND & _BV(PD7))+2*!(PIND & _BV(PD5)))
#  define DEVICE_SELECT_SETUP() do { \
      DDRC  &= ~(_BV(PD7)|_BV(PD5)); \
      PORTD |=   _BV(PD7)|_BV(PD5);  \
   } while (0)


/*** LEDs ***/
/* BUSY led, recommended color: green */
/* R.Riedel - using PORTC instead of the original PORTA here plus inverse polarity */
#  define BUSY_LED_SETDDR() DDRA  |= _BV(PA6)
#  define BUSY_LED_ON()     PORTA |= _BV(PA6)
#  define BUSY_LED_OFF()    PORTA &= ~_BV(PA6)

/* DIRTY led, recommended color: red */
/* R.Riedel - using PORTC instead of the original PORTA here plus inverse polarity */
#  define DIRTY_LED_SETDDR() DDRA  |= _BV(PA7)
#  define DIRTY_LED_ON()     PORTA |= _BV(PA7)
#  define DIRTY_LED_OFF()    PORTA &= ~_BV(PA7)
#  define DIRTY_LED_PORT     PORTA
#  define DIRTY_LED_BIT()    _BV(PA7)

/* Auxiliary LED for debugging */
#  define AUX_LED_SETDDR()   DDRA  |= _BV(PA5)
#  define AUX_LED_ON()       PORTA |= _BV(PA5)
#  define AUX_LED_OFF()      PORTA &= ~_BV(PA5)


/*** IEC signals ***/
/* R.Riedel - using PORTD instead of the original PORTC for the IEC */

#  define IEC_PIN  PIND
#  define IEC_DDR  DDRD
#  define IEC_PORT PORTD

/* Please note that you'll have to change the assembler modules if these */
/* pins aren't defined as Px0-Px3 in this order.                         */
#  define IEC_PIN_ATN   PD2
#  define IEC_PIN_DATA  PD3
#  define IEC_PIN_CLOCK PD4
#  define IEC_PIN_SRQ   PD5


/*** User interface ***/
/* Disk image change key  nicht nötig*/
#  define DISKCHANGE_PIN  PINC
#  define DISKCHANGE_DDR  DDRC
#  define DISKCHANGE_PORT PORTC
#  define DISKCHANGE_BIT  _BV(PC4)
/* Target value of the debounce counter */
#  define DISKCHANGE_MAX  128



/* Pre-configurated hardware variants */

#else
#  error "CONFIG_HARDWARE_VARIANT is unset or set to an unknown value."
#endif

#define IEC_BIT_ATN      _BV(IEC_PIN_ATN)
#define IEC_BIT_DATA     _BV(IEC_PIN_DATA)
#define IEC_BIT_CLOCK    _BV(IEC_PIN_CLOCK)
#define IEC_BIT_SRQ      _BV(IEC_PIN_SRQ)

#ifdef IEC_SEPARATE_OUT
#  define IEC_PULLUPS    (IEC_BIT_ATN | IEC_BIT_DATA | IEC_BIT_CLOCK | IEC_BIT_SRQ)
#  define IEC_OBIT_ATN   _BV(IEC_OPIN_ATN)
#  define IEC_OBIT_DATA  _BV(IEC_OPIN_DATA)
#  define IEC_OBIT_CLOCK _BV(IEC_OPIN_CLOCK)
#  define IEC_OBIT_SRQ   _BV(IEC_OPIN_SRQ)
#  define IEC_OUT        IEC_PORT
#else
#  define IEC_PULLUPS    0
#  define IEC_OPIN_ATN   IEC_PIN_ATN
#  define IEC_OPIN_DATA  IEC_PIN_DATA
#  define IEC_OPIN_CLOCK IEC_PIN_CLOCK
#  define IEC_OPIN_SRQ   IEC_PIN_SRQ
#  define IEC_OBIT_ATN   IEC_BIT_ATN
#  define IEC_OBIT_DATA  IEC_BIT_DATA
#  define IEC_OBIT_CLOCK IEC_BIT_CLOCK
#  define IEC_OBIT_SRQ   IEC_BIT_SRQ
#  define IEC_OUT        IEC_DDR
#endif

/* ---------------- End of user-configurable options ---------------- */

/* Disable COMMAND_CHANNEL_DUMP if UART_DEBUG is disabled */
#ifndef CONFIG_UART_DEBUG
#  undef CONFIG_COMMAND_CHANNEL_DUMP
#endif








/* network controller hardware bug defines */
#define ENC28J60_REV4_WORKAROUND
#define ENC28J60_REV5_WORKAROUND
#define ENC28J60_REV6_WORKAROUND  /* rev is 6; but microchip calls it B7 */

/* configure duplex mode */
#define NET_FULL_DUPLEX 0

/* configure main callback function for uip */
#define UIP_APPCALL if (uip_conn->callback != NULL) uip_conn->callback
#define UIP_UDP_APPCALL if (uip_udp_conn->callback) uip_udp_conn->callback

/* onewire support */
#define ONEWIRE_PARASITE

/* rc5 support */
#define RC5_QUEUE_LENGTH 10

/* rfm12 config */
#define RFM12_FREQ_433920	433920
#define RFM12_FREQ_868300	868300
#define RFM12_FREQ_869775	869775
#define RFM12_FREQ_869800	869800
#define RFM12_FREQ_869825	869825
#define RFM12_FREQ_869850	869850
#define RFM12_FREQ_869875	869875
#define RFM12_FREQ_869900	869900
#define RFM12_FREQ_869925	869925

#define ARCH_AVR	1
#define ARCH_HOST	2

#if ARCH == ARCH_HOST
#include "core/host/host.h"
#endif

/* Include pinning.c as output of m4 scripts in pinning sub-directory.
   Have a look there for MCU specific configuration options. */
#include "pinning.c"

/* use watchdog only when not debugging */
#ifndef DEBUG
#   define USE_WATCHDOG
#endif

/* macros */
#ifdef USE_WATCHDOG
#   define wdt_kick() wdt_reset()
#else
#   define wdt_kick()
#endif


/* Map the IP address configuration to use in network.c
   (and that is assigned to the primary stack). */

// ENC28J60_SUPPORT
#  define set_CONF_ETHERSEX_MAC(ip)		set_CONF_ENC_MAC(ip)
#  define set_CONF_ETHERSEX_IP(ip)		set_CONF_ENC_IP(ip)
#  define set_CONF_ETHERSEX_IP4_NETMASK(ip)	set_CONF_ENC_IP4_NETMASK(ip)
#  define CONF_ETHERSEX_MAC			CONF_ENC_MAC

/* ADC Reference Flags */
#define ADC_AREF	0
#define ADC_AVCC	0x40
#define ADC_1_1	    0x80
#define ADC_2_56    0xC0

/* Figure out whether we need access to EEPROM:

   - ECMD without TEENSY (IP address configuration etc.)
   - BOOTP with to-EEPROM-feature
   - STELLA with eeprom load/write support */
#if (defined(ECMD_PARSER_SUPPORT) && !defined(TEENSY_SUPPORT))   || \
    (defined(BOOTP_SUPPORT) && defined(BOOTP_TO_EEPROM_SUPPORT)) || \
    (defined(STELLA_SUPPORT) && !defined(TEENSY_SUPPORT))        || \
    defined(JABBER_EEPROM_SUPPORT)
#  define EEPROM_SUPPORT 1
#endif


/* Figure out whether we need CRC_SUPPORT: */
#if defined(EEPROM_SUPPORT)     || \
    defined(ONEWIRE_SUPPORT)    || \
    defined(VFS_INLINE_SUPPORT) || \
    defined(TFTP_SUPPORT)
#  define CRC_SUPPORT 1
#endif

#if defined(VFS_SUPPORT)             && \
    defined(VFS_INLINE_SUPPORT)	     && \
    !defined(VFS_SD_SUPPORT)         && \
    !defined(VFS_DF_SUPPORT)         && \
    !defined(VFS_EEPROM_SUPPORT)     && \
    !defined(VFS_EEPROM_RAW_SUPPORT) && \
    !defined(VFS_DC3840_SUPPORT)
#  define VFS_TEENSY 1
#endif



#endif /* _CONFIG_H */
