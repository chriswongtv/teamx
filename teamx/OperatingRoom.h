/** <description>
@file OperatingRoom.h */

#ifndef _OPERATING_ROOM
#define _OPERATING_ROOM


	/*OperatingRoom();

	//testresresrs

	void update();//updates timer and checks for*/

	enum status{
		Empty = 0,
		Busy = 1,
		PickUp = 2
	};

	class OperatingRoom// one per thread
	{
	private:

		Patient patient;
		int time;
		int status;

	public:
		void removePatient();

		/**
		* check if the patient is in the operating room.
		* @pre none
		* @post return true if the patient is in the operating room otherwise return false.
		*/
		bool queryPatient(Patient & patient);

		/**
		* check if operating room is empty or busy or pick up.
		* @pre none
		* @post check if operating room is empty or busy or pick up, return number of empty busy PickUp.
		*/
		int queryStatus();

		/**
		* Add a patient into operating room
		* @pre if operating room is empty
		* @post Add a patient
		* @param patient to add.
		* @ return true if add is successful otherwise return false
		*/
		bool addPatient(Patient & patient);

		/**
		* Pick up the patient
		* @pre check if status is pick up.
		* @post check if operating room's status is pick up, remove the patient.
		*/
		void pickUpPatient();

		/**
		* count the time
		* @pre none
		* @post Change the status, if the time = 0,change the status to PickUP
		or if time > 0,change the status to Busy,otherwise status is empty
		* @param none
		*/
		void tick();

}; // end OperatingRoom

//#include "OperatingRoom.cpp"
#endif
