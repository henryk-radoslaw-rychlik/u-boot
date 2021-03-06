/*
 * (C) Copyright 2005, Psyent Corporation <www.psyent.com>
 * Scott McNutt <smcnutt@psyent.com>
 * (C) Copyright 2010, Thomas Chou <thomas@wytron.com.tw>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * BOARD/CPU
 */
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO_LATE

/*
 * SERIAL
 */
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_CONSOLE_INFO_QUIET	/* Suppress console info */

/*
 * Flash
 */
#define CONFIG_SYS_MAX_FLASH_BANKS	1
#define CONFIG_SYS_MAX_FLASH_SECT	1024
#define CONFIG_MTD_DEVICE

/*
 * NET options
 */
#define CONFIG_SYS_RX_ETH_BUFFER	0
#define CONFIG_CMD_MII
#define CONFIG_PHY_GIGE
#define CONFIG_SYS_FAULT_ECHO_LINK_DOWN
#define CONFIG_PHY_MARVELL

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME

/*
 * FDT options
 */
#define CONFIG_OF_LIBFDT
#define CONFIG_OF_BOARD_SETUP
#define CONFIG_LMB

/*
 * ENVIRONMENT -- Put environment in sector CONFIG_SYS_MONITOR_LEN above
 * CONFIG_SYS_RESET_ADDR, since we assume the monitor is stored at the
 * reset address, no? This will keep the environment in user region
 * of flash. NOTE: the monitor length must be multiple of sector size
 * (which is common practice).
 */
#define CONFIG_ENV_IS_IN_FLASH

#define CONFIG_ENV_SIZE			0x10000	/* 64k, 1 sector */
#define CONFIG_ENV_OVERWRITE		/* Serial change Ok	*/
#define CONFIG_ENV_ADDR			0xf4040000

/*
 * MEMORY ORGANIZATION
 * -Monitor at top of sdram.
 * -The heap is placed below the monitor
 * -The stack is placed below the heap (&grows down).
 */
#define CONFIG_SYS_SDRAM_BASE		0xc8000000
#define CONFIG_SYS_SDRAM_SIZE		0x08000000
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_MONITOR_IS_IN_RAM
#define CONFIG_SYS_MONITOR_LEN		0x40000	/* Reserve 256k */
#define CONFIG_SYS_MONITOR_BASE	(CONFIG_SYS_SDRAM_BASE + \
					 CONFIG_SYS_SDRAM_SIZE - \
					 CONFIG_SYS_MONITOR_LEN)
#define CONFIG_SYS_MALLOC_LEN		0x20000

/*
 * MISC
 */
#define CONFIG_SYS_LONGHELP		/* Provide extended help */
#define CONFIG_SYS_CBSIZE		256	/* Console I/O buf size */
#define CONFIG_SYS_MAXARGS		16	/* Max command args	*/
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE /* Bootarg buf size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + \
					 16)	/* Print buf size */
#define CONFIG_SYS_LOAD_ADDR		CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_MONITOR_BASE - \
					 CONFIG_ENV_SIZE - \
					 CONFIG_SYS_MALLOC_LEN -	\
					 0x10000)
#define CONFIG_CMDLINE_EDITING
#define CONFIG_CMD_GPIO

#endif /* __CONFIG_H */
