/*  Name:Max Thet Tin */

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() {	//Empty linked list
	head = NULL;
	tail = NULL;
	current = NULL;
	length = 0;
}

template <typename T>
LinkedList<T>::LinkedList(T data) {	//Implementing the constructor of the LinkedList
	head = new Node<T>(data);
	tail = head;
	current = tail;
	length = 1;
}

template <typename T>
LinkedList<T>::~LinkedList() {	//Implementing the deconstructor of the LinkedList
	while (head != NULL) {
		removeFromHead();
	}
	tail = NULL;
	current = NULL;
}

template <typename T>
void LinkedList<T>::addToHead(T data) {	//Implementing the function to add data to the head of the LinkedList
	if (length == 0) {
		head = new Node<T>(data);
		tail = head;
		current = head;
		length = 1;
	}
	else {
		Node<T>* head_insert = new Node<T>(data);
		head->setPrev(head_insert);
		head_insert->setNext(head);
		head = head_insert;
		length++;
		head_insert = NULL;
	}
	
}

template <typename T>
void LinkedList<T>::addToTail(T data) {	//Implementing the function to add data to the tail of the LinkedList
	if (length == 0) {
		head = new Node<T>(data);
		tail = head;
		current = tail;
		length = 1;
	}
	else {
		Node<T>* tail_insert = new Node<T>(data);
		tail->setNext(tail_insert);
		tail_insert->setPrev(tail);
		tail = tail_insert;
		length++;
		tail_insert = NULL;
	}
	
}

template <typename T>
void LinkedList<T>::addToCurrent(T data) {	//Implementing the function to add data to the current node of the LinkedList
	if (length == 0) {
		addToHead(data);
	}
	else if (current == tail) {
		addToTail(data);
	}
	else {
		Node<T>* current_insert = new Node<T>(data);
		current_insert->setNext(current->getNext());
		current_insert->setPrev(current);
		current->setNext(current_insert);
		current->getNext()->setPrev(current_insert);
		current = current_insert;
		current_insert = NULL;
	}
	length++;
}

template <typename T>
T LinkedList<T>::removeFromHead() {	//Implementing the function to remove data from the head of the LinkedList
	T data;
	if (head == NULL)
		return data;

	else if (length == 1) {
		data = head->getData();
		delete head;
		head = NULL;
		tail = NULL;
		current = NULL;
		length--;
		return data;
	}

	else {
		data = head->getData();
		Node<T>* temp_head = head;
		head = head->getNext();
		delete temp_head;
		current = head;
		length--;
		return data;
	}
}

template <typename T>
T LinkedList<T>::removeFromTail() {	//Implementing the function to remove data from the tail of the LinkedList
	T data;
	if (head == NULL)
		return data;

	else if (length == 1) {
		data = head->getData();
		delete head;
		head = NULL;
		tail = NULL;
		current = NULL;
		length--;
		return data;
	}

	else {
		data = tail->getData();
		Node<T>* temp_tail = tail;
		tail = tail->getPrev();
		tail->setNext(NULL);
		delete temp_tail;
		current = head;
		length--;
		return data;
	}
}

template <typename T>
T LinkedList<T>::removeFromCurrent() {	//Implementing the function to remove data from the current node of the LinkedList
	T data;
	if (head == NULL) {
		return data;
	}
	else if (length == 1) 
	{ 
		return removeFromHead();
	}
	else if (current == head) //if head
	{
		return removeFromHead();
	}
	else if (current == tail ) //if tail
	{
		return removeFromTail();
	}
	else 
	{
		Node<T>* temp_current = current;
		current->getPrev()->setNext(current->getNext());
		current->getNext()->setPrev(current->getPrev());
		data = current->getData();
		delete temp_current;
		current = head;
		length--;
		return data;
	}
}

//Commenting out the functions that are not required from previos assignment
/*
void LinkedList::remove(const char* studentName)	//Implementing the function to remove data using the Student's Name
{
	start(); 
	for (int i = 0; i < 15; i++) //The reason for setting the length 15 is because I could not figure out how to update my length after Concatenating
	{
		if (current->getData().get_name() == studentName)
		{
			removeFromCurrent();
			forward();
			
		}
		else
		{	forward();
		}
	}
}
*/

template <typename T>
T& LinkedList<T>::getFromCurrent() { //Implementation of getting data from the current node 
	return current->getData();
}

template <typename T>
T& LinkedList<T>::getFromHead() {	//Implementation of getting data from the head node 
	return head->getData();
}

template <typename T>
T& LinkedList<T>::getFromTail() {	//Implementation of getting data from the tail node 
	return tail->getData();
}


//Commenting out the functions that are not required from previos assignment
/*
int LinkedList::count(string cName)		//Implementing the function to calculate the count of the node
{
	start();
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (current->getData().get_name() == cName)
		{
			count++;
		}
	}
	return count;
}


//Commenting out the functions that are not required from previos assignment
double LinkedList::calcAverage() {		//Implementing the function to calculate the average of nodes
	double count = 0.0;
	double sum = 0.0;
	double average;
	start();

	for (int i = 0; i < length; i++)
	{	
		count++;
		sum += current->getData().get_score();
		forward();
	}
	average = sum / count;
	cout << average << endl; //I had to output the right answer with cout because my overloaded operator keeps returning the address of average
	return average;
}

*/

template <typename T>
void LinkedList<T>::start() {	//Implementation of moving the current node to the head
	current = head;
}

template <typename T>
void LinkedList<T>::end() {	//Implementation of moving the current node to the tail
	current = tail;
}

template <typename T>
void LinkedList<T>::forward() {	//Implementation of moving the current node to the right
	if (current != tail){
	current = current->getNext();
}
}

template <typename T>
void LinkedList<T>::back() {	//Implementation of moving the current node to the left
	if (current != head){
	current = current->getPrev();
}
}

template <typename T>
int LinkedList<T>::getLength() {	//Implementation of returning the length of the LinkedList
	return length;
}


//Commenting out the functions that are not required from previos assignment
/*void LinkedList::operator += (LinkedList& l)	//Implementation of overloading the += operator
{	start();
	l.start();
	int length = l.getLength();	
	for (int i = 0; i < length; i++)
	{
		value_type data = l.current->getData();
		addToTail(data);
		l.forward();
	}
}


//Commenting out the functions that are not required from previos assignment
ostream& operator <<(ostream& out, LinkedList& l)	//Implementation of overloading the << operator
{	

	l.start();
	int length = l.getLength();
	for (int i = 0; i < length; i++)
	{
		out << l.getFromCurrent() << " ";
		l.forward();
	}
	
	return out;
}
*/