/*  Name:Minn Thet Tin*/

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {	//Empty linked list
	head = NULL;
	tail = NULL;
	current = NULL;
	length = 0;
}

LinkedList::LinkedList(value_type& data) {	//Implementing the constructor of the LinkedList
	head = new Node(data);
	tail = head;
	current = tail;
	length = 1;
}

LinkedList::~LinkedList() {	//Implementing the deconstructor of the LinkedList
	while (head != NULL) {
		removeFromHead();
	}
	head = NULL;
	tail = NULL;
	current = NULL;
}

void LinkedList::addToHead(value_type& data) {	//Implementing the function to add data to the head of the LinkedList
	if (length == 0) {
		head = new Node(data);
		tail = head;
		current = head;
	}
	else {
		Node* head_insert = new Node(data);
		head->setPrev(head_insert);
		head_insert->setNext(head);
		head = head_insert;
		head_insert = NULL;
	}
	length++;
}

void LinkedList::addToTail(value_type& data) {	//Implementing the function to add data to the tail of the LinkedList
	if (length == 0) {
		head = new Node(data);
		tail = head;
		current = tail;
	}
	else {
		Node* tail_insert = new Node(data);
		tail->setPrev(tail_insert);
		tail_insert->setPrev(tail);
		tail = tail_insert;
		tail_insert = NULL;
	}
	length++;
}

void LinkedList::addToCurrent(value_type& data) {	//Implementing the function to add data to the current node of the LinkedList
	if (length == 0) {
		addToHead(data);
	}
	else if (current == tail) {
		addToTail(data);
	}
	else {
		Node* current_insert = new Node(data);
		current_insert->setNext(current->getNext());
		current_insert->setPrev(current);
		current->setNext(current_insert);
		current->getNext()->setPrev(current_insert);
		current = current_insert;
		current_insert = NULL;
	}
	length++;
}

LinkedList::value_type LinkedList::removeFromHead() {	//Implementing the function to remove data from the head of the LinkedList
	value_type data;
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
		Node* temp_head = head;
		head = head->getNext();
		delete temp_head;
		current = head;
		length--;
		return data;
	}
}

LinkedList::value_type LinkedList::removeFromTail() {	//Implementing the function to remove data from the tail of the LinkedList
	value_type data;
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
		Node* temp_tail = tail;
		tail = tail->getPrev();
		tail->setNext(NULL);
		delete temp_tail;
		current = head;
		length--;
		return data;
	}
}

LinkedList::value_type LinkedList::removeFromCurrent() {	//Implementing the function to remove data from the current node of the LinkedList
	value_type data;
	if (head == NULL) {
		return data;
	}
	else 
	{
		Node* temp_current = current;
		current->getPrev()->setNext(current->getNext());
		current->getNext()->setPrev(current->getPrev());
		data = current->getData();
		delete temp_current;
		current = head;
		length--;
		return data;
	}
}

void LinkedList::remove(const char* studentName)	//Implementing the function to remove data using the Student's Name
{
	start(); 
	for (int i = 0; i < length; i++)
	{
		if (current->getData().get_name() == studentName)
		{
			getFromCurrent();
		}
		else
		{
			return;
		}
	}
}

LinkedList::value_type LinkedList::getFromCurrent() { //Implementation of getting data from the current node 
	return current->getData();
}

LinkedList::value_type LinkedList::getFromHead() {	//Implementation of getting data from the head node 
	return head->getData();
}

LinkedList::value_type LinkedList::getFromTail() {	//Implementation of getting data from the tail node 
	return tail->getData();
}


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

int LinkedList::calcAverage() {		//Implementing the function to calculate the average of nodes
	int count = 0;
	int sum = 0;
	int average = 0;
	start();

	for (int i = 0; i < length; i++)
	{
		count++;
		sum += current->getData().get_score();

	}
	average = sum / count;
	return average;
}


void LinkedList::start() {	//Implementation of moving the current node to the head
	current = head;
}

void LinkedList::end() {	//Implementation of moving the current node to the tail
	current = tail;
}

void LinkedList::forward() {	//Implementation of moving the current node to the right
	current = current->getNext();
}


void LinkedList::back() {	//Implementation of moving the current node to the left
	current = current->getPrev();
}


int LinkedList::getLength() {	//Implementation of returning the length of the LinkedList
	return length;
}

void LinkedList::operator += (LinkedList& l)	//Implementation of overloading the += operator
{
	int length = l.getLength();
	value_type data = l.current->getData();
	l.start();
	for (int i = 0; i < length; i++)
	{
		addToTail(data);
		l.forward();
	}
}


ostream& operator <<(ostream& out, LinkedList& l)	//Implementation of overloading the << operator
{
	int length = l.getLength();
	l.start();
	for (int i = 0; i <= length; i++)
	{
		out << l.getFromCurrent() << " ";
	}
	l.forward();
	return out;
}