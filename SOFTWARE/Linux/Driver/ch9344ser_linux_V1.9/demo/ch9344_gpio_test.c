/*
 * ch9344 gpio application example for USB to Quad UARTs chip ch9344 and USB to Octal UARTs chip ch348.
 *
 * Copyright (C) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Web: http://wch.cn
 * Author: WCH@TECH39 <tech@wch.cn>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 * Cross-compile with cross-gcc -I /path/to/cross-kernel/include
 *
 * Version: V1.1
 *
 * Update Log:
 * V1.0 - initial version
 * V1.1 - added supports for ch348
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <getopt.h>
#include <linux/serial.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "ch9344_lib.h"

static CHIPTYPE chiptype;
static int gpiocount;
static int gpiogroup;

static const char *device = "/dev/ttyCH9344USB0";

void libch9344_gpiotest(int fd)
{
	char c;
	uint8_t gpioval;
	int i;
	int ret;

	ret = libch9344_get_chiptype(fd, &chiptype);
	if (ret) {
		return;
	}

	gpiocount = libch9344_get_gpio_count(chiptype);
	if (gpiocount <= 0) {
		printf("get gpio count error.\n");
		return;
	}
	printf("current chip has %d gpios.\n", gpiocount);

	gpiogroup = libch9344_get_gpio_group(chiptype);
	if (gpiogroup <= 0) {
		printf("get gpio group error.\n");
		return;
	}
	printf("current chip has %d gpio groups.\n", gpiogroup);

	while (1) {
		if (c != '\n')
			printf("press e to enable gpio, d to disable gpio, "
					"o to set gpio output, i to set gpio input, "
					"h to output high, l to low, g to get gpio, q to quit.\n");
		scanf("%c", &c);
		if (c == 'q')
			break;
		switch (c) {
			case 'e':
				for (i = 0; i < gpiogroup; i++) {
					if (chiptype == CHIP_CH9344)
						ret = libch9344_gpioenable(fd, i, 0x01);
					else
						ret = libch9344_gpioenable(fd, i, 0xff);
					if (ret != 0) {
						printf("gpio %d enable failed.\n", i);
						break;
					}
				}
				break;
			case 'd':
				for (i = 0; i < gpiogroup; i++) {
					ret = libch9344_gpioenable(fd, i, 0x00);
					if (ret != 0) {
						printf("gpio %d disable failed.\n", i);
						break;
					}
				}
				break;
			case 'o':
				for (i = 0; i < gpiocount; i++) {
					ret = libch9344_gpiodirset(fd, i, 0x01);
					if (ret != 0) {
						printf("gpio %d direction output set failed.\n", i);
						break;
					}
				}
				break;
			case 'i':
				for (i = 0; i < gpiocount; i++) {
					ret = libch9344_gpiodirset(fd, i, 0x00);
					if (ret != 0) {
						printf("gpio %d direction input set failed.\n", i);
						break;
					}
				}
				break;
			case 'h':
				for (i = 0; i < gpiocount; i++) {
					ret = libch9344_gpioset(fd, i, 0x01);
					if (ret != 0) {
						printf("gpio %d level set failed.\n", i);
						break;
					}
				}
				break;
			case 'l':
				for (i = 0; i < gpiocount; i++) {
					ret = libch9344_gpioset(fd, i, 0x00);
					if (ret != 0) {
						printf("gpio %d level set failed.\n", i);
						break;
					}
				}
				break;
			case 'g':
				for (i = 0; i < gpiocount; i++) {
					ret = libch9344_gpioget(fd, i, &gpioval);
					if (ret != 0) {
						printf("gpio %d level get failed.\n", i);
						break;
					} else
						printf("gpio%d : %s\n", i, gpioval ? "high" : "low");
				}
				break;
			default:
				break;
		}
	}
}

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	char c;

	fd = libtty_open(device);
	if (fd < 0) {
		printf("libtty_open error.\n");
		exit(0);
	}

	libch9344_gpiotest(fd);

	ret = libtty_close(fd);
	if (ret != 0) {
		printf("libtty_close error.\n");
		exit(0);
	}
}
