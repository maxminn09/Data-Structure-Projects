/*  Name:Max Thet Tin */

#include "LStack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
LStack<T>::LStack()					//Empty Stack
{
	used = 0;
}

template <typename T>				//Implementing the deconstructor of the Stack
LStack<T>::~LStack()
{
	used = 0;
}

template <typename T>
void LStack<T>::push (const T& entry)		//Implementing the function to add data to the head of the Stack
{	
	data.start();
	++used;
	data.addToHead(entry);
}

template <typename T>						//Implementing the function to remove data from the head of the Stack
T LStack<T>::pop(){
	data.start();
	--used;
	return data.removeFromHead();
}

template <typename T>
T& LStack<T>::peek() {						//Implementation of getting data from the head of the Stack
	data.start();
	return data.getFromHead();
}

template <typename T>
bool LStack<T>::isEmpty()					//Implementation of returning a boolean value to check whether the Stack is empty or not
{
	if (used >= 1)
		return false;
	else 
		return true;
}


template <typename T>
ostream& operator <<(ostream& out, LStack<T>& s)			//Implementation of Overloading the << Operator
{
	for (int i = 0; i < 2; i++){			//could not figure out how to properly print the Stack
		T data = s.peek();
		out << data << " ";
		s.pop();
		s.push(data);
	}
	
	
	/*while (!s.isEmpty()) {								//my attempt to print out the Stack but I get a Seg Fault
		T data = s.peek();
		out << data << " ";
		s.pop();
	}
	*/
	return out;
}