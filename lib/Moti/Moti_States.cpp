#include <Arduino.h>
#include <Moti.h>

//########//
// STATES //
//########//

/**
 * @brief Method used to initialize Moti's states.
 *
 * There are 6 different states: moving, sleeping, waiting, awake, manipulated, remote controlled.
 * All of them are initialized to false except waiting and awake.
 *
 * The methods used are setMovingState(false), setSleepingState(false), setWaitingState(true), setAwakeState(true), setManipulatedState(false), setRemoteState(false)
 */
void Moti::initializeStates(){
	setMovingState(false);
	setSleepingState(false);
	setWaitingState(true);
	setAwakeState(true);
	setManipulatedState(false);
	setRemoteState(false);
	setLearningState(false);
}



/**
 * @brief Is Moti sleeping method
 *
 * @return true if Moti's sleeping (not moving, not waiting, not awake), false if Moti's not sleeping.
 */
bool Moti::getSleepingState(){
	return _stateSleeping;
}

/**
 * @brief Is Moti waiting method
 *
 * @return true if Moti's waiting for the child to interact.
 */
bool Moti::getWaitingState(){
	return _stateWaiting;
}

/**
 * @brief Is Moti sleeping method
 *
 * @return true if Moti's sleeping (not moving, not waiting, not awake), false if Moti's not sleeping.
 */
bool Moti::getAwakeState(){
	return _stateAwake;
}

/**
 * @brief Is Moti being manipulated method
 *
 * @return true if Moti's is being manipulated by the child or if he has a shock.
 */
bool Moti::getManipulatedState(){
	return _stateManipulated;
}

/**
 * @brief Is Moti being remotely controlled method
 *
 * @return true if Moti's is waiting for instruction from the computer.
 */
bool Moti::getRemoteState(){
	return _stateRemote;
}

/**
 * @brief Is Moti sending data for machine learning
 *
 * @return true if Moti's is sending data for machine learning to the computer.
 */
bool Moti::getLearningState(){
	return _stateLearning;
}



/**
 * @brief Setter method for the sleeping state
 *
 * @param state can be true or false
 */
void Moti::setSleepingState(bool state){
	_stateSleeping = state;
}

/**
 * @brief Setter method for the waiting state
 *
 * @param state can be true or false
 */
void Moti::setWaitingState(bool state){
	_stateWaiting = state;
}

/**
 * @brief Setter method for the awake state
 *
 * @param state can be true or false
 */
void Moti::setAwakeState(bool state){
	_stateAwake = state;
}

/**
 * @brief Setter method for the manipulated state
 *
 * @param state can be true or false
 */
void Moti::setManipulatedState(bool state){
	_stateManipulated = state;
}

/**
 * @brief Setter method for the remote state
 *
 * @param state can be true or false
 */
void Moti::setRemoteState(bool state){
	_stateRemote = state;
}

/**
 * @brief Setter method for the learning state
 *
 * @param state can be true or false
 */
void Moti::setLearningState(bool state){
	_stateLearning = state;
}
