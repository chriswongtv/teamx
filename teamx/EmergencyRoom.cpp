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
	reviewPatient();
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

	system("cls");

	for (int i = 0; i < 80; i++)
		cout << "=";
	cout << "|                                 PATIENT INPUT                                |";
	for (int i = 0; i < 80; i++)
		cout << "=";

	do {
		patientInput();
		patientCount++;
		cout << "Is there another patient? (Y/N): ";
		cin.clear();
		cin >> end;
	} while (end == 'Y' || end == 'y');

	/*Events newPatient("tes1", 8, 925);
	Events newPatient2("tes2", 6, 926);
	Events newPatient3("tes3", 6, 927);
	Events newPatient4("tes4", 7, 928);
	Events newPatient5("tes5", 5, 929);
	Events newPatient6("tes6", 6, 930);
	Events newPatient7("tes7", 7, 931);
	Events newPatient8("tes8", 8, 932);
	Events newPatient9("tes9", 9, 933);
	events.add(newPatient);
	events.add(newPatient2);
	events.add(newPatient3);
	events.add(newPatient4);
	events.add(newPatient5);
	events.add(newPatient6);
	events.add(newPatient7);
	events.add(newPatient8);
	events.add(newPatient9);*/
}

void EmergencyRoom::patientInput() {
	string name = "";
	int priorityValue = 0;
	int arrivalTime = 0;
	cout << "Patient's name: ";
	cin >> name;
	do {
		cout << "Priority value: ";
		cin >> priorityValue;
	} while (priorityValue < 1 || priorityValue > 10);

	do {
		cout << "Arrival time (military time): ";
		cin >> arrivalTime;
	} while (arrivalTime < 0 || arrivalTime > 2359);

	Events newEvent(name, priorityValue, arrivalTime);
	Patient newPatient(name, priorityValue, arrivalTime);
	events.add(newEvent);
	patients[patientCount] = newPatient;
}

void EmergencyRoom::reviewPatient() {
	system("cls");

	for (int i = 0; i < 80; i++)
		cout << "=";
	cout << "|                                PATIENT REVIEW                                |";
	for (int i = 0; i < 80; i++)
		cout << "=";

	char answer = ' ';
	cout << "Doc, would you like to review any of the patients files? (Y/N): ";
	cin >> answer;
	while (answer == 'Y' || answer == 'y'){
		string userInput = "";
		cout << "Enter the name of the patient whose file you wish to review: ";
		cin >> userInput;

		bool found = false;
		Patient *foundPatient = nullptr;
		for (int currentIndex = 0; currentIndex <= patientCount; currentIndex++){
			if (userInput == patients[currentIndex].getName()){
				foundPatient = &patients[currentIndex];
				cout << "Name: " << foundPatient->getName() << endl;
				cout << "Severity: " << foundPatient->getPriorityValue() << endl;
				cout << "Arrival Time: " << timeInString(foundPatient->getArrivalTime()) << endl;
				found = true;
				break;
			}
		}
		if (!found){
			cout << userInput << " has not been found!" << endl;
		}

		cout << "Is there another patient whose file you would like to review? (Y/N): ";
		cin >> answer;
		cout << endl;
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

	system("cls");

	while (end == false)
	{
		patientCount = 0;

		moveArrayToQueue();

		while (isPatientIncoming())
			movePatient();

		if (OR1->isEmpty() && !waitingRoom.isEmpty())
		{
			OR1->incomingPatient(requestNextPatient());
			waitingRoom.remove();
			waitingRoomDisplay.remove();
			patientCount--;
		}

		if (OR2->isEmpty() && !waitingRoom.isEmpty())
		{
			OR2->incomingPatient(requestNextPatient());
			waitingRoom.remove();
			waitingRoomDisplay.remove();
			patientCount--;
		}

		if (OR3->isEmpty() && !waitingRoom.isEmpty())
		{
			OR3->incomingPatient(requestNextPatient());
			waitingRoom.remove();
			waitingRoomDisplay.remove();
			patientCount--;
		}

		updateWaitingRoomArray();

		displayQueueMovement();
		OR1->update();
		OR2->update();
		OR3->update();
		cin.ignore();

		if (OR1->isEmpty() && OR2->isEmpty() && OR3->isEmpty() && waitingRoom.isEmpty() && events.isEmpty())
			end = true;
	}
}

void EmergencyRoom::moveArrayToQueue() {
	for (int i = 0; i < waitingRoomCount; i++)
		waitingRoomDisplay.add(waitingRoomArray[i]);

	waitingRoomCount = 0;
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
	waitingRoomDisplay.add(newPatient);
	patientCount++;
}

void EmergencyRoom::updateWaitingRoomArray() {
	for (int i = 0; !waitingRoomDisplay.isEmpty(); i++)
	{
		waitingRoomArray[i] = waitingRoomDisplay.peek();
		waitingRoomDisplay.remove();
		waitingRoomCount++;
	}
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
	cout << "| " << getCurrentTime() << " |                           OPERATING ROOM                            |" << endl;

	cout << "|";
	for (int i = 0; i < 77; i++)
		cout << "=";
	cout << "|" << endl;

	cout << "|       | " << ".------------."					<< "  |       | " << ".------------." << "  |       | " << ".------------." << "  |" << endl;
	cout << "|       | " << "|            |"					<< "  |       | " << "|            |" << "  |       | " << "|            |" << "  |" << endl;
	cout << "|  O R  | " << "|    " << setw(4) << OR1->getPatientName() << "    |  |  O R  | " << "|    " << setw(4) << OR2->getPatientName() << "    |" << "  |  O R  | " << "|    " << setw(4) << OR3->getPatientName() << "    |" << "  |" << endl;
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
			cout << "| " << setw(4) << waitingRoomArray[i].getName() << " " << waitingRoomArray[i].getPriorityValue() << " " << timeInString(waitingRoomArray[i].getArrivalTime()) << " | ";
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

	cout << "| " << setw(77) << "|" << endl;

	cout << "| ";
	for (int i = 4; i < 8; i++)
	{
		if (i < waitingRoomCount)
			cout << ".--------------. ";
		else
			cout << "                 ";
	}
	cout << "        |" << endl;

	cout << "| ";
	for (int i = 4; i < 8; i++)
	{
		if (i < waitingRoomCount)
			cout << "| " << setw(4) << waitingRoomArray[i].getName() << " " << waitingRoomArray[i].getPriorityValue() << " " << timeInString(waitingRoomArray[i].getArrivalTime()) << " | ";
		else
			cout << "                 ";
	}
	cout << "        |" << endl;

	cout << "| ";
	for (int i = 4; i < 8; i++)
	{
		if (i < waitingRoomCount)
			cout << "'--------------' ";
		else
			cout << "                 ";
	}
	cout << "        |" << endl;

	cout << "| " << setw(77) << "|" << endl;

	cout << "| ";
	for (int i = 8; i < 10; i++)
	{
		if (i < waitingRoomCount)
			cout << ".--------------. ";
		else
			cout << "                 ";
	}

	cout << "               .------------------------. |" << endl;

	cout << "| ";
	for (int i = 8; i < 10; i++)
	{
		if (i < waitingRoomCount)
			cout << "| " << setw(4) <<waitingRoomArray[i].getName() << " " << waitingRoomArray[i].getPriorityValue() << " " << timeInString(waitingRoomArray[i].getArrivalTime()) << " | ";
		else
			cout << "                 ";
	}
	if (!events.isEmpty())
		cout << "               | INCOMING: " << setw(4) << events.peek().getName() << " " << events.peek().getSeverity() << " " << timeInString(events.peek().getArrivalTime()) << " | |" << endl;
	else
		cout << "               | INCOMING: " << setw(16) << "| |" << endl;

	cout << "| ";
	for (int i = 8; i < 10; i++)
	{
		if (i < waitingRoomCount)
			cout << "'--------------' ";
		else
			cout << "                 ";
	}
	cout << "               '------------------------' |" << endl;

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