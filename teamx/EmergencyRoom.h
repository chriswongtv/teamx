/** EmergencyRoom class header file
@file EmergencyRoom.h */

#ifndef _EMERGENCY_ROOM
#define _EMERGENCY_ROOM

#include "Events.h"
#include "Patient.h"
#include "OperatingRoom.h"
#include "Heap_PriorityQueue.h"

using namespace std;
class EmergencyRoom
{
private:
	static const int DEFAULT_CAPACITY = 101;		// Default size of the array
	int patientCount;								// Stores the total patient count
	OperatingRoom* OR1;								// Stores pointer to the first operating room
	OperatingRoom* OR2;								// Stores pointer to the second operating room
	OperatingRoom* OR3;								// Stores pointer to the third operating room
	Heap_PriorityQueue<Events> events;				// Stores the incoming patient priority queue 
	Heap_PriorityQueue<Patient> waitingRoom;		// Stores the waiting room priority queue
	Heap_PriorityQueue<Patient> waitingRoomDisplay;	// Stores a copy of the waiting room priority queue for displaying
	Patient patients[DEFAULT_CAPACITY];				// Stores the patient queue for reviewing
	Patient waitingRoomArray[DEFAULT_CAPACITY];		// Stores the patient queue for displaying
	int waitingRoomCount;							// Stores the total patient count in the waiting room
	int currentTime;								// Stores the current time
public:
	/**
	* Default constructor - initializes private member functions.
	* @pre none
	* @post OR1, OR2, OR3 are pointing to OperatingRoom objects.
			waitingRoom is initialized with a priority queue.
			Calls promptInput. patientCount set to zero.
	*/
	EmergencyRoom();
	
	/**
	* Destructor
	* @pre none
	* @post OR1, OR2, OR3 are pointed to nullptr.
			waitingRoom's clear function is called.
	*/
	~EmergencyRoom();

	/**
	* Prompts user if there is anymore patient.
	* @pre none
	* @post Calls patientInput if user inputs yes, otherwise call simHospital.
	*/
	void promptInput();

	/**
	* Prompts user to input patient's information.
	* @pre none
	* @post Patient's information are stored in waitingRoom.
	*/
	void patientInput();

	/**
	* Prompts if user wants to review a patient's information.
	* @pre none
	* @post Patient's information are displayed.
	*/
	void reviewPatient();

	/**
	* Sets the initial time.
	* @pre none
	* @post The time is set to 5 minutes before the first patient's arrival.
	*/
	void setTime();

	/**
	* Simulates the hospital queue's movements.
	* @pre none
	* @post Process the simulation based on requestNextPatient's arrival time
			and estimated operation time.
	*/
	void simHospital();

	/**
	* Moves patients from the array back to the priority queue's copy
	* @pre none
	* @post The priority queue is added with the array's items
	*/
	void moveArrayToQueue();

	/**
	* Gets the current time.
	* @pre none
	* @post The updateTime function is called.
	* @return The current time is returned as a string.
	*/
	string getCurrentTime();

	/**
	* Checks if the first patient on the queue's arrival time matches the current time
	* @pre none
	* @post none
	* @return True if the first patient's arrival time matches the current time, otherwise false.
	*/
	bool isPatientIncoming();

	/**
	* Moves the patient from the events queue to the waiting room.
	* @pre none
	* @post The first patient in the events queue is removed and added into the waiting room.
	*/
	void movePatient();

	/**
	* Moves the patients from the waiting room copy to the array.
	* @pre none
	* @post The waiting room array is filled with the patients from the waiting room copy.
	*/
	void updateWaitingRoomArray();

	/**
	* Increases the time by a minute.
	* @pre none
	* @post The time is increased by a minute.
	*/
	void updateTime();

	/**
	* Get the first patient in the priority queue.
	* @pre none
	* @post The first patient is removed from the queue.
	* @return The first patient is returned.
	*/
	Patient requestNextPatient();

	/**
	* Refreshes the screen with the queue's movement based on time.
	* @pre none
	* @post The queue's movement is displayed.
	*/
	void displayQueueMovement();

	/**
	* Converts the time from integer to string.
	* @pre none
	* @param The time in integer (military time)
	* @post none
	* @return The time in string is returned.
	*/
	string timeInString(int);

}; // end EmergencyRoom

#endif
