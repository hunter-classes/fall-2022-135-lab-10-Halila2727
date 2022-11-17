/*
  Author: Halil Akca
  Course: CSCI-135
  Instructor: Mike Zamansky
  Assignment: Lab 10
  This program will call the functions made in other .cpp files
*/

#include <iostream>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"


int main()
{
  Time time1 = {10, 30};
  Time time2 = {13, 40};
  Time time3 = {8,10};
  std::cout << "\nTask A: Time Since Midnight:\nTime Right Now: 10:30\nMinutes Since Midnight: " 
  << minutesSinceMidnight(time1) << "\n";
  std::cout << "\n------------------\n";

  std::cout << "\nTask A: Minutes Until:\nEarlier Time: 10:30\nLater Time: 13:40\nMinutes between: " 
  << minutesUntil(time1, time2) << "\n";
  std::cout << "\n------------------\n";

  std::cout << "\nTask B: Add Minutes:\nTime: 8:10\nMinutes to add: 75\n";
  printTime(addMinutes(time3, 75));
  std::cout << "\n\n------------------\n";

  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie movie3 = {"Whiplash", DRAMA, 106};
  TimeSlot morning = {movie1, {8, 30}};  
  TimeSlot evening = {movie2, {19, 45}};

  std::cout << "\nTask C: Get Timeslot:\nMorning: " << getTimeSlot(morning) << "\nEvening: " 
  << getTimeSlot(evening) << "\n";
  std::cout << "\n------------------\n";

  TimeSlot free = scheduleAfter(morning, movie3);
  std::cout << "\nTask D: Scheduling movie after:\n";
  std::cout << movie3.title << " will showcase after " << morning.movie.title << " at ";
  printTime(free.startTime);
  std::cout << "\n\n------------------\n";

  Movie movie4 = {"Eternal Sunshine of the Spotless Mind", ROMANCE, 108};
  TimeSlot overlap = {movie4, {9, 15}};
  std::cout << "\nTask E: Overlapping Movie Showings:\nDoes " << getTimeSlot(morning) << "\nand\n" 
  << getTimeSlot(evening) << "\noverlap?\n";
  if(timeOverlap(morning, evening)==true)
  {
    std::cout << "Yes!";
  }
  else
  {
    std::cout << "No!";
  }
  std::cout << "\n\nDoes " << getTimeSlot(morning) << "\nand\n" << getTimeSlot(overlap) << "\noverlap?\n";
  if(timeOverlap(morning, overlap)==true)
  {
    std::cout << "Yes!";
  }
  else
  {
    std::cout << "No!";
  }

  std::cout << "\n\n";
  return 0;
}