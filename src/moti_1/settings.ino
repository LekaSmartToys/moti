void setPinsAsOutput() {
	//	this function sets all the pins to output
	//	it does not take any argument and requires the user to manually write the different pins
	//	possible update: use arguments to set the pins with the less possible code written.

	pinMode(MOTOR_2_DIR, OUTPUT);
	pinMode(MOTOR_1_DIR, OUTPUT);
	pinMode(MOTOR_2_SPEED, OUTPUT);
	pinMode(MOTOR_1_SPEED, OUTPUT);

	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
}



void setPinsValuesToZero() {
	//	this function sets all the pins to zero / LOW
	//	it does not take any argument and requires the user to manually write the different pins
	//	possible update: use arguments to set the pins with the less possible code written.

	digitalWrite(MOTOR_2_DIR, 0);
	digitalWrite(MOTOR_1_DIR, 0);
	digitalWrite(MOTOR_2_SPEED, 0);
	digitalWrite(MOTOR_1_SPEED, 0);

	digitalWrite(RED_PIN, 0);
	digitalWrite(GREEN_PIN, 0);
	digitalWrite(BLUE_PIN, 0);

	analogWrite(RED_PIN, 0);
	analogWrite(GREEN_PIN, 0); 
	analogWrite(BLUE_PIN, 0);
}



void setRgbAndMotorToZero() {

	MOTOR[0] = 0;
	MOTOR[1] = 0;
	MOTOR_BUFFER[0] = 0;
	MOTOR_BUFFER[1] = 0;

	RGB[0] = 0;
	RGB[1] = 0;
	RGB[2] = 0;
}