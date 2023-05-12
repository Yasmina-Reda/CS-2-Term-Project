#include "Airplane.h"

int Airplane::totalcount = 0;

Airplane::Airplane() {
    // Default constructor
    //generate and set id here with ASCII
    //generate and set departure;
    /*
    string departure;   
    int passengerNum;   
    string id;
    */
    totalcount++;
}

Airplane::~Airplane() {
    // Destructor
}

void Airplane::setId(std::string id) {
    this->id = id;
}

std::string Airplane::getId() {
    return this->id;
}

void Airplane::setDeparture(std::string country) {
    this->departure = country;
}

std::string Airplane::getDeparture() {
    //Y! do the same as for weather
    /* switch (weatherNum) {
    case 0:
        weather = "Sunny";
        break;
    case 1:
        weather = "Rainy";
        break;
    case 2:
        weather = "Foggy";
        break;
    }
    return weather;*/
    return this->departure;
}

void Airplane::setPassNum(int w) {
    this->passengerNum = w;
}

int Airplane::getPassNum() {
    return this->passengerNum;
}

void Airplane::setNext(Airplane* n) {
    this->next = n;
}

Airplane* Airplane::getNext() {
    return this->next;
}
    void Airplane::setWaitTime(string waittime)
    {
    this->waittime = waittime;
}

string Airplane::getWaitTime() {
    return waittime;
}

void Airplane::setArrivalTime(string arrivaltime) {
    this->arrivaltime = arrivaltime;
}

string Airplane::getArrivalTime() {
    return arrivaltime;
}



bool Airplane::getUrgent() {
    //added unsigned int
	srand((unsigned int)time(NULL));

    //Y! what do you wanna do here?
    //it's gonna be an equal probability of urgent or non-urgent
    //urgent shouldn't be that many
    //so maybe one in every ten

	int u=rand()%10;
    if (u == 1) urgent = true; 
    return this->urgent;
}
int Airplane::getTotalAirplanes() {
    return totalcount;
}
void Airplane::print() {
    cout << "\nAirplane ID: " << getId() << endl;
    //Y! commented for now
    //cout << "Departure: " << getDeparture() << endl;
    cout << "Number of Passengers: " << getPassNum() << endl;
    //cout << "Wait time before landing: " << getWaitTime() << endl;
  cout << "Arrival time: " << getArrivalTime() << endl;
}

