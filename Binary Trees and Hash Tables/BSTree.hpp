/*  Name:Minn Thet Tin */

#include "BSTree.h"

//constructors
template <typename T>
BSTree<T>::BSTree()												//default constructor
{
	root = NULL;
	current = NULL;
	
}

template <typename T>
BSTree<T>::BSTree(const T data)									//default constructor with data
{
	root = new BTNode<T>(data);
	current = root;
}

//destructor
template <typename T>
BSTree<T>::~BSTree()											//default deconstructor
{
	deleteTree(root);	//calls the function to delete the whole tree
}

//adding data
template <typename T>
void BSTree<T>::add(T newData)						//adds data to the tree
{
	if (root == NULL)								//if there is no data in the tree
	{
		root = new BTNode<T>(newData);
		return;
	}
	else {
	BTNode<T>* newNode = new BTNode<T>(newData);	//adds new node with new data if root exists
	insert(root, newNode);  //calls helper function to add
}
}

//removing data
template <typename T>
void BSTree<T>::remove(T data)						//removes data from the tree

{	
    BTNode<T>* removeNode = find(data);				//creates a node to find and remove

    if (!(removeNode->getData() == data))			//if data is not found in the tree
    {
        delete removeNode; 
        return;
    }

    if (removeNode->getLeft() == NULL && removeNode->getRight()==NULL)		//if the removing node is a leaf
    {
        if (removeNode->getParent()->getRight() == removeNode)
        {
            removeNode->getParent()->setRight(NULL);
            delete removeNode;
            return;
        }
        else
        {
            removeNode->getParent()->setLeft(NULL);
            delete removeNode;
            return;
        }
    }

    BTNode<T>* smallestRightNode = smallestRight(removeNode);		//gets the smallest right node

    if (smallestRightNode == NULL) 
    {
        if (removeNode == root)										 //if the removing node is the root
        {
            root = removeNode->getLeft();
            root->setParent(NULL);
            delete removeNode;
            return;
        }
        else
        {
            if (removeNode->getParent()->getRight() == removeNode)		//if the removing node has a right child
            {
                removeNode->getParent()->setRight(removeNode->getLeft()); 	
            }
            else 														//if the removing node has a left child
            {
                removeNode->getParent()->setLeft(removeNode->getLeft()); 	
            }
            removeNode->getLeft()->setParent(removeNode->getParent());		
            delete removeNode;
            return;
        }
    }

    
    else 			// if the removing node is internal 
    {	
        swap(smallestRightNode, removeNode); 		//if the removing node has smallest right child
        if (smallestRightNode->getParent()->getLeft() == smallestRightNode)			
        {
            smallestRightNode->getParent()->setLeft(smallestRightNode->getRight());
            if (smallestRightNode->getRight() != NULL)
            {
                smallestRightNode->getRight()->setParent(smallestRightNode->getParent());
            }
            delete smallestRightNode;
            return;
        }
        else if (smallestRightNode->getParent()->getRight() == smallestRightNode)
        {
            
            smallestRightNode->getParent()->setRight(smallestRightNode->getRight());
            if (smallestRightNode->getRight() != NULL)
            {
                smallestRightNode->getRight()->setParent(smallestRightNode->getParent());
            }
            delete smallestRightNode;
            return;
        }
        else 			//if smallest right has no child
        {
            smallestRightNode->getParent()->setLeft(NULL);
            delete smallestRightNode;
            return;
        }
    }
}

template <typename T>
void BSTree<T>::display()
{
	if (root == NULL)	//if the tree is empty
	{
		return;
	}
	if (root->getLeft() == NULL)	//if the left side of the tree is empty
	{
		if (root->getRight() == NULL)	//if the right side of the tree is empty
		{
			cout << root->getData();	//displays the data in the root
			return;
		}
	}
	current = root;
	inorder(current);
	return;
}

template <typename T>
int BSTree<T>::calculateParts()			//calculates the total types of data

{
	int sum = 0;
    if (root == NULL) 		//if there is no tree
        {
            return 0;
        }
    if (root->getLeft() == NULL && root->getRight() == NULL) 	//if the tree exists but root has no children
    {
        return root->getData().get_quantity(); 
    }
    sum += partHelper(root);			//calls a helper function to calculate types
    return sum;
}

template <typename T>
int BSTree<T>::calculateInventory()		//calculates the total parts of data

{
	int sum = 0;
    if (root == NULL) 		//if there is no tree
        {
            return 0;
        }
    if (root->getLeft() == NULL && root->getRight() == NULL) //if the tree exists but root has no children
    {
        return root->getData().get_quantity(); 
    }
    sum += invHelper(root);				//calls a helper function to calculate parts
    return sum;
}

template <typename T>
void BSTree<T>::insert(BTNode<T>* a, BTNode<T>* b) 						//helper function to add
{
	if (a->getData() == b->getData()) 									//if data already exists in the tree, do nothing to preserve tree quality
	{
		return; 
	} 
	if (a->getData() < b->getData()) 									//if the new node is bigger than the original node
	{
		if (a->getRight() == NULL)
		{
			a->setRight(b);
			b->setParent(a);
			return;
		}
		else
		{
			insert(a->getRight(), b);
			return;
		}
	}
	if (a->getData() > b->getData())									 //if the new node is smaller than the original node
	{
		if (a->getLeft() == NULL)
		{
			a->setLeft(b);
			b->setParent(a);
			return;
		}
		else
		{
			insert(a->getLeft(), b );
			return;
		}
	}
}

template <typename T>
void BSTree<T>::inorder(BTNode<T>* a) 									//helper function to display in an inorder traversal
{
	if (a->getLeft() != NULL) 											//if the left child of the node exists
	{
		inorder(a->getLeft()); 
	}
	
	cout  << a->getData() << " "; 
	
	if (a->getRight() != NULL) 											//if the right child of the node exists
	{
		inorder(a->getRight()); 
	}
}


template <typename T>
BTNode<T>* BSTree<T>::find(T data)			//function to find data in the tree
{
	if (root == NULL)						//if there is no tree
	{
		return NULL;
	}
	if (root->getLeft() == NULL)			//if the tree exists but has no child
	{
		if (root->getRight() == NULL)
		{
			if (root->getData() == data) 
			{ 
			return root; 
			}
		}
		else
		{
            current = root;
            BTNode<T>* target = findHelper(current, data);
            if (target->getData() == data) 
			{ 
			return target; 
			}
		else
            return NULL;
		}
	}
	current = root;
	BTNode<T>* target = findHelper(current, data);	//calls a helper function to find data
	if (target->getData() == data) { 
	return target;
	}
	else
	return target; 		//if the data cannot be found
}

template <typename T>
BTNode<T>* BSTree<T>::findHelper(BTNode<T>* a, T data)			//helper function to find
{
    
    if ( a->getData() == data ) { 								//if data is found
	return a; 
	}
    if ( a->getData() > data )									//checks on the left side of the tree
    {
        if (a->getLeft() != NULL) 								//if the left child of the node exists
        {
            return findHelper(a->getLeft(), data); 
        }
    }
    else 														//checks on the right side of the tree
    {
        if (a->getRight() != NULL) 								//if the right child of the node exists
        {
            return findHelper(a->getRight(), data); 
        }
    }
	BTNode<T>* invalidNode = new BTNode<T>();					//if the node does not exist
	return invalidNode;
}

template <typename T>
BTNode<T>* BSTree<T>::smallestRight(BTNode<T>* a)				//function to find the smallest right node in the tree
{
	if (a->getRight() != NULL)
	{
	    return smallestRightHelper(a->getRight());
	}
	else
	return NULL; 												//if there is no smallest right node
}

template <typename T>
BTNode<T>* BSTree<T>::smallestRightHelper(BTNode<T>* a)			//helper function to smallestRight
{
    if (a->getLeft() != NULL)									
    {
        return smallestRightHelper(a->getLeft());
    }
    else 
	return a;
}

template <typename T>
void BSTree<T>::deleteTree(BTNode<T>* a)						//function for the deconstructor
{
    if ( a == NULL ) {
		return;
		} 
    if (a->getLeft() != NULL) 									//if the left child of the node exists
    {
        deleteTree(a->getLeft());
    }

    if (a->getRight() != NULL) 									//if the right child of the node exists.
    {
        deleteTree(a->getRight()); 
    }
    delete a; 
    return;
}

template <typename T>
int BSTree<T>::partHelper(BTNode<T>* a) 						//helper function to calculateParts
{
    int sum = a->getData().get_quantity(); 						
	if (a->getLeft() != NULL) 									//if the left child of the node exists
	{
		sum += partHelper(a->getLeft()); 
	}

	if (a->getRight() != NULL) 									//if the right child of the node exists
	{
		sum += partHelper(a->getRight()); 
	}
	return sum;
}

template <typename T>
int BSTree<T>::invHelper(BTNode<T>* a) 							//helper function to calculateInventory
{
    int sum = a->getData().get_quantity(); 
	if (a->getLeft() != NULL) 									//if the left child of the node exists
	{
		sum += invHelper(a->getLeft()); 
	}

	if (a->getRight() != NULL) 									//if the right child of the node exists
	{
		sum += invHelper(a->getRight()); 
	}
	return sum;
}

template <typename T>
void BSTree<T>::swap(BTNode<T>* a, BTNode<T>* b)				//swaps the data in 2 nodes for removal purposes
{
    T temp_data = a->getData();
    a->setData(b->getData());
    b->setData(temp_data);
}

//overloading the output operator
template <typename T>
ostream& operator <<(ostream& out, BSTree<T>& tree)
{
	tree.display();
	out << "" ;
	return out;
}