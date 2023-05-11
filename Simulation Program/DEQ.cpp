#include "DEQ.h"

bool DEQ::DEQisEmpty(){
	if (length == 0)
		return true;
}

void DEQ::addFront(Airplane* airplane){
	if (DEQisEmpty()){
		front=rear=airplane;
		airplane->setNext(NULL);
	}
	else {
		airplane->setNext(front);
		front=airplane;
	}
	length++;	
}

Airplane* DEQ::removeFront(){ //?
	if(DEQisEmpty())
		cout << "No airplanes currently" << endl;
	Airplane* temp=front;
	front = front->getNext();
	delete front;
	length--;
	return temp; //return last item 
}

void DEQ::addRear(Airplane* airplane){
	if (DEQisEmpty()){
		front=rear=airplane;
	}
	else {
		rear->setNext(airplane);
		rear=airplane;
	}
	length++;
}

Airplane* DEQ::removeRear(){ //?
	Airplane* temp;
	Airplane* temp1;
	if(DEQisEmpty())
		cout << "No airplanes currently" << endl;
	else if(front->getNext() == NULL) {
		front=NULL;
		delete front;
		length--;
	}
	else{
		temp=front;
		while(temp->getNext() != NULL) {
			temp1=temp;
			temp=temp->getNext();
		}
		temp1->getNext() == NULL;
		delete temp;
		length--;
	}
	return temp1;
}

Airplane* DEQ::viewFront(){
	if(DEQisEmpty())
		cout << "No airplanes currently" << endl;
	else
		return front; //-> airplane name ? 
}

Airplane* DEQ::viewRear(){
	if(DEQisEmpty())
		cout << "No airplanes currently" << endl;
	else
		return rear; //-> airplane name ? 
}
