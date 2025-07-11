/*  Name:Minn Thet Tin */

#include <iostream>

using namespace std;

template <typename T>
BTNode<T>::BTNode()									//implementation of default constructor
{	left = NULL;
	right = NULL;
	parent = NULL;
}

template <typename T>
BTNode<T>::BTNode(const T init_data)				//implementation of constructor with data
{
	data = init_data;
	left = NULL;
	right = NULL;
	parent = NULL;
}

template <typename T>
BTNode<T>::BTNode(const T init_data, BTNode* init_parent, BTNode* init_left, BTNode* init_right)		//implementation of constructor with data and modifying other variables
{
	data = init_data;
	left = init_left;
	right = init_right;
	parent = init_parent;
}

template <typename T>
BTNode<T>::~BTNode(){}									//implementation of deconstructor
	
template <typename T>
void BTNode<T>::setLeft(BTNode<T>* pointer_left)		//implementation of setting the left child
{
	left = pointer_left;
}

template <typename T>
void BTNode<T>::setRight(BTNode<T>* pointer_right)		//implementation of setting the right child
{
	right = pointer_right;
}

template <typename T>
void BTNode<T>::setParent(BTNode<T>* pointer_parent)	//implementation of setting the parent of a node
{
	parent = pointer_parent;
}

template <typename T>
void BTNode<T>::setData(const T new_data)				//implementation of setting the data
{
	data = new_data;
}

template <typename T>
BTNode<T>* BTNode<T>::getLeft()							//implementation of getting the left child
{
	return left;
}

template <typename T>
const BTNode<T>* BTNode<T>::getLeft() const				//implementation of getting the left child as a const
{
	return left;
}

template <typename T>
BTNode<T>* BTNode<T>::getRight() 						//implementation of getting the right child
{
	return right;
}

template <typename T>
const BTNode<T>* BTNode<T>::getRight() const			//implementation of getting the right child as a const
{
	return right;
}

template <typename T>
BTNode<T>* BTNode<T>::getParent() 						//implementation of getting the parent of a node
{
	return parent;
}

template <typename T>
const BTNode<T>* BTNode<T>::getParent() const			//implementation of getting the parent of a node as a const
{
	return parent;
}

template <typename T>
T BTNode<T>::getData() const							//implementation of getting the data as a const
{
	return data;
}

template <typename T>
T& BTNode<T>::getData() 								//implementation of getting the data
{
	return data;
}


