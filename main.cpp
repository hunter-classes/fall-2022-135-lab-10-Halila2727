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
  std::cout << "\nTask A: Time Since Midnight:\nTime Right Now: 10:30\nMinutes Since Midnight: " << minutesSinceMidnight(time1) << "\n";
  std::cout << "\n------------------\n";

  std::cout << "\nTask A: Minutes Until:\nEarlier Time: 10:30\nLater Time: 13:40\nMinutes between: " << minutesUntil(time1, time2) << "\n";
  std::cout << "\n------------------\n";

  std::cout << "\nTask B: Add Minutes:\nTime: 8:10\nMinutes to add: 75\n";
  printTime(addMinutes(time3, 75));
  std::cout << "\n\n------------------\n";

  return 0;
}