/*  Name:Max Thet Tin */

#ifndef MAX_QUEUE
#define MAX_QUEUE

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

template <typename T> 	//template declaration
class LQueue{ 
    
public:
	// Constructors
    LQueue();
	
	// Destructor
    ~LQueue(); 
	
	void enqueue (const T&);		//adding data to the tail of the Queue 
	T dequeue();					//removing data from the head of the Queue
	T& front();						//getting data from the head of the Queue
	bool isEmpty();					//checking and returning a boolean value whether the Queue is empty or not
	int size();						//returning the size of the Queue
	
private:
    LinkedList<T> data;				//a LinkedList variable declared to be used in the Queue		
	int used;						//a variable used to get the size of the Queue
};

template <typename T>
ostream& operator <<(ostream& out, LQueue<T>& q); 		//overloaded << operator for printing out the Queue

#include "LQueue.hpp"
#endif