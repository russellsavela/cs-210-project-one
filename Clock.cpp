// Russ Savela
// russell.savela@snhu.edu
// July 14, 2025
//
// CS-210 Project One
//

#include "Clock.h"

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

// Constructor definition
Clock::Clock() {
    hour = 0;
    minute = 0;
    second = 0;
};

Clock::Clock(unsigned int newHour, unsigned int newMinute, unsigned int newSecond) {

    hour = newHour;
    minute = newMinute;
    second = newSecond;

};


void Clock::setSecond(unsigned int newSecond) {
        second = newSecond;
 };
    
void Clock::setMinute(unsigned int newMinute) {
        minute = newMinute;
};
   
void Clock::setHour(unsigned int newHour) {
    hour = newHour;
};


unsigned int Clock::getSecond() {
        return (second);
};
unsigned int Clock::getMinute() {
        return (minute);
};
unsigned int Clock::getHour() {
        return (hour);
 };

// Return a string of n characters 'c'
string Clock::nCharString(unsigned int n, char c) {
        
        std::string result_string = "";

        for (unsigned int i = 0; i < n; i++) {
            result_string += c;
        }

        // return the n character string
        return (result_string);
 }

// Given an integer, return a string, prepended with 0 if a single digit
string Clock::twoDigitString(unsigned int n) {

        std::string result_string = "";
        // TODO: your code here to implement the method
        // Numbers between 10 and 59 just need to be converted to a string
        // Numbers from 0 to 9 need a "O" tacked onto the front of the string representation of the number

        if (n > 9) {
            // 2 digit number, easy
            result_string = to_string(n);
        }
        else if (n < 10) {
            // prepend a zero
            result_string = "0";
            result_string.append(to_string(n));
        }

        // Return the two digit string representation of n
        return (result_string);
}

// Format a 24 hour time string
string Clock::formatTime24(unsigned int h, unsigned int m, unsigned int s) {

        string result_string = "";

        result_string.append(twoDigitString(h));
        result_string.append(":");
        result_string.append(twoDigitString(m));
        result_string.append(":");
        result_string.append(twoDigitString(s));

        // return time as hh:mm:ss

        return(result_string);
}

// Format a 12 hour time string. 
string Clock::formatTime12(unsigned int h, unsigned int m, unsigned int s) {

        string result_string = "";

        // check for PM
        if (h == 0) {
            // PM Time display
            result_string.append(twoDigitString(12));
            result_string.append(":");
            result_string.append(twoDigitString(m));
            result_string.append(":");
            result_string.append(twoDigitString(s));
            result_string.append(" A M");
        }
        else if (h == 12) {
            // PM Time display
            result_string.append(twoDigitString(12));
            result_string.append(":");
            result_string.append(twoDigitString(m));
            result_string.append(":");
            result_string.append(twoDigitString(s));
            result_string.append(" P M");
        }
        else if (h > 12) {
            // PM Time display
            result_string.append(twoDigitString(h - 12));
            result_string.append(":");
            result_string.append(twoDigitString(m));
            result_string.append(":");
            result_string.append(twoDigitString(s));
            result_string.append(" P M");
        }
        else {
            result_string.append(twoDigitString(h));
            result_string.append(":");
            result_string.append(twoDigitString(m));
            result_string.append(":");
            result_string.append(twoDigitString(s));
            result_string.append(" A M");
        }

        return (result_string);
}


// Print a menue, given an array of C-style strings, the number of stings, and a width for the menu
void Clock::printMenu(char* strings[], unsigned int numStrings, unsigned char width) {


        cout << nCharString(width, '*') << endl;

        for (unsigned int i = 0; i < numStrings; i++) {
            cout << "* " << (i + 1) << " - " << strings[i];
            cout << nCharString((width - (static_cast<unsigned int> (strlen(strings[i]) + 7))), ' ') << "*" << endl;
            if (i != (numStrings - 1)) {
                cout << endl;
            }
        }

        // outside the loop print another width *s followed by an endl
        cout << nCharString(width, '*') << endl;

}

// Perform input validation and return a menu selection   
unsigned int Clock::getMenuChoice(unsigned int maxChoice) {

        unsigned int input = 0;


        while (true) {
            std::cin >> input;
            if ((input > 0) && (input <= maxChoice)) {
                break;
            }
        }

        // return the value
        return (input);
    }

// Display 2 clocks, 12 and 24 hour, side by side.   
void Clock::displayClocks(unsigned int h, unsigned int m, unsigned int s) {


    // cout 27 stars + 3 spaces + 27 stars + endl
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    // cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
    cout << "*      " << "12-HOUR CLOCK" << "      *   ";
    // cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
    cout << "*      " << "24-HOUR CLOCK" << "      *" << endl;
    // cout an endl for a blank line
    cout << endl;
    // cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces
    cout << "*      " << formatTime12(h, m, s) << "       *   ";
    // cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl
    cout << "*        " << formatTime24(h, m, s) << "         *" << endl;
    // cout 27 stars + 3 spaces + 27 stars + endl
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

void Clock::mainMenu() {

  
        bool should_exit = false;
        unsigned int menu_choice = 0;

        // the print menu member function expects C style strings
        char* menuItems[] = { (char*)"Add One Hour", (char*)"Add One Minute", (char*)"Add One Second", (char*)"Exit Program" };


        while (!should_exit) {

            printMenu(menuItems, 4, 27);

            menu_choice = getMenuChoice(4);

            switch (menu_choice) {
            case 1:
                addOneHour();
                break;
            case 2:
                addOneMinute();
                break;
            case 3:
                addOneSecond();
                break;
            case 4:
                should_exit = true;
                break;
            }

            // Oddly, the flowchart does not call for displaying the
            // time until after time has been added.

            displayClocks(
                getHour(),
                getMinute(),
                getSecond());

        }

        // Exit(Process)
        // END LOOP

        // nothing to return, just call the appropriate methods
}


void Clock::addOneSecond() {

        if (getSecond() < 59) {
            setSecond(getSecond() + 1);
        }
        else {
            setSecond(0);
            addOneMinute();
        }

        // nothing to return, just call setSecond() with the right value and addOneMinute() when needed
 }


void Clock::addOneMinute() {

        if (getMinute() < 59) {
            setMinute(getMinute() + 1);
        }
        else {
            setMinute(0);
            addOneHour();
        }

        // nothing to return, just setMinute to the appropriate value and use addOneHour if needed
    }


void Clock::addOneHour() {

        if (getHour() < 23) {
            setHour(getHour() + 1);
        }
        else {
            setHour(0);
        }
        // nothing to return, just setHour to the appropriate value
}

