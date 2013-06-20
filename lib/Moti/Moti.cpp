#include "Moti.h"
#include "Constants.h"

#include "Arduino.h"

#include "FreeSixIMU.h"
#include "RGBLED.h"


//##############//
// CONSTRUCTORS //
//##############//

Moti & Moti::getInstance() {
	static Moti singleton;
	return singleton;
}

Moti::Moti(){
	delay(50);

	Serial.begin(115200);

	delay(50);

	RGBLED rgbled = RGBLED(RED_PIN, GREEN_PIN, BLUE_PIN);
	FreeSixIMU AccelGyro = FreeSixIMU();

	delay(50);
}


//###############//
// SET CONSTANTS //
//###############//

void Moti::setGlobalDelay(int value){
	_globalDelay = value;
}

void Moti::setSleepDelay(int value){
	_sleepDelay = value;
}

void Moti::setAwakeThreshold(int value){
	_awakeThreshold = value;
}

void Moti::setDeltaAccelThreshold(int value){
	_deltaAccelThreshold = value;
}

void Moti::setHighActivityThreshold(int value){
	_highActivityThreshold = value;
}

void Moti::setLedMaxBrightness(int value){
	_ledMaxBrightness = value;
}

void Moti::setRedMaxBrightness(int value){
	_redMaxBrightness = value;
}

void Moti::setGreenMaxBrightness(int value){
	_greenMaxBrightness = value;
}

void Moti::setBlueMaxBrightness(int value){
	_blueMaxBrightness = value;
}


//###############//
// GET CONSTANTS //
//###############//

int Moti::getGlobalDelay(){
	return _globalDelay;
}

int Moti::getSleepDelay(){
	return _sleepDelay;
}

int Moti::getAwakeThreshold(){
	return _awakeThreshold;
}

int Moti::getDeltaAccelThreshold(){
	return _deltaAccelThreshold;
}

int Moti::getHighActivityThreshold(){
	return _highActivityThreshold;
}

int Moti::getLedMaxBrightness(){
	return _ledMaxBrightness;
}

int Moti::getRedMaxBrightness(){
	return _redMaxBrightness;
}

int Moti::getGreenMaxBrightness(){
	return _greenMaxBrightness;
}

int Moti::getBlueMaxBrightness(){
	return _blueMaxBrightness;
}


//#################//
// RESET CONSTANTS //
//#################//

void Moti::resetGlobalDelay(int value){
	_globalDelay = DEFAULT_GLOBAL_DELAY;
}

void Moti::resetSleepDelay(int value){
	_sleepDelay = DEFAULT_SLEEP_DELAY;
}

void Moti::resetAwakeThreshold(int value){
	_awakeThreshold = DEFAULT_AWAKE_THRESHOLD;
}

void Moti::resetDeltaAccelThreshold(int value){
	_deltaAccelThreshold = DEFAULT_DELTA_ACCEL_THRESHOLD;
}

void Moti::resetHighActivityThreshold(int value){
	_highActivityThreshold = DEFAULT_HIGH_ACTIVITY_THRESHOLD;
}


void Moti::resetLedMaxBrightness(int value){
	_ledMaxBrightness = DEFAULT_LED_MAX_BRIGHTNESS;
}

void Moti::resetRedMaxBrightness(int value){
	_redMaxBrightness = DEFAULT_RED_MAX_BRIGHTNESS;
}

void Moti::resetGreenMaxBrightness(int value){
	_greenMaxBrightness = DEFAULT_GREEN_MAX_BRIGHTNESS;
}

void Moti::resetBlueMaxBrightness(int value){
	_blueMaxBrightness = DEFAULT_BLUE_MAX_BRIGHTNESS;
}



//###########################//
// DATA TRANSFER TO COMPUTER //
//###########################//

void Moti::sendDataToProcessing(){
	Serial.print(XYZ[0]);
	Serial.print(',');
	Serial.print(XYZ[1]);
	Serial.print(',');
	Serial.print(XYZ[2]);

	Serial.print(',');

	Serial.print(deltaXYZ[0]);
	Serial.print(',');
	Serial.print(deltaXYZ[1]);
	Serial.print(',');
	Serial.print(deltaXYZ[2]);

	Serial.print(',');

	Serial.print(rgb[0]);
	Serial.print(',');
	Serial.print(rgb[1]);
	Serial.print(',');
	Serial.print(rgb[2]);

	Serial.print(',');
	Serial.print(rightMotor);
	Serial.print(',');
	Serial.println(leftMotor);
}

void Moti::sendDataToDebug(){
	Serial.print(F("Sleep: "));
	Serial.print(sleepy);

	Serial.print(F("R: "));
	Serial.print(rgb[0]);
	Serial.print(F(" G: "));
	Serial.print(rgb[1]);
	Serial.print(F(" B: "));
	Serial.print(rgb[2]);

	Serial.print(F(" | MOTOR 1: "));
	Serial.print(rightMotor);
	Serial.print(F(" MOTOR 2: "));
	Serial.print(leftMotor);

	Serial.print(F(" | X: "));
	Serial.print(XYZ[0]);
	Serial.print(F(" Y: "));
	Serial.print(XYZ[1]);
	Serial.print(F(" Z: "));
	Serial.print(XYZ[2]);

	Serial.print(F(" | dX: "));
	Serial.print(deltaXYZ[0]);
	Serial.print(F(" dY: "));
	Serial.print(deltaXYZ[1]);
	Serial.print(F(" dZ: "));
	Serial.println(deltaXYZ[2]);
}

void Moti::sendDataJson(){
	Serial.print(F("{"));
		Serial.print(F("\" accel\" : "));
			Serial.print(F("{"));

				Serial.print(F(" \"x\" : "));
				Serial.print(XYZ[0]);
				Serial.print(F(","));

				Serial.print(F(" \"y\" : "));
				Serial.print(XYZ[1]);
				Serial.print(F(","));

				Serial.print(F(" \"z\" : "));
				Serial.print(XYZ[2]);

			Serial.print(F(" },"));

		Serial.print(F("\" gyro\" : "));
			Serial.print(F("{"));

				Serial.print(F(" \"yaw\" : "));
				Serial.print(YPR[0]);
				Serial.print(F(","));

				Serial.print(F(" \"pitch\" : "));
				Serial.print(YPR[1]);
				Serial.print(F(","));

				Serial.print(F(" \"roll\" : "));
				Serial.print(YPR[2]);

			Serial.print(F(" },"));

		Serial.print(F("\" rgb\" : "));
			Serial.print(F("{"));

				Serial.print(F(" \"red\" : "));
				Serial.print(rgb[0]);
				Serial.print(F(","));

				Serial.print(F(" \"green\" : "));
				Serial.print(rgb[1]);
				Serial.print(F(","));

				Serial.print(F(" \"blue\" : "));
				Serial.print(rgb[2]);

			Serial.print(F(" }"));
	Serial.println(F("}"));
}


//#####//
// LED //
//#####//

void Moti::setRgbValue(){
	rgbBuffer[0] = constrain(rgb[0], 0, getLedMaxBrightness());
	rgbBuffer[1] = constrain(rgb[1], 0, getLedMaxBrightness());
	rgbBuffer[2] = constrain(rgb[2], 0, getLedMaxBrightness());

	rgb[0] = rgbBuffer[0];
	rgb[1] = rgbBuffer[1];
	rgb[2] = rgbBuffer[2];
}

void Moti::setRgbValue(int value){
	for(int _i = 0 ; _i < 3 ; _i++){
		rgbBuffer[_i] = constrain(value, 0, getLedMaxBrightness());
		rgb[_i] = rgbBuffer[_i];
	}
}

void Moti::setRgbValue(int redValue, int greenValue, int blueValue){
	rgbBuffer[0] = constrain(redValue, 0, getLedMaxBrightness());
	rgbBuffer[1] = constrain(greenValue, 0, getLedMaxBrightness());
	rgbBuffer[2] = constrain(blueValue, 0, getLedMaxBrightness());

	rgb[0] = rgbBuffer[0];
	rgb[1] = rgbBuffer[1];
	rgb[2] = rgbBuffer[2];
}

void Moti::printRgbColor(){
	rgbled.colorRGB(rgb[0], rgb[1], rgb[2]);
}

void Moti::printRgbColor(int redValue, int greenValue, int blueValue){
	rgbled.colorRGB(redValue, greenValue, blueValue);
}

void Moti::blinkLed(int nbrOfBlinks){

}

void Moti::fadeLedTo(void (*color)){


	int fadeRed = 0;
	int fadeGreen = 0;
	int fadeBlue = 0;
	while(fadeRed <= Moti::rgb[0] || fadeGreen <= Moti::rgb[1] || fadeBlue <= Moti::rgb[2]){
		if (fadeRed < Moti::rgb[0]){
			fadeRed++;
		}
		if (fadeGreen < Moti::rgb[1]){
			fadeGreen++;
		}
		if (fadeBlue < Moti::rgb[2]){
			fadeBlue++;
		}
		printRgbColor();
	}
}

void Moti::turnLedOn(){
	rgbled.colorRGB(255, 255, 255);
}

void Moti::turnLedOff(){
	rgbled.colorRGB(0, 0, 0);
}


//########//
// MOTORS //
//########//

void Moti::goForward(){

}

void Moti::goForward(int time){

}

void Moti::goBackward(){

}

void Moti::goBackward(int time){

}

void Moti::turnAround(){

}

void Moti::turnAround(int time){

}

void Moti::goLeft(){

}

void Moti::goRight(){

}

void Moti::stop(){

	//voici la function stop, elle permet à Moti de s'arrêter en un instant !

}

void Moti::nouvelleFonction(){
	// Luan s'il te plait, peux tu l'implémenter ? :) merci!
	// Ok, voilá je travaille.
	// Okay c'est super mais il manque un truc ! :(
	// Okay, maintenant c'est bon !!! :)
}


//#########//
// SENSORS //
//#########//

void Moti::checkSensors(){
	checkAccelerometer();
	checkGyroscope();
}

void Moti::checkAccelerometer(){

}

void Moti::checkGyroscope(){

}


//#########//
// GENERAL //
//#########//

void Moti::setAllToLow(){

}

void Moti::shutDown(){

}

void Moti::softwareReset() {
	//	this function reset the program so that it can restart before the void setup().
	//	it is used because we don't know how much time has passed since the last awaken state.
	//	the environment may have change, so going through the void setup() again is required.

	asm volatile ("  jmp 0");
}

