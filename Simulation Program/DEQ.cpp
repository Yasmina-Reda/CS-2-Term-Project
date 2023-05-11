#include "DEQ.h"

bool DEQ::DEQisEmpty(){
	if (length == 0)
		return true;
	else return false;
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
	//Y! this is going to create an issue because we want to return a pointer to an airplane, but we also want to delete it
	Airplane* temp;
	Airplane* temp1;
	if(DEQisEmpty())
		cout << "No airplanes currently" << endl;
	else if(front->getNext() == NULL) {
		temp = front;
		//Y! after deleting front temp should be pointing at nothing
		delete front;
		front = NULL;
		length--;
		return temp;
	}
	else{
		temp=front;
		temp1 = temp;
		while(temp->getNext() != NULL) {
			temp1=temp;
			temp=temp->getNext();
		}
		//this line will nullify temp
		temp1->setNext(NULL);
		delete temp;
		length--;
		return temp1;
	}

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
