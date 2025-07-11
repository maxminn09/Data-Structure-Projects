/*  Name:Minn Thet Tin */

#ifndef MAX_NODE
#define MAX_NODE

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>	 //template declaration
class Node{ 
    
public:

	// Constructors
    Node();                        
    Node(const T i);
	
	// Destructor
    ~Node(); 
	
	// Getters
	Node* getNext(); //get next pointer
    Node* getPrev(); //get previous pointer
    T& getData(); //get main data
	
	// Setters
	void setNext(Node* n);  //set next pointer 
    void setPrev(Node* p);	//set previous pointer
    void setData(const T i); //set main data
    
    
private:
    Node* next;      //next pointer               
    Node* prev;      //previous pointer               
    T data; //main data
};

#include "Node.hpp"
#endif