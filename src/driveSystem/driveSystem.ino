#define serial Serial

#include <Arduino.h>
#include "ChibiOS_AVR.h"

#include "Motor.h"
#include "Led.h"
#include "Tools.h"
#include "DriveSystem.h"
#include "Serial.h"

DriveSystem drive;
Led light = Led(8, 9, 10);

static WORKING_AREA(waThread1, 1024);

static msg_t Thread1 (void *arg) {

	(void)arg;

	while (TRUE) {

		// drive.go(FORTH, 95);
		// chThdSleepMilliseconds(1100);
		// drive.stop();
		// chThdSleepMilliseconds(750);
		// drive.spin(RIGHT, 100);
		// chThdSleepMilliseconds(500);
		// drive.stop();
		// chThdSleepMilliseconds(750);

		// drive.go(FORTH, 95);
		// chThdSleepMilliseconds(1100);
		// drive.stop();
		// chThdSleepMilliseconds(750);
		// drive.spin(RIGHT, 100);
		// chThdSleepMilliseconds(500);
		// drive.stop();
		// chThdSleepMilliseconds(750);

		// drive.go(FORTH, 95);
		// chThdSleepMilliseconds(1100);
		// drive.stop();
		// chThdSleepMilliseconds(750);
		// drive.spin(RIGHT, 100);
		// chThdSleepMilliseconds(500);
		// drive.stop();
		// chThdSleepMilliseconds(750);

		chThdSleepMilliseconds(5000);

	}
	return 0;
}

static WORKING_AREA(waThread2, 1024);

static msg_t Thread2 (void *arg) {

	(void)arg;

	while (TRUE) {
		light.fade(300, RED_PURE, GREEN_PURE);
		light.fade(300, GREEN_PURE, BLUE_PURE);
		light.fade(300, BLUE_PURE, RED_PURE);
	}

	return 0;
}

void chSetup() {

	chThdCreateStatic(waThread1, sizeof(waThread1),
		NORMALPRIO, Thread1, NULL);

	chThdCreateStatic(waThread2, sizeof(waThread2),
		NORMALPRIO, Thread2, NULL);

}


void setup() {

	serial.begin(115200);

	delay(3000);

	serial.println("Starting...");

	chBegin(chSetup);

	while(1) {
	}
}

void loop() {

}

