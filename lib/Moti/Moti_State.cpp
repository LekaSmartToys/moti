#include "Moti.h"
#include "Arduino.h"

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
void MOTI::initializeStates(){
	setMovingState(false);
	setSleepingState(false);
	setWaitingState(true);
	setAwakeState(true);
	setManipulatedState(false);
	setRemoteState(false);
}

/**
 * @brief Is Moti moving method
 *
 * @return true if motors are ON, false if motors are OFF.
 */
bool MOTI::isMoving(){
	return _stateMoving;
}

/**
 * @brief Is Moti sleeping method
 *
 * @return true if Moti's sleeping (not moving, not waiting, not awake), false if Moti's not sleeping.
 */
bool MOTI::isSleeping(){
	return _stateSleeping;
}

/**
 * @brief Is Moti waiting method
 *
 * @return true if Moti's waiting for the child to interact.
 */
bool MOTI::isWaiting(){
	return _stateWaiting;
}

/**
 * @brief Is Moti sleeping method
 *
 * @return true if Moti's sleeping (not moving, not waiting, not awake), false if Moti's not sleeping.
 */
bool MOTI::isAwake(){
	return _stateAwake;
}

/**
 * @brief Is Moti being manipulated method
 *
 * @return true if Moti's is being manipulated by the child or if he has a shock.
 */
bool MOTI::isManipulated(){
	return _stateManipulated;
}

/**
 * @brief Is Moti being remotely controlled method
 *
 * @return true if Moti's is waiting for instruction from the computer.
 */
bool MOTI::isRemote(){
	return _stateRemote;
}

/**
 * @brief Setter method for the moving state
 *
 * @param state can be true or false
 */
void MOTI::setMovingState(bool state){
	_stateMoving = state;
}

/**
 * @brief Setter method for the sleeping state
 *
 * @param state can be true or false
 */
void MOTI::setSleepingState(bool state){
	_stateSleeping = state;
}

/**
 * @brief Setter method for the waiting state
 *
 * @param state can be true or false
 */
void MOTI::setWaitingState(bool state){
	_stateWaiting = state;
}

/**
 * @brief Setter method for the awake state
 *
 * @param state can be true or false
 */
void MOTI::setAwakeState(bool state){
	_stateAwake = state;
}

/**
 * @brief Setter method for the manipulated state
 *
 * @param state can be true or false
 */
void MOTI::setManipulatedState(bool state){
	_stateManipulated = state;
}

/**
 * @brief Setter method for the remote state
 *
 * @param state can be true or false
 */
void MOTI::setRemoteState(bool state){
	_stateRemote = state;
}
