#include "Events.h"
#include <iostream>

Events::Events() {
	name = "";
	severity = 0;
	arrivalTime = 0;
}

Events::Events(string n, int s, int t) {
	setName(n);
	setSeverity(s);
	setArrivalTime(t);
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

string Events::getName() {
	return name;
}

int Events::getSeverity() {
	return severity;
}

int Events::getPriorityValue() {
	return arrivalTime;
}