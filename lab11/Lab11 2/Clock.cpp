/* 
 * File:   Clock.cpp
 * Purpose: to provide the definition of the class named Clock
 * Author: <your name>
 *
 */

#include "Clock.h"

using namespace std;

Clock::Clock()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}
    
Clock::Clock(int hh, int mm, int ss)
{
    if (hh < 0 || mm < 0 || ss < 0)
    {    
        cout << "Invalid time! Reset to 0:0:0" << endl;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    else 
    {
        hours = hh;
        minutes = mm;
        seconds = ss;
        adjustClock();
    }
}

void Clock::setClock(int hh, int mm, int ss)
{
    if (hh < 0 || mm < 0 || ss < 0)
    {    
        cout << "Invalid time! Reset to 0:0:0" << endl;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    else 
    {
        hours = hh;
        minutes = mm;
        seconds = ss;
        adjustClock();
    }    
}

//increase time by sec seconds
void Clock::incrementSeconds(int sec)
{
    seconds = seconds + sec;
    adjustClock();
}

//increase time by min minutes
void Clock::incrementMinutes(int min)
{
    minutes = minutes + min;
    adjustClock();
}

//increase time by hh hours, 
//if hours reach 24, simply wrap around to 0.
void Clock::incrementHours(int hh)
{
    hours = hours + hh;
    adjustClock();
}

void Clock::addTime(Clock C) //add C into the clock
{
    hours = hours + C.hours;
    minutes = minutes + C.minutes;
    seconds = seconds + C.seconds;
    adjustClock();
}

ostream &operator<<(ostream &out, const Clock &C)
{
   return (out << C.hours << " : " << C.minutes <<" : " << C.seconds); 
}

bool operator>(Clock C1, Clock C2)
{
    if (C1.hours > C2.hours)
        return true;
    if (C1.hours < C2.hours)
        return false;
    if (C1.minutes > C2.minutes)
        return true;
    if (C1.minutes < C2.minutes)
        return false;
    if (C1.seconds > C2.seconds)
        return true;
    else 
        return false;     
}

void Clock::adjustClock()
{
    int adjust = 0;
    if (seconds >= 60)
    {
        adjust = seconds / 60;
        seconds = seconds % 60;
        minutes = minutes + adjust;
    }
    if (minutes >= 60)
    {
        adjust = minutes / 60;
        minutes = minutes % 60;
        hours = hours + adjust;
    }
    if (hours >= 24)
        hours = hours % 24;
}


