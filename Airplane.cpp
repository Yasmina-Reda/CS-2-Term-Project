#include "Airplane.h"

Airplane::Airplane() {
    // Default constructor
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

bool Airplane::getUrgent() {
	srand(time(NULL));

	urgent=rand()%1;
    return this->urgent;
}
