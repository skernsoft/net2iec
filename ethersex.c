/*
 * Copyright (c) by Alexander Neumann <alexander@bumpern.de>
 * Copyright (c) 2007 by Stefan Siegl <stesie@brokenpipe.de>
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

#include "config.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <stdlib.h>

#include "protocols/uip/uip.h"
#include "protocols/uip/uip_neighbor.h"

#include "core/global.h"
#include "core/debug.h"
#include "core/spi.h"
#include "core/mbr.h"
#include "network.h"
#include "core/portio/portio.h"
#include "hardware/radio/rfm12/rfm12.h"
#include "protocols/uip/ipv6.h"
#include "hardware/storage/sd_reader/sd_raw.h"
#include "core/vfs/vfs.h"

#include "autoconf.h"

#include "version.h"


#include <stdio.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <avr/boot.h>
#include <avr/wdt.h>
#include <util/delay.h>

#include "sd2iec/buffers.h"
#include "sd2iec/eeprom.h"
#include "sd2iec/fatops.h"
#include "sd2iec/iec.h"


#include "sd2iec/uart.h"

void get_mcusr(void) \
      __attribute__((naked)) \
      __attribute__((section(".init3")));
void get_mcusr(void)
{
  MCUSR = 0;
  wdt_disable();
}


/* global configuration */
global_status_t status;

/* prototypes */
#if ARCH != ARCH_HOST
void (*jump_to_bootloader) (void) = (void *) BOOTLOADER_START_ADDRESS;

#ifdef DEBUG_RESET_REASON
uint8_t mcusr_mirror __attribute__ ((section (".noinit")));
#endif

void __start (void) __attribute__ ((naked))
                    __attribute__ ((used))
                    __attribute__ ((section (".init3")));
void __start ()
{
  /* Clear the watchdog register to avoid endless wdreset loops */

  MCU_STATUS_REGISTER = 0;
  wdt_disable ();
  /* Disable all timer interrupts */
#ifdef TIMSK
  TIMSK = 0;
#endif
#ifdef TIMSK0
  TIMSK0 = 0;
#endif
#ifdef TIMSK1
  TIMSK1 = 0;
#endif
#ifdef TIMSK2
  TIMSK2 = 0;
#endif
}
#endif  /* ARCH != ARCH_HOST */


extern void ethersex_meta_init (void);
extern void ethersex_meta_startup (void);
extern void ethersex_meta_mainloop (void);
// Anfang
int main (void)
{
//IEC Code



	asm volatile ("in  r24, %0\n"
		"ori r24, 0x80\n"
		"out %0, r24\n"
		"out %0, r24\n"
		:
		: "I" (_SFR_IO_ADDR(MCUCSR))
		: "r24"
		);	

  BUSY_LED_SETDDR();
  DIRTY_LED_SETDDR();

  BUSY_LED_ON();
  DIRTY_LED_OFF();

  init_serial();
  init_buffers();
  init_iec();

  read_configuration();

  BUSY_LED_OFF();


//Ethernet code
  /* Default DDR Config */
#if IO_HARD_PORTS >= 4 && DDR_MASK_A != 0
  DDRA = DDR_MASK_A;
#endif
#if DDR_MASK_B != 0
  DDRB = DDR_MASK_B;
#endif
#if DDR_MASK_C != 0
  DDRC = DDR_MASK_C;
#endif
#if DDR_MASK_D != 0
  DDRD = DDR_MASK_D;
#endif
#if IO_HARD_PORTS >= 6
#if DDR_MASK_E != 0
  DDRE = DDR_MASK_E;
#endif
#if DDR_MASK_F != 0
  DDRF = DDR_MASK_F;
#endif
#endif
#if IO_HARD_PORTS >= 7
#if DDR_MASK_G != 0
  DDRG = DDR_MASK_G;
#endif
#endif




  //FIXME: zum ethersex meta system hinzufügen, aber vor allem anderem initalisieren
//debug_init();
  debug_printf("%S (Debug mode)\n", pstr_E6_VERSION_STRING_LONG);




  /* enable interrupts */
  cli ();//sei



  spi_init();


  ethersex_meta_init();



  debug_printf ("enc28j60 revision 0x%x\n",
  read_control_register (REG_EREVID));
  debug_printf ("mac: %02x:%02x:%02x:%02x:%02x:%02x\n",
	  uip_ethaddr.addr[0], uip_ethaddr.addr[1], uip_ethaddr.addr[2],
	  uip_ethaddr.addr[3], uip_ethaddr.addr[4], uip_ethaddr.addr[5]);



  ethersex_meta_startup();
  /* main loop */
  while (1)
  {

    //iEC code
    
iec_mainloop();





  
  }
}
