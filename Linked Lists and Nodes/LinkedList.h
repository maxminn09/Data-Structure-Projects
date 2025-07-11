/*  Name:Minn Thet Tin */

#ifndef MAX_LINKEDLIST
#define MAX_LINKEDLIST

#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "Student.h"

class LinkedList{ 
    
public:
	
	//type definition of Student class
	typedef Student value_type;
	
	// Constructors
	LinkedList();
	LinkedList(value_type& data);
	
	// Destructor
	~LinkedList();
	
	//Adding data to nodes
	void addToHead(value_type& data); 
	void addToTail(value_type& data); 
	void addToCurrent(value_type& data); 
	
	//Removing data from nodes
	value_type removeFromHead(); 
	value_type removeFromTail(); 
	value_type removeFromCurrent(); 
	void remove(const char* studentName);
	
	//Getting data from nodes
	value_type getFromCurrent();
	value_type getFromHead();
	value_type getFromTail();	
	
	//Calculating the average of nodes and calculating the count of nodes
	int count(const string cName);
	int calcAverage();
	
	//Moving pointer to different nodes
	void start();   //Moving current to the head
	void end();     //Moving current to the tail
	void forward(); //Moving current for one node to the right
	void back();    //Moving current for one node to the left
	
	//Getting the Length of the nodes
	int getLength(); //Calculating the length of the nodes
	
	//Overloading the += operator
	void operator += (LinkedList& l);
	
    
private:
	Node* head;	//Pointer for head node
	Node* tail;	//Pointer for tail node
	Node* current;	//Pointer for current node
	int length;	//Length of the nodes

};
//Overloading the << operator
ostream& operator <<(ostream& out, LinkedList& l);
#endif