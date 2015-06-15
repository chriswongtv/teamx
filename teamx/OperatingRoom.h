/** OperatingRoom class header file
@file OperatingRoom.h */

#ifndef _OPERATING_ROOM
#define _OPERATING_ROOM

#include "Patient.h"

using namespace std;

class OperatingRoom
{
private:
	Patient *theOneUnderTheKnife;	// Stores the address of the patient in this operating room
	string patientName;				// Stores the patient's name
	int timeRemaining;				// Stores the time remaining until the operation is done
public:
	/**
	* Default constructor - initializes private member functions.
	* @pre none
	* @post theOneUnderTheKnife is set to nullptr, 
			patientName is set to empty, timeRemaining is set to -1.
	*/
	OperatingRoom();

	/**
	* Checks if the operating room is empty.
	* @pre none
	* @post none
	* @return True if theOneUnderTheKnife is pointing to null, false otherwise.
	*/
	bool isEmpty();

	/**
	* Receives the patient's address and store them.
	* @pre none
	* @param The address of the patient.
	* @post theOneUnderTheKnife is pointing to the patient's address.
	*/
	void incomingPatient(Patient&);

	/**
	* Sets the patient name.
	* @pre none
	* @param The name of the patient in string.
	* @post patientName is set to the patient's name.
	*/
	void setPatientName(string);

	/**
	* Sets the time remaining.
	* @pre none
	* @param The time remaining of the patient in integer.
	* @post timeRemaining is set to the patient's estimated operating time.
	*/
	void setTimeRemaining(int);

	/**
	* Checks if the the patient is done operating.
	* @pre none
	* @post Calls tick if the operation is still ongoing, otherwise remove patient.
	*/
	void update();

	/**
	* Gets the patient's name.
	* @pre none
	* @post none
	* @return The patient's name in string.
	*/
	string getPatientName();

	/**
	* Gets the patient's time remaining.
	* @pre none
	* @post none
	* @return The patient's time remaining in string.
	*/
	string getTimeRemaining();

	/**
	* Decreases the time remaining by a minute.
	* @pre none
	* @post the time remaining is decreased by a minute.
	*/
	void tick();

	/**
	* Removes the patient from the operating room.
	* @pre none
	* @post theOneUnderTheKnife is set to nullptr,
			patientName is set to empty string,
			timeRemaining is set to -1.
	*/
	void removePatient();
}; // end OperatingRoom

#endif
