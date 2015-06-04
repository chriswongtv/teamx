#include <iostream>
#include "OperatingRoom.h"

using namespace std;

OperatingRoom::OperatingRoom() {
	theOneUnderTheKnife = nullptr;
	timeRemaining = 0;
}

bool OperatingRoom::isEmpty() {
	if (theOneUnderTheKnife == nullptr)
		return true;
	else
		return false;
}

void OperatingRoom::incomingPatient(Patient& patient) {
	theOneUnderTheKnife = &patient;
	setPatientName(patient.getName());
	setTimeRemaining(patient.getEstimatedOperationTime());
}

void OperatingRoom::setPatientName(string name) {
	patientName = name;
}

void OperatingRoom::setTimeRemaining(int severity) {
	timeRemaining = severity;
}

void OperatingRoom::update() {
	if (timeRemaining > 0)
		tick();
	else
		removePatient();
}

string OperatingRoom::getPatientName() {
	return patientName;
}

string OperatingRoom::getTimeRemaining() {
	if (timeRemaining == -1)
		return "          ";
	else
		return to_string(timeRemaining) + " min left";
}

void OperatingRoom::tick() {
	timeRemaining--;
}

void OperatingRoom::removePatient() {
	theOneUnderTheKnife = nullptr;
	patientName = "    ";
	timeRemaining = -1;
}