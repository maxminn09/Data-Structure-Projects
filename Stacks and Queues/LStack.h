/*  Name:Max Thet Tin */
    
#ifndef MAX_STACK
#define MAX_STACK

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

template <typename T>
class LStack{ 
    
public:
	// Constructors
    LStack();
	
	// Destructor
    ~LStack(); 
	
	void push(const T&);			//adding data to the head of the Stack 
	T pop();						//removing data from the head of the Stack
	T& peek();						//getting data from the head of the Stack
	bool isEmpty();					//checking and returning a boolean value whether the Stack is empty or not

	
private:
    LinkedList<T> data;				//a LinkedList variable declared to be used in the Stack	
	int used;						//a variable used to get the size of the Stack
};

template <typename T>
ostream& operator <<(ostream& out, LStack<T>& s);				//overloaded << operator for printing out the Stack
#include "LStack.hpp"
#endif