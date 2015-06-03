/** <description>
@file OperatingRoom.h */

#ifndef _OPERATING_ROOM
#define _OPERATING_ROOM

#include "Patient.h"

using namespace std;

class OperatingRoom
{
private:
	Patient *theOneUnderTheKnife;
	string patientName;
	int timeRemaining;
public:
	OperatingRoom();
	bool isEmpty();
	void incomingPatient(Patient&);
	void setPatientName(string);
	void setTimeRemaining(int);
	void update();
	string getPatientName();
	string getTimeRemaining();
	void tick();
	void removePatient();

	/**
	* check if the patient is in the operating room.
	* @pre none
	* @post return true if the patient is in the operating room otherwise return false.
	*/
	//bool queryPatient(Patient & patient){
	//	return 1;
	//}

	/**
	* check if operating room is empty or busy or pick up.
	* @pre none
	* @post check if operating room is empty or busy or pick up, return number of empty busy PickUp.
	*/
	//int queryStatus()
	//{
	//	return -1;
	//}

	/**
	* Add a patient into operating room
	* @pre if operating room is empty
	* @post Add a patient
	* @param patient to add.
	* @ return true if add is successful otherwise return false
	*/
	//bool addPatient(Patient & patient){
		/*if (status == 0){
		time = patient.getEstimatedOperationTime();
		status = 1;
		return true;
		}
		else*/
	//	return false;
	//}

	/**
	* Pick up the patient
	* @pre check if status is pick up.
	* @post check if operating room's status is pick up, remove the patient.
	*/
	//void pickUpPatient(){
		/*if (status == PickUp){
		removePatient();
		}*/
	//}

	/**
	* count the time
	* @pre none
	* @post Change the status, if the time = 0,change the status to PickUP
	or if time > 0,change the status to Busy,otherwise status is empty
	* @param none
	*/
	//void tick(){
		/*time--;
		if (time == 0){
		status = PickUp;
		}
		else if (time > 0){
		status = Busy;
		}
		else
		status = Empty;*/
	//}

	//void update();//updates timer and checks for

}; // end OperatingRoom

#endif
