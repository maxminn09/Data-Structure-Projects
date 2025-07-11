/*  Name:Max Thet Tin */

#ifndef MAX_LINKEDLIST
#define MAX_LINKEDLIST

#include <iostream>
#include <cstdlib>
#include "Node.h"

using namespace std;

template <typename T>			//template declaration
class LinkedList{ 
    
public:
	
	// Constructors
	LinkedList();
	LinkedList(T data);
	
	// Destructor
	~LinkedList();
	
	//Adding data to nodes
	void addToHead(T data); 			//adding data to the head of the LinkedList
	void addToTail(T data); 			//adding data to the tail of the LinkedList
	void addToCurrent(T data); 			//adding data to the current node of the LinkedList
	
	//Removing data from nodes
	T removeFromHead(); 				//removing data from the head of the LinkedList
	T removeFromTail(); 				//removing data from the tail of the LinkedList
	T removeFromCurrent(); 				//removing data from the current node of the LinkedList
	//void remove(const char* studentName);											//Commenting out the functions that are not required from previos assignment
	
	//Getting data from nodes
	T& getFromCurrent();				//getting data from the current node of the LinkedList
	T& getFromHead();					//getting data from the head of the LinkedList
	T& getFromTail();					//getting data from the tail of the LinkedList
	
	//Calculating the average of nodes and calculating the count of nodes			
	//int count(const string cName);												//Commenting out the functions that are not required from previos assignment
	//double calcAverage();															//Commenting out the functions that are not required from previos assignment				
	
	//Moving pointer to different nodes
	void start();   //Moving current to the head
	void end();     //Moving current to the tail
	void forward(); //Moving current for one node to the right
	void back();    //Moving current for one node to the left
	
	//Getting the Length of the nodes
	int getLength(); //Calculating the length of the nodes
	
	//Overloading the += operator													//Commenting out the functions that are not required from previos assignment
	//void operator += (LinkedList& l);												//Commenting out the functions that are not required from previos assignment			
	
    
private:
	Node<T>* head;	//Pointer for head node
	Node<T>* tail;	//Pointer for tail node
	Node<T>* current;	//Pointer for current node
	int length;	//Length of the nodes

};

//Commenting out the functions that are not required from previos assignment	
//Overloading the << operator
//ostream& operator <<(ostream& out, LinkedList& l);	//overloaded << operator for printing out the LinkedList							
#include "LinkedList.hpp"
#endif