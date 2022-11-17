/*
    Author: Halil Akca
    Course: CSCI-135
    Instructor: Zamansky
    Assignment: Lab 10
    This program will perform all the tasks
*/

#include <iostream>
#include <cmath>
#include <string>
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

std::string getMovie(Movie movie)
{
    std::string str = "";
    switch(movie.genre)
    {
        case ACTION : str = "ACTION"; break;
        case COMEDY : str = "COMEDY"; break;
        case DRAMA  : str = "DRAMA";  break;
        case ROMANCE: str = "ROMANCE"; break;
        case THRILLER   : str = "THRILLER"; break;
    }
    return movie.title + " " + str + " (" + std::to_string(movie.duration) + " min)";
}

std::string getTimeSlot(TimeSlot timeslot)
{
    Time k = addMinutes(timeslot.startTime, timeslot.movie.duration);
    
    return (getMovie(timeslot.movie) + " [starts at " + std::to_string(timeslot.startTime.h)
    + ":" + std::to_string(timeslot.startTime.m) + ", ends by " 
    + std::to_string(k.h) + ":" + std::to_string(k.m) + "]");
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    Time k = addMinutes(ts.startTime, ts.movie.duration);
    TimeSlot j;
    j.movie = nextMovie;
    j.startTime = k;

    return j;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    int one = minutesSinceMidnight(ts1.startTime);
    int two = minutesSinceMidnight(ts2.startTime);
    if(one > two)
    {
        Time t = addMinutes(ts2.startTime, ts2.movie.duration);
        if(minutesSinceMidnight(t) > one)
        {
            return true;
        }
    }
    else
    {
        Time t = addMinutes(ts1.startTime, ts1.movie.duration);
        if(minutesSinceMidnight(t) > two)
        {
            return true;
        }
    }
    return false;
}