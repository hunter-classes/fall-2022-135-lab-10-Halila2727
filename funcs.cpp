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

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
std::string getTimeSlot(TimeSlot timeslot);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);