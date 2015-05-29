//  Created by Tziak-Voon Wong

/** Chris-based implementation of EmergencyRoom
@file EmergencyRoom.cpp */

#include "EmergencyRoom.h"
#include <iostream>

EmergencyRoom::EmergencyRoom() {
	patientCount = 0;
	OR1 = new OperatingRoom;
	OR2 = new OperatingRoom;
	OR3 = new OperatingRoom;
}

EmergencyRoom::~EmergencyRoom() {
	delete OR1;
	delete OR2;
	delete OR3;
	patientCount = 0;
}

void EmergencyRoom::promptInput() {
	char end = ' ';

	do {
		patientInput();
		patientCount++;

		cout << "Is there another patient? (Y/N): ";
		cin >> end;
	} while (end == 'Y' || end == 'y');

	simHospital();
}

void EmergencyRoom::patientInput() {
	string name = "";
	int priorityValue = 0;
	int arrivalTime = 0;
	cout << "Patient's name: ";
	getline(cin, name);
	cout << "Priority value: ";
	cin >> priorityValue;

	//Patient newPatient(name, priorityValue, arrivalTime);
	//waitingRoom.add(newPatient);
}

void EmergencyRoom::simHospital() {
	// i have no idea how to do this...yet.
	/*char answer = ' ';
	cout << "Doc, would you like to review any of the patients files?" << endl;
	cin >> answer;
	if (answer == 'Y' || answer == 'y'){
		string userInput = "";
		do {
			cout << "Enter the name of the patient whose file you wish to review"
			<< endl;
			cin >> userInput;
			Patient foundPatient = waitingRoom.get(userInput);
			cout << foundPatient;

			cout << "Is there another patient whose file you would like to review? (Y/N): ";
			cin >> answer;
		} while (answer == 'Y' || answer == 'y');
	}
	*/

}

Patient EmergencyRoom::requestNextPatient() {
	return waitingRoom.peek();
}

void EmergencyRoom::displayQueueMovement() {
	// same case as simHospital
}