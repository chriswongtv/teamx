/** Events class header file
@file Events.h */

#ifndef _EVENTS
#define _EVENTS

#include <string>
using namespace std;

class Events 
{
private:
	string name;		// Stores the patient's name
	int severity;		// Stores the patient's severity value
	int arrivalTime;	// Stores the patient's arrival time
	int priorityValue;	// Stores the patient's priority value
public:
	/**
	* Default constructor
	* @pre none
	* @post Name set to empty string.
			severity, arrival time and priority value set to zero.
	*/
	Events();

	/**
	* Copy constructor
	* @pre none
	* @param Patient's name in string, severity value and arrival time in integer.
	* @post Patient's name, severity, and arrival time are set to the values received.
	*/
	Events(string, int, int);

	/**
	* Destructor
	* @pre none
	* @post All private member functions are set to default values.
	*/
	~Events();

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
	* Sets the arrival time for the patient.
	* @pre none
	* @param An integer.
	* @post arrivalTime is set to the integer received.
	*/
	void setArrivalTime(int);

	/**
	* Sets the priority value.
	* @pre none
	* @param An integer.
	* @post priorityValue is set based on the value received.
	*/
	void setPriorityValue(int);

	/**
	* Gets the name of the patient.
	* @pre none
	* @post none
	* @return Name.
	*/
	string getName() const;

	/**
	* Gets the severity value of the patient.
	* @pre none
	* @post none
	* @return Severity.
	*/
	int getSeverity() const;

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

	bool operator>(Events&) const;

	bool operator<=(Events&) const;
};

#endif