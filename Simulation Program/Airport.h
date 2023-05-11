//Y: Added #pragma once to avoid class redefinition
#pragma once
#include <iostream>
#include <cstring>
#include "DEQ.h"
#include <ctime>
#include <cstdlib>
using namespace std;

// Enumeration to represent the possible weather conditions
enum class Weather {
    Sunny,
    Rainy,
    Windy,
    Stormy
};

// Class to represent an airport
class Airport {
public:
    Airport();
    ~Airport();

    // Calculates the landing time for a given airplane based on the weather and number of passengers
    int calculateLandingTime(Airplane* airplane, string weather);

    // Displays the current time at the airport
    void displayTime();

    // Inserts an airplane into the airport's deque
    void insertDEQ(Airplane* airplane);

    // Generates airplane with random characteristics and returns a pointer to it
    Airplane* Randomgenerate();
    
    // Generates random sweather that affect the landing time of an airplane
   string generateWeather();

private:
    int AirplaneCount;
    DEQ  deque;
    string weather;
    
};
