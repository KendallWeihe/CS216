/* 
 * File:   Clock.h
 * Purpose: Provide the declaration of the class named Clock
 *          to represent the time in 24-hour format
 * Author: <your name>
 *
 */

#ifndef CLOCK_H
#define	CLOCK_H

#include <iostream>

using namespace std;

class Clock
{
   public:
    Clock(); // default constructor
    Clock(int hh, int mm, int ss); 	//constructor
        
    // set time to hh:mm:ss
    void setClock(int hh, int mm, int ss);

    //increase time by sec seconds
    void incrementSeconds(int sec); 

    //increase time by min minutes
    void incrementMinutes(int min); 

    //increase time by hh hours, 
    //if hours reach 24, simply wrap around to 0.
    void incrementHours(int hh); 

    void addTime(Clock C); //add C into the current time
    
    friend ostream &operator<<(ostream &out, const Clock &C);
    friend bool operator>(Clock C1, Clock C2);
        
   private:
    // Declare data members of the class
    // 0 <= hours < 24, 0 <= minutes < 60, 0 <= seconds < 60
    int hours, minutes, seconds;
        
    //make sure the data members are in the valid range
    void adjustClock();
};


#endif	/* CLOCK_H */
