//
//  setbaud.c
//  SwiftSerial
//
//  Created by Lrdsnow on 1/1/25.
//

#include <stdio.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/termios.h>
#include <unistd.h>

#ifndef IOSSIOSPEED
#define IOSSIOSPEED _IOW('T', 2, speed_t)
#endif

int setbaud(int fileDescriptor, int baud) {
	speed_t speed = baud;
	if ( ioctl( fileDescriptor, IOSSIOSPEED, &speed ) == -1 ) {
		return 1;
	}
	return 0;
}
