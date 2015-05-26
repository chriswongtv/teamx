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
	cout << "Patient's name: ";
	getline(cin, name);
	cout << "Priority value: ";
	cin >> priorityValue;

	Patient newPatient(name, priorityValue);
	waitingRoom.add(newPatient);
}

void EmergencyRoom::simHospital() {
	// i have no idea how to do this...yet.
}

Patient EmergencyRoom::requestNextPatient() {
	return waitingRoom.peek();
}

void EmergencyRoom::displayQueueMovement() {
	// same case as simHospital
}