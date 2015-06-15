/** Patient class header file
@file Patient.h */

#include <string>
#ifndef _PATIENT
#define _PATIENT

using namespace std;

class Patient
{
private:
	string name;				// Stores the patient's name
	int severity;				// Stores the patient's severity value
	int arrivalTime;			// Stores the patient's arrival time
	int estimatedOperationTime;	// Stores the patient's estimated operation time
public:
	/**
	* Default constructor
	* @pre none
	* @post Name set to empty string. 
			severity, arrival time and estimated operation time set to zero.
	*/
	Patient();

	/**
	* Copy constructor
	* @pre none
	* @param Patient's name in string, severity value and arrival time in integer.
	* @post Patient's name, severity, and arrival time are set to the values received.
	*/
	Patient(string, int, int);

	/**
	* Destructor
	* @pre none
	* @post All private member functions are set to default values.
	*/
	~Patient();

	/**
	* Set the name of the patient.
	* @pre none
	* @param A string.
	* @post name is set to the string received.
	*/
	void setName(string);

	/**
	* Set the severity and the estimated operation time based on the severity.
	* @pre none
	* @param An integer between 1 and 10.
	* @post severity is set to the integer received.
	*/
	void setSeverity(int);

	/**
	* Sets the estimated operation time.
	* @pre none
	* @param An integer.
	* @post estimatedOperationTime is set based on the value received.
	*/
	void setEstimatedOperationTime(int);

	/**
	* Sets the arrival time for the patient.
	* @pre none
	* @param An integer.
	* @post arrivalTime is set to the integer received.
	*/
	void setArrvalTime(int);

	/**
	* Gets the name of the patient.
	* @pre none
	* @post none
	* @return Name.
	*/
	string getName() const;

	/**
	* Gets the arrival time of the patient.
	* @pre none
	* @post none
	* @return Arrival time.
	*/
	int getArrivalTime() const;

	/**
	* Gets the priority value of the patient.
	* @pre none
	* @post none
	* @return Priority value.
	*/
	int getPriorityValue() const;

	/**
	* Gets the estimated operation time of the patient.
	* @pre none
	* @post none
	* @return Estimated operation time.
	*/
	int getEstimatedOperationTime() const;

	bool operator>(Patient&) const;

	bool operator<=(Patient&) const;
}; // end Patient

#endif
