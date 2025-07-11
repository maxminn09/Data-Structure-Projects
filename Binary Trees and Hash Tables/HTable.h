/*  Name:Minn Thet Tin */

#ifndef MAX_HTABLE
#define MAX_HTABLE

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

template <typename T>
class HTable
{
	public:

		//constructor
		HTable();									//default constructor

		//destructor
		~HTable();									//default deconstructor
		
		//adding data
		void add(T data);							//adds data to the hash table
		
		//removing data
		void remove(T data);						//removes data from the hash table
		
		//displaying data
		void display();								//displays data from the hash table
		
		//calculations
		int calculateParts();						//calculates the total types of data
		int calculateInventory();					//calculates the total parts of data

		
	private:
		const static int size = 5000;				//size of the array
		LinkedList<T>* array[size];					//creates an array of type LinkedList
		int hashfunc(const T& value);				//hashfunction for the hash table
		bool checkData(LinkedList<T>* ll, T data);	//function to check if data entry is in the table
};

template <typename T>
ostream& operator <<(ostream& out, HTable<T>& hashTable);	//overloading the output operator

#include "HTable.hpp"
#endif