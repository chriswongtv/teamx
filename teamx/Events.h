#ifndef _EVENTS
#define _EVENTS

#include <string>
using namespace std;

class Events 
{
private:
	string name;
	int severity;
	int arrivalTime;
	int priorityValue;
public:
	Events();
	Events(string, int, int);
	~Events();
	void setName(string);
	void setSeverity(int);
	void setArrivalTime(int);
	void setPriorityValue(int);
	string getName();
	int getSeverity();
	int getArrivalTime();
	int getPriorityValue();
};

#endif