/*
 * Copyright (C) 2010 ROCKCHIP, Inc.
 * Author: roger_chen <cz@rock-chips.com>
 *
 * This program is the virtual flash device
 * used to store bd_addr or MAC
 *
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include "eth_mac_tinker.h"

#define VERSION "0.2"
#define WLAN_MAC_FILE "/data/misc/wifi/wlan_mac"

int eth_mac_eeprom(u8 *eth_mac)
{
	int i;
	int ret;

	memset(eth_mac, 0, 6);
	printk("Read the Ethernet MAC address from EEPROM:");
	ret = at24_read_eeprom(eth_mac, 0, 6);

	for(i=0; i<5; i++)
		pr_info("%2.2x:", eth_mac[i]);
	pr_info("%2.2x\n", eth_mac[i]);

	return ret;
}
