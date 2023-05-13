#include "Airport.h"

// Constructor
Airport::Airport() {
    AirplaneCount = 0;
    //fixed the expression from "DEQ=DEQ()" to "deque=DEQ()"
    deque = DEQ();
    weather = generateWeather();

}

// Destructor
Airport::~Airport() {}






// Inserts an airplane into the deque based on its urgency and arrival time
/*void Airport::insertDEQ(Airplane* a) {
    if (a->getUrgent()) {
        deque.push_front(a);
    }
    else {
        int arrivalTime = stoi(a->getArrivalTime());
        for (int i = 0; i < deque.size(); i++) {
            Airplane* curr = deque[i];
            int currArrivalTime = stoi(curr->getArrivalTime());
            if (arrivalTime < currArrivalTime) {
                deque.insert(i, a);
                return;
            }
        }
        deque.push_back(a);
    }
}*/

// Generates circumstances that affect an airplane's landing time (i.e. weather and passenger count)
//Y! rermoved and moved over to constructor

//Airplane* Airport::Randomgenerate() {
//  
//    int id = (rand () % 100) + 1;
//    int passNum = rand() % 200 + 1;
//    //Y! don't set arrival time here. It's set in simulation
//    //string arrivalTime = "to_string(rand() % 24) : to_string(rand() % 60)";
//    Airplane* a = new Airplane();
//    a->setId(to_string(id));
//    
//    a->setPassNum(passNum);
//    //a->setArrivalTime(arrivalTime);
//    return a;
//}


