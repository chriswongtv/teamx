/** Evemts class implementation file
@file Events.cpp */

#include "Events.h"
#include <iostream>

Events::Events() {
	name = "";
	severity = 0;
	arrivalTime = 0;
	priorityValue = 0;
}

Events::Events(string n, int s, int t) {
	setName(n);
	setSeverity(s);
	setArrivalTime(t);
	setPriorityValue(t);
}

Events::~Events() {
	name = "";
	severity = 0;
	arrivalTime = 0;
	priorityValue = 0;
}

void Events::setName(string n) {
	name = n;
}
void Events::setSeverity(int s) {
	severity = s;
}

void Events::setArrivalTime(int t) {
	arrivalTime = t;
}

void Events::setPriorityValue(int t) {
	priorityValue = t * (-1);
}

string Events::getName() const {
	return name;
}

int Events::getSeverity() const {
	return severity;
}

int Events::getArrivalTime() const {
	return arrivalTime;
}

int Events::getPriorityValue() const {
	return priorityValue;
}

bool Events::operator>(Events& rhs) const {
	bool samePriority = true;
	bool sameArrivalTime = (arrivalTime == rhs.getArrivalTime());

	if (samePriority && !sameArrivalTime){
		if (arrivalTime < rhs.getArrivalTime()){
			return true;
		}
		else{
			return false;
		}
	}
	else if (!samePriority){
		if (severity >= rhs.getSeverity()){
			return true;
		}
		else{
			return false;
		}
	}
	else{

	}
}

bool Events::operator<=(Events& rhs) const {
	bool samePriority = true;
	bool sameArrivalTime = (arrivalTime == rhs.getArrivalTime());

	if (samePriority && !sameArrivalTime){
		if (arrivalTime > rhs.getArrivalTime()){
			return true;
		}
		else{
			return false;
		}
	}
	else if (!samePriority){
		if (severity <= rhs.getSeverity()){
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