#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

Time time1 = {10, 30};
Time time2 = {0, 0};
Time time3 = {8,13};
Time time4 = {0, 7};
Time time5 = {7, 0};

TEST_CASE("Minutes Since Midnight")
{
    CHECK(minutesSinceMidnight(time1) == 630);
    CHECK(minutesSinceMidnight(time2) == 0);
    CHECK(minutesSinceMidnight(time3) == 493);
    CHECK(minutesSinceMidnight(time4) == 7);
    CHECK(minutesSinceMidnight(time5) == 420);
}

TEST_CASE("Minutes Between Two Times")
{
    CHECK(minutesUntil(time1, time2) == -630);
    CHECK(minutesUntil(time4, time1) == 623);
    CHECK(minutesUntil(time4, time5) == 413);
    CHECK(minutesUntil(time3, time1) == 137);
}

TEST_CASE("Add Minutes")
{
    CHECK(addMinutes(time1, 35).h == 11);
    CHECK(addMinutes(time1, 35).m == 5);
    CHECK(addMinutes(time2, 452).h == 7);
    CHECK(addMinutes(time2, 452).m == 32);
    CHECK(addMinutes(time5, 600).h == 17);
    CHECK(addMinutes(time5, 600).m == 0);
}

Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
Movie movie3 = {"Whiplash", DRAMA, 106};
Movie movie4 = {"Eternal Sunshine of the Spotless Mind", ROMANCE, 108};
TimeSlot ts1 = {movie4, {9, 15}};
TimeSlot ts2 = {movie1, {8, 30}};  
TimeSlot ts3 = {movie3, {19, 45}};


TEST_CASE("Get Time Slots")
{
    CHECK(getTimeSlot(ts1) == "Eternal Sunshine of the Spotless Mind ROMANCE (108 min) [starts at 9:15, ends by 11:3]");
    CHECK(getTimeSlot(ts2) == "Back to the Future COMEDY (116 min) [starts at 8:30, ends by 10:26]");
    CHECK(getTimeSlot(ts3) == "Whiplash DRAMA (106 min) [starts at 19:45, ends by 21:31]");
}

TEST_CASE("Next Movie Time Slot")
{
    CHECK(scheduleAfter(ts1, movie2).startTime.h == 11);
    CHECK(scheduleAfter(ts1, movie2).startTime.m == 3);
    CHECK(scheduleAfter(ts2, movie1).startTime.h == 10);
    CHECK(scheduleAfter(ts2, movie1).startTime.m == 26);
    CHECK(scheduleAfter(ts3, movie3).startTime.h == 21);
    CHECK(scheduleAfter(ts3, movie4).startTime.m == 31);
}

TEST_CASE("Overlap Cases")
{
    CHECK(timeOverlap(ts1, ts2) == true);
    CHECK(timeOverlap(ts2, ts3) == false);
}