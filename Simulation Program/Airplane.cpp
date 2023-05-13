#include "Airplane.h"

int Airplane::totalcount = 0;

Airplane::Airplane(int t=0) {
    // Default constructor
    //generate and set id here with ASCII
    //generate and set departure;
    /*
    string departure;   
    int passengerNum;   
    string id;
    */
    //play with ascii
    srand(time(0)+t);
    //id+= "B" + char(rand() % 25 + 65) + to_string(rand() % 899 + 100);
    id += "B";
    id += char(rand() % 25 + 65);
    id += to_string(rand() % 899 + 100);
    this->t = t;
    passengerNum = rand() % 200 + 1;
    int urg = rand() % 10; if (urg == 1) urgent = true;
    totalcount++; 
    int r = rand() % 4;
    switch (r)
    {
    case 0: departure = Egypt; break;
    case 1: departure = Kuwait; break;
    case 2: departure = Saudia_Arabia; break;
    case 3: departure = UAE ; break;
        
    }

}

Airplane::~Airplane() {
    // Destructor
}

//void Airplane::setId(std::string id) {
//    this->id = id;
//}

std::string Airplane::getId() {
    return this->id;
}

//void Airplane::setDeparture(std::string country) {
//    this->departure = country;
//}

std::string Airplane::getDeparture() {

    switch (departure)
    {
    case 0: return "Egypt"; 
    case 1: return "Kuwait"; 
    case 2: return "Saudia_Arabia"; break;
    case 3: return "UAE";
    }

}

//void Airplane::setPassNum(int w) {
//    this->passengerNum = w;
//}

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
	srand(time(NULL)+t);

    //Y! what do you wanna do here?
    //it's gonna be an equal probability of urgent or non-urgent
    //urgent shouldn't be that many
    //so maybe one in every ten

    return /*this->*/ urgent;
}

void Airplane::setServiceTime(int t)
{
    serviceTime = t;
}

int Airplane::getServiceTime()
{
    return serviceTime;
}

int Airplane::getTotalAirplanes() {
    return totalcount;
}
void Airplane::print() {
  //  cout << "\nAirplane ID: " << getId() << endl;
  //  //Y! commented for now
  //  cout << "Departure: " << getDeparture() << endl;
  //  cout << "Number of Passengers: " << getPassNum() << endl;
  //  //cout << "Wait time before landing: " << getWaitTime() << endl;
  //cout << "Arrival time: " << getArrivalTime() << endl;

  cout << "\nAirplane ID: " << getId() << "\nDeparture: " << getDeparture() << "\nNumber of Passengers: " << getPassNum() << "\nArrival Time: " << getArrivalTime();
  cout << "\nStatus: "; 
  if (urgent) cout << "Urgent\n"; else cout << "Not Urgent\n";
}

