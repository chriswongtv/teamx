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
	Events newPatient("tes1", 7, 925);
	Events newPatient2("tes2", 5, 927);
	Events newPatient3("tes3", 4, 925);
	Events newPatient4("tes4", 8, 929);
	Events newPatient5("tes5", 1, 926);
	events.add(newPatient);
	events.add(newPatient2);
	events.add(newPatient3);
	events.add(newPatient4);
	events.add(newPatient5);
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

	Events newPatient(name, priorityValue, arrivalTime);
	events.add(newPatient);
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
	const int minsBeforeFirstEvent = 5;

	int firstPatientTime = events.peek().getArrivalTime();
	if ((firstPatientTime % 100) >= minsBeforeFirstEvent)
		currentTime = firstPatientTime - minsBeforeFirstEvent;
	else if ((firstPatientTime % 100) < minsBeforeFirstEvent)
		currentTime = (firstPatientTime / 100 - 1) * 100 + 60 + (firstPatientTime % 100) - minsBeforeFirstEvent;
}

void EmergencyRoom::simHospital() {
	bool end = false;

	while (end == false)
	{
		while (incomingPatient())
			movePatient();

		if (OR1->isEmpty() && waitingRoom.isEmpty() == false)
		{
			OR1->incomingPatient(requestNextPatient());
			waitingRoom.remove();
		}

		if (OR2->isEmpty() && waitingRoom.isEmpty() == false)
		{
			OR2->incomingPatient(requestNextPatient());
			waitingRoom.remove();
		}

		if (OR3->isEmpty() && waitingRoom.isEmpty() == false)
		{
			OR3->incomingPatient(requestNextPatient());
			waitingRoom.remove();
		}
			
		displayQueueMovement();
		OR1->update();
		OR2->update();
		OR3->update();
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

bool EmergencyRoom::incomingPatient() {
	if (!events.isEmpty())
	{
		if (events.peek().getArrivalTime() == currentTime)
			return true;
		else
			return false;
	}
	else 
		return false;
}

void EmergencyRoom::movePatient() {
	string name = events.peek().getName();
	int severity = events.peek().getSeverity();
	int arrivalTime = events.peek().getPriorityValue();
	Patient newPatient(name, severity, arrivalTime);
	waitingRoom.add(newPatient);
	events.remove();
}

void EmergencyRoom::updateTime() {
	if ((currentTime % 100) == 59)
		currentTime = (currentTime / 100 + 1) * 100;
	else
		currentTime++;
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

	cout << "|       | " << ".------------."					<< "  |       | " << ".------------." << "  |       | " << ".------------." << "  |" << endl;
	cout << "|       | " << "|            |"					<< "  |       | " << "|            |" << "  |       | " << "|            |" << "  |" << endl;
	cout << "|  O R  | " << "|    " << OR1->getPatientName() << "    |  |  O R  | " << "|    " << OR2->getPatientName() << "    |" << "  |  O R  | " << "|    " << OR3->getPatientName() << "    |" << "  |" << endl;
	cout << "|   1   | " << "| " << OR1->getTimeRemaining()	<< " |  |   2   | " << "| " << OR2->getTimeRemaining() << " |  |   3   | " << "| " << OR3->getTimeRemaining() << " |  |" << endl;
	cout << "|       | " << "|            |" << "  |       | "	<< "|            |" << "  |       | " << "|            |" << "  |" << endl;
	cout << "|       | " << "'------------'" << "  |       | "	<< "'------------'" << "  |       | " << "'------------'" << "  |" << endl;

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