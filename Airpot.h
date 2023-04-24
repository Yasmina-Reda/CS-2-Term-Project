

#include <iostream>
#include <string>
#include <DEQ>
#include <random>
#include "Airplane.h"
using namespace std;

// Enumeration to represent the possible weather conditions
enum class Weather {
    Sunny,
    Rainy,
    Windy,
    Stormy
};

// Enumeration to represent the possible destinations
enum class Country {Egypt,Kuwait,Saudia_Arabia,UAE};

// Class to represent an airport
class Airport {
public:
    Airport();
    ~Airport();

    // Calculates the landing time for a given airplane based on the weather and number of passengers
    int calculateLandingTime(const Airplane* airplane, Weather weather) const;

    // Displays the current time at the airport
    void displayTime() const;

    // Inserts an airplane into the airport's deque
    void insertDEQ(Airplane* airplane);

    // Generates random circumstances that affect the landing time of an airplane
    void generateCircumstances(Airplane* airplane);

private:
    int airplaneCount;
    DEQ  deque;
    
};
