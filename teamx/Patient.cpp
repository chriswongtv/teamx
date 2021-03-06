/** Patient class implementation file
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

bool Patient::operator>(Patient& rhs) const {
	bool samePriority = ( getPriorityValue() == rhs.getPriorityValue() );
	bool sameArrivalTime = ( getArrivalTime() == rhs.getArrivalTime() );

	if (samePriority && !sameArrivalTime){
		if (getArrivalTime() < rhs.getArrivalTime() ){
			return true;
		}
		else{
			return false;
		}
	}
	else if (!samePriority){
		if (getPriorityValue() > rhs.getPriorityValue()){
			return true;
		}
		else{
			return false;
		}
	}
	else{

	}
}

bool Patient::operator<=(Patient& rhs) const {
	bool samePriority = (getPriorityValue() == rhs.getPriorityValue());
	bool sameArrivalTime = (getArrivalTime() == rhs.getArrivalTime());

	if (samePriority && !sameArrivalTime){
		if (getArrivalTime() > rhs.getArrivalTime()){
			return true;
		}
		else{
			return false;
		}
	}
	else if (!samePriority){
		if (getPriorityValue() <= rhs.getPriorityValue()){
			return true;
		}
		else{
			return false;
		}
	}
	else if (samePriority && sameArrivalTime){
		return true;
	}
	else{

	}
}
