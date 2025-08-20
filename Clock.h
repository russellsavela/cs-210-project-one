#pragma once
#ifndef CLOCK_H
#define CLOCK_H

#include <string>
#include <iostream>

// Russ Savela
// russell.savela@snhu.edu
// July 14, 2025
//
// CS-210 Project One
//

using namespace std;

// This Implements a Clock class.  The clock can
// be used by the get and set member functions, or
// an interactive clock demo is provided by the 
// mainMenu member function.

class Clock
{
private:
    unsigned int second;
    unsigned int minute;
    unsigned int hour;

    string nCharString(unsigned int n, char c);
    string twoDigitString(unsigned int n);
    string formatTime24(unsigned int h, unsigned int m, unsigned int s);
    string formatTime12(unsigned int h, unsigned int m, unsigned int s);
    void printMenu(char* strings[], unsigned int numStrings, unsigned char width);
    unsigned int getMenuChoice(unsigned int maxChoice);
    void displayClocks(unsigned int h, unsigned int m, unsigned int s);

    void addOneSecond();
    void addOneMinute();
    void addOneHour();

public:

    // default constructor
    Clock(); 

    Clock(unsigned int hour, unsigned int minute, unsigned int second);

    // changed from the exercises, to take a menu_choice argument
    void mainMenu();

    unsigned int getSecond();
    unsigned int getMinute();
    unsigned int getHour();

    void setSecond(unsigned int newSecond);
    void setMinute(unsigned int newMinute);
    void setHour(unsigned int newHour);

};


#endif 