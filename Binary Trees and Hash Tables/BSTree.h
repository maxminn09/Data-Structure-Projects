/*  Name:Minn Thet Tin */

#ifndef MAX_BSTREE
#define MAX_BSTREE

#include <iostream>
#include <cstdlib>
#include "BTNode.h"

using namespace std;

template <typename T>
class BSTree
{
	public:
	
		//constructors
		BSTree();										//default constructor
		BSTree(T data);									//constructor with data

		//destructor
		~BSTree();										//default deconstructor

		//adding data
		void add(T newData);							//adds data to the tree

		//removing data
		void remove(T data);							//removes data from the tree
			
		//displaying data
		void display();									//displays data from the tree
		
		//calculations
		int calculateParts();							//calculates the total types of data
		int calculateInventory();						//calculates the total parts of data
		
		
	private:
		BTNode<T>* root; 								//root node of the tree
		BTNode<T>* current;								//current node of the tree
		void insert(BTNode<T>* a, BTNode<T>* b);		//helper function to add
		void inorder(BTNode<T>* a);						//helper function to display in an inorder traversal
		void deleteTree(BTNode<T>* a);					//function for the deconstructor
		int partHelper(BTNode<T>* a);					//helper function to calculateParts
		int invHelper(BTNode<T>* a);					//helper function to calculateInventory
		BTNode<T>* find(T data);						//function to find data in the tree
		BTNode<T>* findHelper(BTNode<T>* a, T data);	//helper function to find
		BTNode<T>* smallestRight(BTNode<T>* a);			//function to find the smallest right node in the tree
		BTNode<T>* smallestRightHelper(BTNode<T>* a);	//helper function to smallestRight
		void swap(BTNode<T>* a, BTNode<T>* b);			//swaps the data in 2 nodes for removal purposes
};

template <typename T>
ostream& operator <<(ostream& out, BSTree<T>& tree);	//overloading the output operator

#include "BSTree.hpp"
#endif
