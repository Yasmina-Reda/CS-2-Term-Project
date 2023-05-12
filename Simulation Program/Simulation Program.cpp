#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Airport.h"
#include "Airport.cpp"
using namespace std;


//global variables
Airport MAIN; string stime; DEQ line;
int simTime, clockTime=0, timeTillService=0, jobCount=0, waitTotal=0, landingTime;


//Prototypes

//returns a random value for arrival time, range varies depending on time of the day
int generateArrivalAverage();

//generates a random double
float generateRandFloat();

//reads a string time in hh:mm and returns minutes 
int readTime(string);

//reads minutes and returns time -> will write later then implement in other functions
string writeTime(int);

//validates that the entered time is correct -> will write later then implement in other functions
void validateTime(string&);

//tests if a plane has arrived and can be entered into the landing
bool Arrived(double);

//test if a plane can be serviced
bool canService();

//returns true if there is a plane to dequeue, sets its wait time and updates waitTotal and jobCount. Returns false if DEQ is empty
void exitLine();




int main()
{

	int arrivalAVG = generateArrivalAverage();
	double probablityArrival = float(1) / arrivalAVG;
	Airplane* temp;
	//please enter simulation time in hh:mm
	cout << "Please Enter Simulation Duration in hh:mm or h:mm format: "; cin >> stime;
	validateTime(stime);

	//convert to minutes
	simTime = readTime(stime);

	//Y! get landing time from Airport but initialize for now
	landingTime = 10; int averageTime;

	for (clockTime; clockTime < simTime;clockTime++)
	{
		if(Arrived(probablityArrival)) 
			canService();
		if (timeTillService > 0) timeTillService--;
	}

	cout << "\nSimulation complete\n";

	for (int i = 0;i < 30;i++) cout << "---";

	if (jobCount != 0)
	{
		averageTime = waitTotal / jobCount;
		cout << "\nAverage wait time is " << writeTime(averageTime);
	}
	else cout << "\nNo jobs have been processed\n";


	return 0;
}

int generateArrivalAverage()
{
	//Y! if prime time increase, else decrease
	//but for now just set it
	srand((unsigned int)time(NULL));
	int T = rand() % 5 + 1;
	return T;
}

float generateRandFloat()
{
	srand((unsigned int)time(NULL));
	float T = rand() / float(32767);
	return T;
}


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
	string time;
	time = "" + to_string(t / 60) + ':';
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


bool Arrived(double probability)
{
	double R = generateRandFloat();

	//if the probability allows for plane arrival
	if (R < probability)
	{
		//generates a new plane if arrived;
		Airplane* plane = MAIN.Randomgenerate();

		//sets arrival time with the current clockTime
		plane->setArrivalTime(writeTime(clockTime));

		//adds plane to deque
		line.addRear(plane);
		return true;
	}
	else return false;	

}




bool canService()
{
	//if the conditions are met for carrying out the service
	if (timeTillService == 0 && !line.DEQisEmpty())
	{
		//Airplane* plane;
		 exitLine();

			//outputs plane info and time
			//Y! problem with print
			//plane->print();
			return true;
	}
	//else returns false
	return false;
}



void exitLine()
{
		Airplane plane;
		plane = line.removeFront();
		plane.setWaitTime(writeTime(clockTime - readTime(plane.getArrivalTime())));
		waitTotal += readTime(plane.getWaitTime());
		jobCount++;
		plane.print();
		cout << "started service at " << writeTime(clockTime) << ". Wait time = " << plane.getWaitTime() << "\n";
		timeTillService = landingTime;
}

//Airplane* exitLine()
//{
//	if (line.DEQisEmpty())
//	{
//		cout << "Report: Line is Empty";
//		return nullptr;
//	}
//	else
//	{
//		Airplane a= line.removeFront();
//		Airplane* plane = &a;
//		plane->setWaitTime(writeTime(clockTime - readTime(plane->getArrivalTime())));
//		waitTotal += readTime(plane->getWaitTime());
//		jobCount++;
//		return plane;
//	}
//}