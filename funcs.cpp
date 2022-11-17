/*
    Author: Halil Akca
    Course: CSCI-135
    Instructor: Zamansky
    Assignment: Lab 10
    This program will perform all the tasks
*/

#include <iostream>
#include <cmath>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

void printTime(Time time) 
{
    std::cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time)
{
    return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later)
{
    int timeSince = later.h - earlier.h;
    timeSince *= 60;
    if(later.m > earlier.m)
    {
        timeSince += later.m - earlier.m;
    }
    else
    {
        int newLater = later.m + 60;
        timeSince -= 60;
        timeSince += later.m - earlier.m;
    }
    return timeSince;
}

Time addMinutes(Time time0, int min)
{
    Time timeFin;
    timeFin.m = time0.m + min;
    int hrs = 0;
    
    while(timeFin.m > 59)
    {
        timeFin.m -= 60;
        hrs++;
    }

    timeFin.h = time0.h + hrs;
    return timeFin;
}

std::string getTimeSlot(TimeSlot timeslot)
{

}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{

}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    
}