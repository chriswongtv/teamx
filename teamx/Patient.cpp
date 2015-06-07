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

Patient::Patient(string n, int s, int a) {
	setName(n);
	setSeverity(s);
	setArrvalTime(a);
}

Patient::~Patient() {
	name = "";
	severity = 0;
	arrivalTime = 0;
	estimatedOperationTime = 0;
}

void Patient::setName(string n) {
	name = n;
}

void Patient::setSeverity(int s) {
	severity = s;
	setEstimatedOperationTime(s);
}

void Patient::setEstimatedOperationTime(int s) {
	estimatedOperationTime = s;
}

void Patient::setArrvalTime(int a) {
	arrivalTime = a;
}

string Patient::getName() const {
	return name;
}

int Patient::getArrivalTime() const {
	return arrivalTime;
}

int Patient::getPriorityValue() const {
	return severity;
}

int Patient::getEstimatedOperationTime() const {
	return estimatedOperationTime;
}