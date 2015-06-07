/** <description>
@file Patient.h */

#include <string>
#ifndef _PATIENT
#define _PATIENT

using namespace std;

class Patient
{
private:
	string name;
	int severity;
	int arrivalTime;
	int estimatedOperationTime;

public:
	/**
	* Default constructor
	* @pre none
	* @post .
	Name set to empty string. severity, arrival time and estimated operation time set to zero.
	*/
	Patient();

	Patient(string, int, int);

	~Patient();

	/**
	* Set the name of the patient.
	* @pre none
	* @post Calls patientInput if user inputs yes, otherwise call simHospital.
	*/
	void setName(string);

	/**
	* Set the severity and the estimated operation time based on the severity.
	* @pre none
	* @param an integer between 1 and 10.
	* @post Calls patientInput if user inputs yes, otherwise call simHospital.
	*/
	void setSeverity(int);

	void setEstimatedOperationTime(int);

	/**
	* Set the arrival time for each patient.
	* @pre none
	* @post Calls patientInput if user inputs yes, otherwise call simHospital.
	*/
	void setArrvalTime(int);

	/**
	* Get the name of the patient.
	* @pre none
	* @post Get getName.
	* @return name
	*/
	string getName() const;

	/**
	* Get the arrival time for the patient.
	* @pre none
	* @post Get arrivalTime.
	* @return arrival time.
	*/
	int getArrivalTime() const;

	int getPriorityValue() const;

	/**
	* Get the estimated operation time of the patient.
	* @pre none
	* @post Get estimateOoperationTime.
	* @return estimated operation time.
	*/
	int getEstimatedOperationTime() const;

}; // end Patient

#endif
