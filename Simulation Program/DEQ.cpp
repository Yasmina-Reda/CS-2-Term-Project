#include "DEQ.h"

int DEQ::getDEQLength() { return length;}

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
	else if (airplane->getUrgent()==true)
	{
		Airplane* temp=front;
		//temp->getNext() here is null. if the queue is all urgent or there is only 1 airplane
		if (temp->getNext() == NULL)
		{
			if (temp->getUrgent() == true)
			{
				temp->setNext(airplane);
				airplane->setNext(NULL);
				rear = airplane;
			}
			else {
				airplane->setNext(front);
				front = airplane;
				rear = temp;
			}
		}
		else {
			while (temp->getNext()->getUrgent() == true)
			{
				temp = temp->getNext();

			}
			airplane->setNext(temp->getNext());
			if (airplane->getNext() == NULL) rear = airplane;
			temp->setNext(airplane);
		}
	}
	else {
		airplane->setNext(front);
		front=airplane;
	}
	length++;	
}

Airplane DEQ::removeFront(){ //?
	if(DEQisEmpty())
		cout << "No airplanes currently" << endl;
	else if (front->getNext()==NULL)
	{
		Airplane temp = *front;
		delete front;
		front = NULL;
		rear = NULL;
		length--;
		return temp; //return last item 
	}
	else {
		Airplane *second, temp = *front;
		second = front->getNext();
		delete front;
		front = second;
		length--;
		return temp; //return last item 
	}
}

void DEQ::addRear(Airplane* airplane){ 
	if (airplane->getUrgent()==true)
	{
		addFront(airplane);
	}
	else if (DEQisEmpty()){
		front=rear=airplane;
		length++;
	}
	else {
		rear->setNext(airplane);
		rear=airplane;
		length++;
	}
}

Airplane DEQ::removeRear(){ //make a while loop until next is rear
	//Y! this is going to create an issue because we want to return a pointer to an airplane, but we also want to delete it
	Airplane* temp;
	Airplane* temp1;
	Airplane sendback;
	if(DEQisEmpty())
		cout << "No airplanes currently" << endl;
	else if(front->getNext() == NULL) {
		sendback = *front;
		//Y! after deleting front temp should be pointing at nothing
		delete front;
		front = NULL;
		length--;
		return sendback;
	}
	else{
		temp=front;
		temp1 = temp;
		while(temp->getNext() != NULL) {
			temp1=temp;
			temp=temp->getNext();
		}
		sendback = *temp;
		delete temp;
		temp1->setNext(NULL);
		length--;
		return sendback;
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

void DEQ::viewQueue(Airplane* a){
	cout << "\n\nBeginning of Queue" << endl;
	while (a!=NULL){
		a->print();
		a=a->getNext(); 
	}
	cout << "End of Queue\n\n" << endl;
}
