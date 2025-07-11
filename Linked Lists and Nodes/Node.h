/*  Name:Minn Thet Tin */

#ifndef MAX_NODE
#define MAX_NODE

#include <iostream>
#include <cstdlib>
#include "Student.h"

class Node{ 
    
public:
	//type definition of Student class
    typedef Student value_type;    
	
	// Constructors
    Node();                        
    Node(const value_type& i);
	
	// Destructor
    ~Node(); 
	
	// Getters
	Node* getNext(); //get next pointer
    Node* getPrev(); //get previous pointer
    value_type getData(); //get main data
	
	// Setters
	void setNext(Node* n);  //set next pointer 
    void setPrev(Node* p);	//set previous pointer
    void setData(const value_type& i); //set main data
    
    
private:
    Node* next;      //next pointer               
    Node* prev;      //previous pointer               
    value_type data; //main data
};
#endif