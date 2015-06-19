/*
Program Description: Hospital simulator

Written By: Team 10 - Can Yildrim, Dan Zhong, Yoke Hui Fong, Tziak Voon Wong

Date Submitted: 06/16/2015

IDE Used: Visual Studio Ultimate 2013
*/
// All include statements starting from here
#include <iostream>
#include <string>
#include <iomanip>
#include "EmergencyRoom.h"

using namespace std;

// All global constants starting from here

// All function declaration starting from here

// It is extremely important that you document each function declaration
// with the required elements: purpose, preconditions, parameters, postconditions
// and returns.

/**
* Display a welcome message at the beginning of the program.
* @pre none
* @post A welcome message has been displayed.
*/
void hello();

/**
* Display a farewell message at the end of the program.
* @pre none
* @post A farewell message has been displayed.
*/
void goodBye();

// Main function
int main() {
	//display welcome screen
	hello();

	//create the emergency room class with 3 operating rooms
	EmergencyRoom er(3);

	//prompt the user for patient entry
	er.promptInput();

	//ask the user and handle patient review
	er.reviewPatient();

	//set the start time of the simulation based on 
	//the arrival time of the first patient
	er.setTime();

	//start the simulation
	er.simHospital();

	//display goodbye screen
	goodBye();
	return 0;
}

// All function definitions starting from here

void hello() {
	cout << endl << endl;

	cout << " __          __  _                          " << endl;
	cout << " \\ \\        / / | |                         " << endl;
	cout << "  \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___ " << endl;
	cout << "   \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ " << endl;
	cout << "    \\  /\\  /  __/ | (_| (_) | | | | | |  __/" << endl;
	cout << "     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|" << endl;

	cout << setw(20) << " _        " << endl;
	cout << setw(20) << "| |       " << endl;
	cout << setw(20) << "| |_ ___  " << endl;
	cout << setw(20) << "| __/ _ \\ " << endl;
	cout << setw(20) << "| || (_) |" << endl;
	cout << setw(20) << " \\__\\___/ " << endl;

	cout << "       __ __              _ __       __  _____            __     __          " << endl;
	cout << "      / // /__  ___ ___  (_) /____ _/ / / __(_)_ _  __ __/ /__ _/ /____  ____" << endl;
	cout << "     / _  / _ \\(_-</ _ \\/ / __/ _ `/ / _\\ \\/ /  ' \\/ // / / _ `/ __/ _ \\/ __/" << endl;
	cout << "    /_//_/\\___/___/ .__/_/\\__/\\_,_/_/ /___/_/_/_/_/\\_,_/_/\\_,_/\\__/\\___/_/   " << endl;
	cout << "                 /_/                                                         " << endl;
	
	cout << endl;
	
	cout << setw(70) << "+-+-+-+-+ +-+-+" << endl;
	cout << setw(70) << "|T|E|A|M| |1|0|" << endl;
	cout << setw(70) << "+-+-+-+-+ +-+-+" << endl;

	cout << endl;

	system("pause");
}

void goodBye() {
	system("cls");
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << " ________  ________  ________  ________  ________      ___    ___ _______      " << endl;
	cout << "|\\   ____\\|\\   __  \\|\\   __  \\|\\   ___ \\|\\   __  \\    |\\  \\  /  /|\\  ___ \\     " << endl;
	cout << "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\_|\\ \\ \\  \\|\\ /_   \\ \\  \\/  / | \\   __/|    " << endl;
	cout << " \\ \\  \\  __\\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\ \\\\ \\ \\   __  \\   \\ \\    / / \\ \\  \\_|/__" << endl;
	cout << "  \\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\_\\\\ \\ \\  \\|\\  \\   \\/  /  /   \\ \\  \\_|\\ \\" << endl;
	cout << "   \\ \\_______\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\__/  / /      \\ \\_______\\" << endl;
	cout << "    \\|_______|\\|_______|\\|_______|\\|_______|\\|_______|\\___/ /        \\|_______|" << endl;
	cout << "                                                     \\|___|/                   " << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;                                                    
}

/*
Copy program interaction between user and the program here.
*/