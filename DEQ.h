#include <iostream>
using namespace std;

class DEQ{
	private:
		Airplane* front;
		Airplane* rear;
		int length;
	public:
		DEQ(){front=rear=NULL; length=0;} //
		~DEQ();
		int getDEQLength();
		bool DEQisEmpty();//
		bool DEQisFull();//
		void addRear(Airplane* node);//anyone of front/rear
		void addFront(Airplane* node);//
		Airplane* removeFront();//
		Airplane* removeRear();//
		Airplane* viewFront();
		Airplane* viewRear();
		
};
