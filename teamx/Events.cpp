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

string Events::getName() {
	return name;
}

int Events::getSeverity() {
	return severity;
}

int Events::getArrivalTime() {
	return arrivalTime;
}

int Events::getPriorityValue() {
	return priorityValue;
}