/*
 * Automatically generated by make menuconfig: don't edit
 */
#define AUTOCONF_INCLUDED




// IEC Daten

#define CONFIG_MCU atmega32
#define CONFIG_LINKER_RELAX
#define CONFIG_MCU_FREQ 16000000

#define CONFIG_TURBODISK
#define CONFIG_HARDWARE_VARIANT 1

//#define CONFIG_SD_AUTO_RETRIES 10

#define CONFIG_ERROR_BUFFER_SIZE 36
#define CONFIG_COMMAND_BUFFER_SIZE 100
#define CONFIG_BUFFER_COUNT 3
#define CONFIG_EEPROM_SIZE 512
#define CONFIG_EEPROM_OFFSET 512










/*
 * General Setup
 */
#define MCU_STATUS_REGISTER  MCUCSR 
#define ARCH ARCH_AVR
#define MCU atmega32
#define FREQ (16000000)
#define HARDWARE netio

#define BOOTLOADER_SIZE (0)
#define BOOTLOADER_START_ADDRESS 0x8000
#define FLASH_SIZE 0x8000
#define EEPROM_SIZE 0x400
#define RAM_SIZE 0x800
#define FLASH_PAGESIZE 0x80
#define EEPROM_PAGESIZE 0x4

#define GIT_VERSION ""


/*
 * Periodic / Scheduler
 */
#define CONF_MTICKS_PER_SEC (50)

#define CONF_PERIODIC_USE_TIMER 1
#
#define CONF_SCHEDULER_NUM_DYNAMIC_TIMERS (8)

#define VFS_SUPPORT 1

#define VFS_INLINE_SUPPORT 1

#define VFS_IO_INLINE_SUPPORT 1

#define ADC_INLINE_SUPPORT 1
#define ONEWIRE_INLINE_SUPPORT 1

#define VFS_INLINE_INLINESVG_SUPPORT 1

#define VFS_INLINE_INLINESVG_SUPPORT 1


/*
 * Network
 */
#define CONF_HOSTNAME "Tom"
#define NET_MAX_FRAME_LENGTH (500)
#define ENC28J60_SUPPORT 1
#define CONF_ENC_MAC  "\x00\x22\xf9\x01\x0c\x65"
#undef  IPV6_STATIC_SUPPORT
#define set_CONF_ENC_IP(ip) uip_ipaddr((ip), 192,168,0,91 )
#define CONF_ENC_IP "192.168.0.91"
#define set_CONF_ENC_IP4_NETMASK(ip) uip_ipaddr((ip), 255,255,255,0 )
#define CONF_ENC_IP4_NETMASK "255.255.255.0"

#define CONF_ENC_ECOCON ECOCON_UNSET

#define ETHERNET_SUPPORT 1

#define CONF_TAP_MAC  "\xac\xde\x48\xfd\x0f\xd0"
#undef  IPV6_STATIC_SUPPORT

#define set_CONF_TAP_IP4_NETMASK(ip) uip_ipaddr((ip), 255,255,255,0 )
#define CONF_TAP_IP4_NETMASK "255.255.255.0"

#define UIP_SUPPORT 1
#define NET_SUPPORT 1
#undef IPV6_SUPPORT 
#define IPV4_SUPPORT 1

#define set_CONF_ETHERSEX_GATEWAY(ip) uip_ipaddr((ip), 192,168,0,2 )
#define CONF_ETHERSEX_GATEWAY "192.168.0.2"

#define TCP_SUPPORT 1
#undef  UDP_SUPPORT 
#undef  BROADCAST_SUPPORT
#define ICMP_SUPPORT 1
#undef  DNS_SUPPORT
#define set_CONF_DNS_SERVER(ip) uip_ipaddr((ip), 192,168,0,254 )
#define CONF_DNS_SERVER "192.168.0.254"

#undef  DHCP_SUPPORT






/*
 * Protocols
 */
#undef  NET_MAX_FRAME_LENGTH_GT_571
#undef  ARTNET_SUPPORT
#define CONF_ARTNET_PORT (6454)
#define CONF_ARTNET_INUNIVERSE (1)
#define CONF_ARTNET_OUTUNIVERSE (0)
#define set_CONF_ARTNET_OUTPUT_IP(ip) uip_ipaddr((ip), 192,168,0,255 )
#define CONF_ARTNET_OUTPUT_IP "192.168.0.255"
/*
#define DMX_OUTPUT_UNIVERSE (1)
#define ECMD_PARSER_SUPPORT 1

#define ECMD_TCP_SUPPORT 1
#define ECMD_TCP_PORT (2701)

#define EMS_BUFFER_LEN (64)
#define EMS_PORT (7950)

#define FNORDLICHT_BAUDRATE (19200)

#define CONF_FNORDLICHTER (1)

#define CONF_HTTPLOG_SERVICE "volkszaehler.org"
#define CONF_HTTPLOG_PATH "/httplog/httplog.php"

#define CONF_HTTPLOG_UUID "12345678-9ABC-DEF0-1234-56789ABCDEF0"
#define HTTPLOG_BUFFER_LEN (140)

#define set_CONF_IRC_IP(ip) uip_ipaddr((ip), 192,168,0,254 )
#define CONF_IRC_IP "192.168.0.254"
#define CONF_IRC_PORT (6667)
#define CONF_IRC_CHANNEL "ethersex"
#define CONF_IRC_USERNAME "ethersex"
#define CONF_IRC_NICKNAME "ethersex"
#define CONF_IRC_REALNAME "Ethersex Wollmilchsau"

#define MQTT_CALLBACK_SLOTS (1)

#define set_CONF_MYSQL_IP(ip) uip_ipaddr((ip), 192,168,0,254 )
#define CONF_MYSQL_IP "192.168.0.254"
#define CONF_MYSQL_USERNAME "root"
#define CONF_MYSQL_PASSWORD "password"
#define CONF_MYSQL_SCHEMA "mavisdb"

#define set_CONF_NETSTAT_SERVICE_IP(ip) uip_ipaddr((ip), 188,40,33,175 )
#define CONF_NETSTAT_SERVICE_IP "188.40.33.175"
#define CONF_NETSTAT_SERVICE "ethersex.de"
#define CONF_NETSTAT_API "/~habo/stat/"
*/
