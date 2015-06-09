//  Created by Tziak-Voon Wong

/** Chris-based implementation of EmergencyRoom
@file EmergencyRoom.cpp */

#include "EmergencyRoom.h"
#include <iostream>
#include <iomanip>

EmergencyRoom::EmergencyRoom() {
	patientCount = 0;
	waitingRoomCount = 0;
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
	Events newPatient("tes1", 1, 925);
	Events newPatient2("tes2", 2, 926);
	Events newPatient3("tes3", 3, 927);
	Events newPatient4("tes4", 4, 928);
	Events newPatient5("tes5", 5, 929);
	Events newPatient6("tes6", 6, 930);
	Events newPatient7("tes7", 7, 931);
	Events newPatient8("tes8", 8, 932);
	Events newPatient9("tes9", 9, 933);
	//Events newPatient10("te10", 1, 934);
	events.add(newPatient);
	events.add(newPatient2);
	events.add(newPatient3);
	events.add(newPatient4);
	events.add(newPatient5);
	events.add(newPatient6);
	events.add(newPatient7);
	events.add(newPatient8);
	events.add(newPatient9);
	//events.add(newPatient10);
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
		patientCount = 0;
		waitingRoomCount = 0;

		while (isPatientIncoming())
			movePatient();

		if (OR1->isEmpty() && !waitingRoom.isEmpty())
		{
			OR1->incomingPatient(requestNextPatient());
			waitingRoom.remove();
			removeWaitingRoomArray();
			patientCount--;
		}

		if (OR2->isEmpty() && !waitingRoom.isEmpty())
		{
			OR2->incomingPatient(requestNextPatient());
			waitingRoom.remove();
			removeWaitingRoomArray();
			patientCount--;
		}

		if (OR3->isEmpty() && !waitingRoom.isEmpty())
		{
			OR3->incomingPatient(requestNextPatient());
			waitingRoom.remove();
			removeWaitingRoomArray();
			patientCount--;
		}

		displayQueueMovement();
		OR1->update();
		OR2->update();
		OR3->update();
		cin.ignore();

		if (OR1->isEmpty() && OR2->isEmpty() && OR3->isEmpty() && waitingRoom.isEmpty() && events.isEmpty())
			end = true;
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

bool EmergencyRoom::isPatientIncoming() {
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
	int arrivalTime = events.peek().getArrivalTime();
	Patient newPatient(name, severity, arrivalTime);
	waitingRoom.add(newPatient);
	events.remove();
	updateWaitingRoomArray(newPatient);
	patientCount++;
}

void EmergencyRoom::updateWaitingRoomArray(Patient& patient) {
	waitingRoomArray[waitingRoomCount] = patient;
	waitingRoomCount++;
}

void EmergencyRoom::removeWaitingRoomArray() {
	for (int i = 0; i < waitingRoomCount; i++)
	{
		waitingRoomArray[i] = waitingRoomArray[i + 1];
	}

	waitingRoomCount--;
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
	
	cout << "| ";
	for (int i = 0; i < 4; i++)
	{
		if (i < waitingRoomCount)
			cout << ".--------------. ";
		else
			cout << "                 ";
	}
	cout << "        |" << endl;

	cout << "| ";
	for (int i = 0; i < 4; i++)
	{
		if (i < waitingRoomCount)
			cout << "| " << waitingRoomArray[i].getName() << " " << waitingRoomArray[i].getPriorityValue() << " " << timeInString(waitingRoomArray[i].getArrivalTime()) << " | ";
		else
			cout << "                 ";
	}
	cout << "        |" << endl;

	cout << "| ";
	for (int i = 0; i < 4; i++)
	{
		if (i < waitingRoomCount)
			cout << "'--------------' ";
		else
			cout << "                 ";
	}
	cout << "        |" << endl;

	//cout << "| " << "| John 7 09:10 |" << setw(61) << "|" << endl;
	//cout << "| " << "'--------------'" << setw(61) << "|" << endl;
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

string EmergencyRoom::timeInString(int t) {
	string hour = "";
	string minute = "";

	if (t < 0)
		t *= (-1);

	string time = to_string(t);

	if (currentTime >= 1000)
	{
		hour = time.substr(0, 2);
		minute = time.substr(2, 3);
	}
	else
	{
		hour = "0" + time.substr(0, 1);
		minute = time.substr(1, 2);
	}

	time = hour + ":" + minute;

	return time;
}