/** <description>
@file EmergencyRoom.h */

#ifndef _EMERGENCY_ROOM
#define _EMERGENCY_ROOM

class EmergencyRoom
{
private:
	OperatingRoom* OR;
	PriorityQueue waitingRoom;
public:
	EmergencyRoom();
	EmergencyRoom(int ORcount);

	Patient requestNextPatient();

}; // end EmergencyRoom

//#include "EmergencyRoom.cpp"
#endif
