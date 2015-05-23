/** <description>
@file OperatingRoom.h */

#ifndef _OPERATING_ROOM
#define _OPERATING_ROOM

class OperatingRoom// one per thread
{
private:
	Patient theOneUnderTheKnife;
	int timeRemaining;
public:
	OperatingRoom();

	void update();//updates timer and checks for

}; // end OperatingRoom

//#include "OperatingRoom.cpp"
#endif
