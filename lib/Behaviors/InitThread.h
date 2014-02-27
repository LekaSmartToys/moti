#ifndef LEKA_MOTI_ARDUINO_THREAD_SETUP_H_
#define LEKA_MOTI_ARDUINO_THREAD_SETUP_H_

#include <Arduino.h>
#include "ChibiOS_AVR.h"

#include "SensorThread.h"
#include "ArbitrerThread.h"
#include "HeartThread.h"
#include "DriveThread.h"
#include "LightThread.h"

void chSetup() {

	// SensorThread = chThdCreateStatic(waSensorThread, sizeof(waSensorThread),
	// 			NORMALPRIO + 13, SensorThreadFunction, NULL);
	// ArbitrerThread = chThdCreateStatic(waArbitrerThread, sizeof(waArbitrerThread),
	// 			NORMALPRIO + 12, ArbitrerThreadFunction, NULL);
	// DriveThread = chThdCreateStatic(waDriveThread, sizeof(waDriveThread),
	// 			NORMALPRIO + 9, DriveThreadFunction, NULL);
	// HeartThread = chThdCreateStatic(waHeartThread, sizeof(waHeartThread),
	// 			NORMALPRIO + 11, HeartThreadFunction, NULL);
	// LightThread = chThdCreateStatic(waLightThread, sizeof(waLightThread),
	// 			NORMALPRIO + 10, LightThreadFunction, NULL);

	chThdCreateStatic(waSensorThread, sizeof(waSensorThread),
				NORMALPRIO + 10, SensorThreadFunction, NULL);
	chThdCreateStatic(waArbitrerThread, sizeof(waArbitrerThread),
				NORMALPRIO + 9, ArbitrerThreadFunction, NULL);
	chThdCreateStatic(waDriveThread, sizeof(waDriveThread),
				NORMALPRIO + 8, DriveThreadFunction, NULL);
	chThdCreateStatic(waHeartThread, sizeof(waHeartThread),
				NORMALPRIO + 8, HeartThreadFunction, NULL);
	chThdCreateStatic(waLightThread, sizeof(waLightThread),
				NORMALPRIO + 8, LightThreadFunction, NULL);
}

#endif