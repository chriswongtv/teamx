//  Created by TYoke Hui Fong

/** Yoke-based implementation of Patient
@file Patirnt.cpp */

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
	
}

int Patient::setArrvalTime() {
	
}

int Patient::setSeverity() {

}

string Patient::getName() {
	return name;
}

int Patient::getArrivalTime() {
	return arrivalTime;
}

int Patient::getEstimatedOperationTime() {
	return estimatedOperationTime;
}