#include "DEQ.h"

DEQ::DEQisEmpty(){
	if (length==0)
		return true;
}

void DEQ::addFront(Airplane* airplane){
	if (DEQisEmpty()){
		front=rear=airplane;
		airplane->next=NULL;
	}
	else {
		airplane->next=front;
		front=airplane;
	}
	length++;	
}

Airplane DEQ::removeFront(){
	if(DEQisEmpty())
		cout << "No airplanes currently" << endl;
	int temp=front;
	front=front->next;
	delete front;
	length--;
	return temp; //return last item 
}

void DEQ::addRear(Airplane* airplane){
	if (DEQisEmpty()){
		front=rear=airplane;
	}
	else {
		rear->next=airplane;
		rear=airplane;
	}
	length++;
}

Airplane DEQ::removeRear(){
	Airplane* temp;
	Airplane* temp1;
	if(DEQisEmpty())
		cout << "No airplanes currently" << endl;
	else if(head->next==NULL){
		head=NULL;
		delete head;
		length--;
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp1=temp;
			temp=temp->next;
		}
		temp1->next==NULL;
		delete temp;
		length--;
	}
	return temp1;
}
