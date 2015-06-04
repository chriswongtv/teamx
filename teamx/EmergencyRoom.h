/** <description>
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
	int patientCount;
	OperatingRoom* OR1;							// Stores pointer to the first operating room
	OperatingRoom* OR2;							// Stores pointer to the second operating room
	OperatingRoom* OR3;							// Stores pointer to the third operating room
	Heap_PriorityQueue<Events> events;			// Stores the incoming patient priority queue 
	Heap_PriorityQueue<Patient> waitingRoom;	// Stores the waiting room priority queue
	int currentTime;							// Stores the current time
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

	void reviewPatient();

	void setTime();

	/**
	* Simulate the hospital queue's movements.
	* @pre none
	* @post Process the simulation based on requestNextPatient's arrival time
			and estimated operation time.
	*/
	void simHospital();

	string getCurrentTime();

	bool incomingPatient();

	void movePatient();

	void updateTime();

	/**
	* Get the first patient in the priority queue.
	* @pre none
	* @post The first patient is removed from the queue.
	* @return The first patient is returned.
	*/
	Patient requestNextPatient();

	string getQueuePatient(int);

	/**
	* Refreshes the screen with the queue's movement based on time.
	* @pre none
	* @post The queue's movement is displayed.
	*/
	void displayQueueMovement();

}; // end EmergencyRoom

#endif
