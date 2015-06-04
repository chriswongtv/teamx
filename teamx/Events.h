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
public:
	Events();
	Events(string, int, int);
	~Events();
	void setName(string);
	void setSeverity(int);
	void setArrivalTime(int);
	string getName();
	int getSeverity();
	int getPriorityValue();
};

#endif