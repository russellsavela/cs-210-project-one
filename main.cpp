// Russ Savela
// russell.savela@snhu.edu
// July 14, 2025
//
// CS-210 Project One
//

#include "Clock.h"


int main() {

	// START Program

	// What to set the clock to
	int hours, minutes, seconds = 0;

	// Get User Input for Initial Time
	//  input validation was not specified,
	//  so test for any valid time.
	do {
		cout << endl << "Please enter initial time, as 3 integers for";
		cout << "hours, minutes, and seconds, separated by spaces" << endl;
		cout << ": ";

		cin >> hours >> minutes >> seconds;

	} while ((hours > 23) || (minutes > 59) || (seconds > 59));

	// Create a Clock object initialized with the time input
	Clock* myClock = new Clock(hours, minutes, seconds);


	
		// Clock::mainMenu() implmenents the event loop, so
		// when it completes, the program exits

		// -- the following flowchart steps are in mainMenu() --
			
		// LOOP
		// Display Menu(Process)
		// IF Add Hour ? (Decision)
		// Add Hour(Process)
		// Display Time(Process)
		// IF Add Minute ? (Decision)
		// Add Minute(Process)
		// Display Time(Process)
		// IF Add Second ? (Decision)
		// Add Second(Process)
		// Display Time(Process)
		// IF EXIT ? (Decision)

		myClock->mainMenu();

	// END Program
}