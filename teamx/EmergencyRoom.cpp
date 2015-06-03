//  Created by Tziak-Voon Wong

/** Chris-based implementation of EmergencyRoom
@file EmergencyRoom.cpp */

#include "EmergencyRoom.h"
#include <iostream>
#include <iomanip>

EmergencyRoom::EmergencyRoom() {
	patientCount = 0;
	OR1 = new OperatingRoom;
	OR2 = new OperatingRoom;
	OR3 = new OperatingRoom;
	promptInput();
	//reviewPatient();
	setTime();
	simHospital();
}

EmergencyRoom::~EmergencyRoom() {
	delete OR1;
	delete OR2;
	delete OR3;
	patientCount = 0;
}

void EmergencyRoom::promptInput() {
	char end = ' ';
	/*
	do {
		patientInput();
		patientCount++;
		cout << "Is there another patient? (Y/N): ";
		cin.clear();
		cin >> end;
	} while (end == 'Y' || end == 'y');
	*/
	Patient newPatient("test", 7, 925);
	waitingRoom.add(newPatient);
}

void EmergencyRoom::patientInput() {
	string name = "";
	int priorityValue = 0;
	int arrivalTime = 0;
	cout << "Patient's name: ";
	cin.clear();
	getline(cin, name);
	cin.clear();
	cout << "Priority value: ";
	cin >> priorityValue;
	cout << "Arrival time (military time): ";
	cin >> arrivalTime;

	Patient newPatient(name, priorityValue, arrivalTime);
	waitingRoom.add(newPatient);
}

void EmergencyRoom::reviewPatient() {
	char answer = ' ';
	cout << "Doc, would you like to review any of the patients files?" << endl;
	cin >> answer;
	while (answer == 'Y' || answer == 'y'){
		string userInput = "";
		cout << "Enter the name of the patient whose file you wish to review"
			<< endl;
		cin >> userInput;
		//Patient foundPatient = waitingRoom.get(userInput);
		//cout << foundPatient;

		cout << "Is there another patient whose file you would like to review? (Y/N): ";
		cin >> answer;
	}
}

void EmergencyRoom::setTime() {
	int firstPatientTime = waitingRoom.peek().getArrivalTime();
	if ((firstPatientTime % 100) >= 5)
		currentTime = firstPatientTime - 5;
	else if ((firstPatientTime % 100) < 5)
		currentTime = (firstPatientTime / 100 - 1) * 100 + 60 + (firstPatientTime % 100) - 5;
}

void EmergencyRoom::simHospital() {
	bool end = false;
	while (end == false)//&waitingRoom.peek() != nullptr)
	{
		displayQueueMovement();
		cin.ignore();
	}
}

string EmergencyRoom::getCurrentTime() {
	string hour = "";
	string minute = "";
	string timeInString = to_string(currentTime);
	
	if (currentTime >= 1000)
	{
		hour = timeInString.substr(0, 2);
		minute = timeInString.substr(2, 3);
	}
	else
	{
		hour = "0" + timeInString.substr(0, 1);
		minute = timeInString.substr(1, 2);
	}

	timeInString = hour + ":" + minute;

	updateTime();

	return timeInString;
}

void EmergencyRoom::updateTime() {
	if ((currentTime % 100) == 59)
		currentTime = (currentTime / 100 + 1) * 100;
	else
		currentTime++;
}

string EmergencyRoom::getORPatientName(OperatingRoom&) {
	return "";
}

string EmergencyRoom::getORMinutes(OperatingRoom&) {
	return "";
}

Patient EmergencyRoom::requestNextPatient() {
	return waitingRoom.peek();
}

void EmergencyRoom::displayQueueMovement() {
	for (int i = 0; i < 79; i++)
		cout << "=";
	cout << endl;
	cout << "| " << getCurrentTime() << " |                           Operating Room                            |" << endl;

	cout << "|";
	for (int i = 0; i < 77; i++)
		cout << "=";
	cout << "|" << endl;

	cout << "|       | " << ".------------." << "  |       | " << ".------------." << "  |       | " << ".------------." << "  |" << endl;
	cout << "|       | " << "|            |" << "  |       | " << "|            |" << "  |       | " << "|            |" << "  |" << endl;
	cout << "|  O R  | " << "|    " << /*getName(1) <<*/ "    |" << "  |  O R  | " << "|    " << /*getName(2) <<*/ "    |" << "  |  O R  | " << "|    " << /*getName(3) <<*/ "    |" << "  |" << endl;
	cout << "|   1   | " << "| 5 min left |" << "  |   2   | " << "|            |" << "  |   3   | " << "|            |" << "  |" << endl;
	cout << "|       | " << "|            |" << "  |       | " << "|            |" << "  |       | " << "|            |" << "  |" << endl;
	cout << "|       | " << "'------------'" << "  |       | " << "'------------'" << "  |       | " << "'------------'" << "  |" << endl;

	cout << "|";
	for (int i = 0; i < 77; i++)
		cout << "=";
	cout << "|" << endl;

	cout << "| " << ".--------." << setw(67) << "|" << endl;
	cout << "| " << "| Carmen |" << setw(67) << "|" << endl;
	cout << "| " << "'--------'" << setw(67) << "|" << endl;
	cout << "| " << setw(77) << "|" << endl;
	cout << "| " << setw(77) << "|" << endl;
	cout << "| " << setw(77) << "|" << endl;
	cout << "| " << setw(77) << "|" << endl;
	cout << "| " << setw(77) << "|" << endl;
	cout << "| " << setw(77) << "|" << endl;
	cout << "| " << setw(77) << "|" << endl;
	cout << "| " << setw(77) << "|" << endl;
	cout << "| " << setw(77) << "|" << endl;
	cout << "| " << setw(77) << "|" << endl;
	for (int i = 0; i < 79; i++)
		cout << "=";
	cout << endl;
}