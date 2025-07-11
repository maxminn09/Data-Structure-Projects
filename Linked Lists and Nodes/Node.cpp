/*  Name:Minn Thet Tin */

#include "Node.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Node::Node() {
   
}

Node::Node(const value_type& i){  //Implementation of Node constructor
    data = i;
	next = NULL;
    prev = NULL;
}

Node::~Node(){	//Implementation of Node deconstructor
    
}
void Node::setNext(Node* n){  //Implementation of setting the next pointer
    next = n;
}

Node* Node::getNext(){	//Implementation of getting the next pointer
    return next;
}

void Node::setPrev(Node* p){	//Implementation of setting the previous pointer
    
    prev = p;
}

Node* Node::getPrev(){	//Implementation of getting the previous pointer
    return prev;
}

void Node::setData(const value_type& i){	//Implementation of setting the main data
    data = i;
}

Node::value_type Node::getData(){	//Implementation of getting the main data	
    return data;
} 
    
    
    
    