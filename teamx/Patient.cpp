//  Created by Yoke Hui Fong

/** Yoke-based implementation of Patient
@file Patient.cpp */

#include "Patient.h"
#include <iostream>
#include <string>

Patient::Patient() {
	name = "";
	severity = 0;
	arrivalTime = 0;
	estimatedOperationTime = 0;
}

string Patient::setName() {
	return "";
}

int Patient::setArrvalTime() {
	return 0;
}

int Patient::setSeverity() {
	return 0;
}

string Patient::getName() {
	return name;
}

int Patient::getArrivalTime() {
	return arrivalTime;
}

int Patient::getPriorityValue() {
	return -1;
}

int Patient::getEstimatedOperationTime() {
	return estimatedOperationTime;
}