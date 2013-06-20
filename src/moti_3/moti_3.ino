//######################################################################//
//	MOTI SOFTWARE v1.0													//
//	COPYRIGHT WE ARE LEKA! - SOURCE CODE DISTRIBUTED UNDER MIT LICENCE	//
//######################################################################//


//###########//
// LIBRARIES //
//###########//

#include "RGBLED.h"
#include "Arduino.h"
#include <Wire.h>

#include <CommunicationUtils.h>
#include <DebugUtils.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>
#include <FreeSixIMU.h>



//#####################//
// CONSTANT DEFINITION //
//#####################//

const int GLOBAL_DELAY = 75;   //	Delay used at the end of void loop() - The higher, the slower the robot is.
const int SLEEP_DELAY = 600; //	Time to elapse before the robot goes to sleep

const int AWAKE_THRESHOLD = 300; //	DO NOT USE A VALUE HIGHER THAN 150 - This threshold is used to wake up the card. The higher, the harder it is to wake up.
const int DELTA_ACCELERO_THRESHOLD = 200;   //	Threshold used to know if the accelerometer has moved between 2 cycles
const int CRAZY_ACTIVITY_THRESHOLD= 80;    //	Is used to know if the activity around the robot is important. If so, the robot gets excited much faster - Smaller value means more excitement.

const int LED_MAX_BRIGHTNESS = 255;	//	Maximum led brightness
const int RED_MAX_BRIGHTNESS = 255;
const int GREEN_MAX_BRIGHTNESS = 255;
const int BLUE_LED_MAX = 255;



//##############################################//
// ACCELEROMETER, GYROSCOPE AND RGB LED CLASSES //
//##############################################//

//	ACCELEROMETER
FreeSixIMU AccelGyro = FreeSixIMU();

//	LED
RGBLED RGBLED(9, 10,11);



//######################//
// MOTOR PINS ASSIGMENT //
//######################//

//	MOTORS - set speed and direction pins for each motor
const int MOTOR_1_SPEED = 5;
const int MOTOR_1_DIR = 4;
const int MOTOR_2_SPEED = 6;
const int MOTOR_2_DIR = 7;



//###########//
// VARIABLES //
//###########//

//	GENERAL
int i;
int RGB[3], RGB_BUFFER[3];
int MOTOR[2], MOTOR_BUFFER[2];
float XYZ[3], lastXYZ[3], deltaXYZ[3];
float YPR[3], lastYPR[3], deltaYPR[3];
int sleepy;

//	DEBUG
boolean isRemoteCtrl;
boolean isShutDown;



//#######//
// SETUP //
//#######//

void setup() {

	// setupMoti_VERBOSE();
	setupMoti_QUIET();
}



//######//
// LOOP //
//######//

void loop() {

	//	Check sensors values
	checkSensors();

	if(isShutDown) {

		// sendSerialFeedback();
		sendProcessingFeedback(); // JUST COMMENT ONE OF THE TWO LINES

		if ( deltaXYZ[0] > AWAKE_THRESHOLD || deltaXYZ[1] > AWAKE_THRESHOLD || deltaXYZ[2] > AWAKE_THRESHOLD) {
			isShutDown = false;
			softwareReset();
		}
	}
	else {

		if (lastXYZ[2] == XYZ[2]) {
			sleepy++;
		}

		if (deltaXYZ[0] < CRAZY_ACTIVITY_THRESHOLD || deltaXYZ[1] < CRAZY_ACTIVITY_THRESHOLD || deltaXYZ[2] < CRAZY_ACTIVITY_THRESHOLD) {
			sleepy++;

			RGB[0]-=15;
			RGB[1]-=15;
			RGB[2]+=30;

			MOTOR[0]-=10;
			MOTOR[1]-=10;
		}
		else {
			if (deltaXYZ[0] > CRAZY_ACTIVITY_THRESHOLD) {
				sleepy=0;
				RGB[0]+=30;
				RGB[1]+=10;
				RGB[2]-=50;
			}
			if (deltaXYZ[1] > CRAZY_ACTIVITY_THRESHOLD) {
				sleepy=0;
				RGB[0]+=30;
				RGB[1]+=10;
				RGB[2]-=50;
			}
			if (deltaXYZ[2] > CRAZY_ACTIVITY_THRESHOLD) {
				sleepy=0;
				RGB[0]+=30;
				RGB[1]+=10;
				RGB[2]-=50;
			}
		}

		if(sleepy > SLEEP_DELAY) {
			setMotorPinToZero();
			setMotorValueToZero();
			setMotorSpeedAndDirection();

			setRGBValueToZero();
			setLedPinToZero();

			RGBLED.blinkLED(2);

			delay(100);
			
			shutDown();
		}

		setRGBValue();

		outputRGB();

		setMotorSpeedAndDirection();

		// sendSerialFeedback();
		sendProcessingFeedback(); //JUST COMMENT ONE OF THE TWO LINES
	}

	lastXYZ[0] = XYZ[0];
	lastXYZ[1] = XYZ[1];
	lastXYZ[2] = XYZ[2];

	delay(GLOBAL_DELAY);
}
