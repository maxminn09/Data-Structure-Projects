/*  Name:Max Thet Tin */
    
#include "LQueue.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
LQueue<T>::LQueue()			//Empty Queue
{
	used = 0;
}

template <typename T>
LQueue<T>::~LQueue()		//Implementing the deconstructor of the Queue
{
	used = 0;
}

template <typename T>
void LQueue<T>::enqueue (const T& entry)		//Implementing the function to add data to the tail of the Queue
{
	++used;
	data.addToTail(entry);
}

template <typename T>
T LQueue<T>::dequeue(){							//Implementing the function to remove data from the head of the Queue
	data.start();
	--used;
	return data.removeFromHead();
}

template <typename T>
T& LQueue<T>::front() {							//Implementation of getting data from the head of the Queue
	data.start();
	return data.getFromHead();
}

template <typename T>
bool LQueue<T>::isEmpty()						//Implementation of returning a boolean value to check whether the Queue is empty or not
{
	
	if (used >= 1)
		return false;
	else 
		return true;
}

template <typename T>
int LQueue<T>::size()							//Implementation of getting the size of the Queue
{
	return data.getLength();
}

template <typename T>
ostream& operator <<(ostream& out, LQueue<T>& q)	//Implementation of Overloading the << Operator
{
	for (int i = 0; i < q.size(); i++){
		T data = q.front();
		out << data << " ";
		q.dequeue();
		q.enqueue(data);
	}
	return out;
	
}