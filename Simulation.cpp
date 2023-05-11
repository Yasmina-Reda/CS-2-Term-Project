
#include <iostream>
#include <cstdlib>
#include<ctime>
#include "Airport.h"
using namespace std;

//returns a random value for arrival time, range varies depending on time of the day
int generateArrivalAverage();

//generates a random double
float generateRandFloat();

//reads a string time in hh:mm and returns minutes -> will write later then implement in other functions
int readTime(string);

//reads minutes and returns time -> will write later then implement in other functions
string writeTime(int);

//validates that the entered time is correct -> will write later then implement in other functions
void validateTime(string&);

//tests if a plane has arrived and can be entered into the landing
bool arrived(DEQ, int);

//test if a plane can be serviced
bool canService(DEQ,int,int&, int,int&,int&);

//returns true if there is a plane to dequeue, sets its wait time and updates waitTotal and jobCount. Returns false if DEQ is empty
bool exitLine(DEQ, int, int&, int&, Airplane&);

int main()
{
	//please enter simulation time in hh:mm
	string time;
	cout << "Please Enter Simulation Duration in hh:mm format"; cin >> time;


	//convert to minutes
	//but for now let's set it here
	int simTime = 60, clockTime = 0, timeTillService = 0, jobCount = 0, waitTotal = 0;

	//get landing time from Airport but initialize for now
	int landingTime = 10;

	int arrivalTime;

	int arrivalAVG = generateArrivalAverage();
	double probablityArrival = 1 / arrivalAVG;
	DEQ waitingline;

	for (clockTime; clockTime < simTime;clockTime++)
	{
		
		//write main function later


	}

	//compute average


	return 0;
}

int generateArrivalAverage()
{
	//if prime time increase, else decrease
	//but for now just set it
	srand((unsigned int)time(NULL));
	int T = rand() % 5 + 1;
	return T;
}

float generateRandFloat()
{
	srand((unsigned int)time(NULL));
	float T = rand()/float(32767);
	return T;
}


bool Arrived(DEQ line, int time, Airplane& plane, int probability)
{
	double R = generateRandFloat();
	if (R < probability)
	{
		if (line.DEQisFull())
		{
			cout << "Error: Line is Full";
		}

		else {
			plane.setarrivaltime(time);
			line.addRear(plane);
			return true;
		}

		return false;

	}
}




bool canService(DEQ line,int time,int& timeTillService, int landingTime,int& waitTotal,int& jobCount)
{

	if(timeTillService==0 && !line.DEQisEmpty())
	{
		Airplane plane;
		bool exited=exitLine(line,time,plane, waitTotal,jobTotal, plane);

		if (exited)
		{
			cout << "Airplane " << plane.id << " started service at " << time << ". Wait time = " << plane.waitTime;
			timeTillService = landingTime;
		}
	}
		

}



bool exitLine(DEQ line, int time, int& waitTotal, int& jobCount, Airplane& plane)
{
	if(line.DEQisEmpty()) 
	{
		cout<< "Report: Line is Empty";
		return false
	}
	else
	{
	plane=line.removeFront();
	plane.waittime=time-plane.arrivaltime;
	waitTotal+=plane.waittime;
	jobCount++;
	return true;
	}

}
