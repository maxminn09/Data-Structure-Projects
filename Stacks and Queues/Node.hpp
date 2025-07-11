/*  Name:Max Thet Tin */

#include "Node.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
Node<T>::Node() {		   //Empty Node
	next = NULL;
    prev = NULL;
}

template <typename T>
Node<T>::Node(const T i){  //Implementation of Node constructor
    data = i;
}

template <typename T>
Node<T>::~Node(){	//Implementation of Node deconstructor
    
}

template <typename T>
void Node<T>::setNext(Node<T>* n){  //Implementation of setting the next pointer
    next = n;
}

template <typename T>
Node<T>* Node<T>::getNext(){	//Implementation of getting the next pointer
    return next;
}

template <typename T>
void Node<T>::setPrev(Node<T>* p){	//Implementation of setting the previous pointer
    
    prev = p;
}

template <typename T>
Node<T>* Node<T>::getPrev(){	//Implementation of getting the previous pointer
    return prev;
}

template <typename T>
void Node<T>::setData(const T i){	//Implementation of setting the main data
    data = i;
}

template <typename T>
T& Node<T>::getData(){	//Implementation of getting the main data	
    return data;
} 
    
    
    
    