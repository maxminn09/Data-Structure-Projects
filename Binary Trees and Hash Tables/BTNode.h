/*  Name:Minn Thet Tin */

#ifndef MAX_BTNODE
#define MAX_BTNODE

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class BTNode
{
	public:
	
		//constructors
		BTNode(); 																				//default constructor
		BTNode(const T init_data);																//constructor with data
		BTNode(const T init_data, BTNode* init_parent, BTNode* init_left, BTNode* init_right);	//constructor with data and modifying other variables

		//destructor
		~BTNode();																				
		
		//setters
		void setLeft(BTNode* pointer_left);														//sets data for left child
		void setRight(BTNode* pointer_right);													//sets data for right child
		void setParent(BTNode* pointer_parent);													//sets data for parent of a node
		void setData(const T new_data);															//sets data for a node

		//getters
		const BTNode* getLeft() const;															//gets data for left child as a const
		BTNode* getLeft();																		//gets data for left child
		const BTNode* getRight() const;															//gets data for right child as a const
		BTNode* getRight();																		//gets data for right child
		const BTNode* getParent() const;														//gets data for parent of a node as a const
		BTNode* getParent();																	//gets data for parent of a node
		T getData() const; 																		//gets data of a node as a const
		T& getData(); 																			//gets data of a node
			
	private:
		T data;																					//data variable as a template
		BTNode* left;																			//pointer to the left child
		BTNode* right;																			//pointer to the right child
		BTNode* parent;																			//pointer to the parent of a node
};

#include "BTNode.hpp"
#endif
