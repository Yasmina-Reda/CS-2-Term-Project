#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <fstream>
#include <chrono>
#include <thread>
#include "DEQ.h"
#include "DEQ.cpp"
using namespace std;


//global variables
string stime, DayBegin = "6:00"; bool Prime, Low; DEQ line;
int simTime, timeofDay, clockTime = 0, timeTillService = 0, jobCount = 0, jobTotal = 0, waitTotal = 0;
enum Weather { Sunny, Rainy, Windy, Stormy }; Weather currentWeather; int weatherFactor;
ofstream write("Log.txt", ios::app);

//Prototypes

//returns a random value for arrival time, range varies depending on time of the day
int generateArrivalAverage();
//
////generates a random double
float generateRandFloat();

//generates random probability of plane arrival range varies depending on time of the day
//bool generateProbability();

//reads a string time in hh:mm and returns minutes 
int readTime(string);

//reads minutes and returns time -> will write later then implement in other functions
string writeTime(int);

//validates that the entered time is correct -> will write later then implement in other functions
void validateTime(string&);

//tests if a plane has arrived and can be entered into the landing
void Arrived(float);

//test if a plane can be serviced
void canService();

//returns true if there is a plane to dequeue, sets its wait time and updates waitTotal and jobCount. Returns false if DEQ is empty


// Calculates the landing time of an airplane based on weather and number of passengers
int calculateLandingTime(Airplane*);

// Displays the time and weather of the airport
void displayWeather();

// Generates a random weather condition
void generateWeather();

//Prime or Low Time based on current time of day
bool changeTimeStatus();

void writeToLog(Airplane);

int main()
{
	cout << "Welcome to Airport Simulator\n\nDay Begins at " << DayBegin << "\n\nPlease Enter Simulation Duration in hh:mm or h:mm format: ";
	cin >> stime;
	validateTime(stime);

	char real = 'N'; cout << "For Real Time Simulation, Enter the Character 'Y': "; cin >> real;

	ofstream clear("Log.txt");

	cout << "\n\nSimulation Start\n";
	for (int i = 0;i < 30;i++) cout << "---";

	clear << "Simulation Start\n"; clear.close();

	for (int i = 0;i < 30;i++) write << "---";
	write << "\n\n";

	//convert to minutes
	simTime = readTime(stime);

	//Y! get landing time from Airport but initialize for now
	int averageTime;

	float probability = float(1) / generateArrivalAverage();

	timeofDay = readTime(DayBegin);
	generateWeather();
	if (changeTimeStatus()) probability = float(1) / generateArrivalAverage();

	if (real=='Y') {

		for (clockTime; clockTime < simTime;clockTime++)
		{
			timeofDay++;
			//if we reached 24:00
			if (timeofDay == 1440)
			{
				timeofDay = 0;
				simTime -= clockTime;
				clockTime = 0;
			}

			if (changeTimeStatus()) probability = float(1) / generateArrivalAverage();
			if (timeofDay % 360 == 0) generateWeather();

			Arrived(probability);
			canService();
			if (timeTillService > 0) timeTillService--;
			cout << "Current Time: " << writeTime(timeofDay) << "\t Runway Status: ";
			if (timeTillService == 0) cout << "Free"; else cout << "Occupied";
			cout << "\r";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		}
	}

	else {

		for (clockTime; clockTime < simTime;clockTime++)
		{
			timeofDay++;
			//if we reached 24:00
			if (timeofDay == 1440)
			{
				timeofDay = 0;
				simTime -= clockTime;
				clockTime = 0;
			}

			if (changeTimeStatus()) probability = float(1) / generateArrivalAverage();
			if (timeofDay % 360 == 0) generateWeather();

			Arrived(probability);
			canService();
			if (timeTillService > 0) timeTillService--;
		}

	}

	cout << endl;
	for (int i = 0;i < 30;i++) cout << "---";
	cout << "\nSimulation complete\n";

	for (int i = 0;i < 30;i++) write << "---";
	write << "\nsimulation complete\n";

	if (jobCount != 0)
	{
		averageTime = waitTotal / jobCount;
		cout << "\nAverage wait time is " << writeTime(averageTime) << ". Airplanes not processed: " << jobTotal - jobCount << "\n\n";
		write << "\nAverage wait time is " << writeTime(averageTime) << ". Airplanes not processed: " << jobTotal - jobCount << "\n\n";


	}
	else
	{
		cout << "\nNo jobs have been processed\n\n";
		write << "\nNo jobs have been processed\n\n";
	}

	write.close();

	return 0;
}

int generateArrivalAverage()
{
	//Y! if prime time increase, else decrease
	//but for now just set it
	int T;
	//only works properly if we call srand in the function itself
	if (Prime) T = 5;

	else if (Low) T = 20;

	else T = 10;

	return T;
}


//Y! fix this, or not
float generateRandFloat()
{
	//only works properly if we call srand in the function itself
	srand(time(NULL) + timeofDay);

	//Y! fix probability based on simTime
	float T = rand() / float(rand()%32767);
	/*(rand() % 40000 + 10000)*/
	//int T = rand() % 5 + 1;

	return T;
}

//bool generateProbability()
//{
//	//vary based on time of day
//	srand(clockTime);
//	if (rand() % 100 < 10) return true;
//	else return false;
//}

int readTime(string time)

{
	int t;
	string shr = "", smin = "";
	bool colon = false;
	for (int i = 0;i < time.length();i++) {
		if (time.at(i) != ':' && colon == false) shr += time.at(i);
		else if (time.at(i) == ':') colon = true;
		else smin += time.at(i);
	}
	t = stoi(shr) * 60 + stoi(smin);
	return t;
}

string writeTime(int t)
{
	string time = "";
	if (t / 60 < 10) time = time + '0';
	time += to_string(t / 60) + ':';
	if (t % 60 < 10) time = time + '0';
	time += to_string(t % 60);
	return time;
}

void validateTime(string& time)
{
	//to make sure string entered is in h:mm or hh:mm format 
	while (!(time.length() == 4 && time.at(1) == ':') && time.length() != 5)
	{
		cout << "\nInvalid time format. Please re-enter: "; cin >> time;
	}
}

void Arrived(float probability)
{

	//if the probability allows for plane arrival
	/* if (generateProbability())*/
	//srand(clockTime);

	float R = generateRandFloat();

	if ((R < probability))
	{
		//generates a new plane if arrived;
		Airplane* plane = new Airplane(timeofDay);

		//sets arrival time with the current time: DayBegin+ClockTime
		plane->setArrivalTime(writeTime(timeofDay));

		plane->setServiceTime(calculateLandingTime(plane));
		//adds plane to deque
		line.addRear(plane);
		jobTotal++;
		//cout << "\nyes at " << writeTime(clockTime);
		cout << "\n-->Airplane " << plane->getId() << " arrived\n";
		if (plane->getUrgent()) cout << "Urgent Airplane->Moved to priority queue\n";

	}
	return;
}

void canService()
{
	//if the conditions are met for carrying out the service
	if (timeTillService == 0 && !line.DEQisEmpty())
	{
		Airplane plane;
		plane = line.removeFront();
		int wt;
		if (timeofDay < readTime(plane.getArrivalTime())) wt = 1440 + timeofDay - readTime(plane.getArrivalTime());
		else wt = timeofDay - readTime(plane.getArrivalTime());

		plane.setWaitTime(writeTime(wt));
		waitTotal += wt;
		jobCount++;
		plane.print();
		cout << "Started Service at " << writeTime(timeofDay) << "\nWait Time Before Landing: " << plane.getWaitTime() << "\nEstimated Service Duration: " << writeTime(plane.getServiceTime()) << "\n\n";
		writeToLog(plane);
		timeTillService = plane.getServiceTime();

	}
	return;
}

int calculateLandingTime(Airplane* plane) {
	int passNum = plane->getPassNum();
	return 10 * (passNum / float(100)) * weatherFactor;
}

void generateWeather() {

	srand(time(NULL) + timeofDay);
	int r = rand() % 6;
	switch (r) {
	case 0:
	case 1:
	case 2: currentWeather = Sunny; weatherFactor = 1; break;
	case 3: currentWeather = Rainy; weatherFactor = 1.25; break;
	case 4: currentWeather = Windy; weatherFactor = 1.75; break;
	case 5: currentWeather = Stormy; weatherFactor = 2;
	}
	displayWeather();
	return;
}

void displayWeather() {

	//Y! add comment about weather condition and how each of them will affect landing time
	switch (currentWeather) {
	case 0: cout << "\n\n[Weather Forecast Update] Sunny Conditions.\nEstimated Service Time is Normal\n\n"; return;
	case 1: cout << "\n\n[Weather Forecast Update] Rainy Conditions.\n*Warning: Estimated Service Time is Above Normal*\n\n"; return;
	case 2: cout << "\n\n[Weather Forecast Update] Windy Conditions.\n*Warning: Estimated Service Time is Above Normal*\n\n"; return;
	case 3: cout << "\n\n[Weather Forecast Update] Stormy Conditions.\n*Warning: Estimated Service Time is Above Normal*\n\n"; return;
	}

}

bool changeTimeStatus() {

	//at 12 pm
	if (timeofDay == 720)
	{
		Prime = true;
		cout << "\n\n*Warning: Entering Prime Time.*\nFrequency of Airplane Arrival is Expected to Increase\n\n";
		return true;
	}

	//at 4 pm
	else if (timeofDay == 960)
	{
		Prime = false;
		cout << "\n\n*Warning: Prime Time is Over.*\nFrequency of Airplane Arrival is Expected to Go Back to Normal\n\n";
		return true;
	}

	//at 2 am
	else if (timeofDay == 120)
	{
		Low = true;
		cout << "\n\n*Warning: Entering Low Time.*\nFrequency of Airplane Arrival is Expected to Decrease\n\n";
		return true;
	}

	//at 6 am
	else if (timeofDay == 360)
	{
		Low = false;
		cout << "\n*Warning: Low Time is Over. Frequency of Airplane Arrival is Expected to Go Back to Normal\n";
		return true;
	}

	return false;
}

void writeToLog(Airplane plane)
{
	if (!write.fail()) {

		write << "\nAirplane ID: " << plane.getId() << "\nDeparture: " << plane.getDeparture() << "\nNumber of Passengers: " << plane.getPassNum() << "\nArrival Time; " << plane.getArrivalTime();
		write << "\nStatus: ";
		if (plane.getUrgent()) write << "Urgent\n"; else write << "Not Urgent\n";

		write << "Started Service at " << writeTime(timeofDay) << "\nWait Time Before Landing: " << plane.getWaitTime() << "\nEstimated Service Duration: " << writeTime(plane.getServiceTime());
		write << "\n\n\n";

	}
	else cout << "Failed to Open Log File to Write";
}

