#pragma once
#include "movie.h"
#include "time.h"

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};