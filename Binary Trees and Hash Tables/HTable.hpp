/*  Name:Minn Thet Tin */

#include "HTable.h"

// constructor
template <typename T>
HTable<T>::HTable()												//default constructor
{
    for (int i =0; i < size; i++)
    {
        array[i] = new LinkedList<T>();
    }
}

// destructor
template <typename T>
HTable<T>::~HTable()											//default deconstructor
{
    for(int i = 0; i < size; i++)
    {
        delete array[i];
    }
}

//adding data
template <typename T>
void HTable<T>::add(T data)										//adds data to the hash table
{
	int index = hashfunc(data);
	if(checkData(array[index], data) == false)					//checks if data entry is in the table
	{
	    array[index]->addToHead(data);
	}
}

//removing data
template <typename T>
void HTable<T>::remove(T data)									//removes data from the hash table
{
    int index = hashfunc(data);
	if(checkData(array[index], data))							//checks if data entry is in the table
    {
        array[index]->remove(data);
    }
}

//displaying data
template <typename T>
void HTable<T>::display()										//displays data from the hash table
{	
	for(int i = 0; i < size; i++)								//displays data from the start of the LinkedList array to the end
    {
        array[i]->start();
        for(int j=0; j < array[i]->getLength(); j++)
        {
            cout << array[i]->getFromCurrent();
            array[i]->forward();
        }
    }
}

//calculations
template <typename T>
int HTable<T>::calculateParts()									//calculates the total types of data
{	int sum = 0;
	for(int i = 0; i < size; i++) 
	{
	    array[i]->start();
	    for(int j=0; j < array[i]->getLength(); j++ ) 
	    {
	        if(array[i]->getFromCurrent().get_code().length() != 0){
	        sum ++;
	        array[i]->forward();
			
	    }
	}
}
return sum;
}

template <typename T>
int HTable<T>::calculateInventory()								//calculates the total parts of data
{
	int sum = 0;
	for(int i = 0; i < size; i++) 
	{
	    array[i]->start();
	    for(int j=0; j < array[i]->getLength(); j++ ) 
	    {	
			sum += array[i]->getFromCurrent().get_quantity();
	        array[i]->forward();
	    }
	}
	return sum;
}

template <typename T>
int HTable<T>::hashfunc ( const T& value ) {					//hashfunction for the hash table
	int position = 0;
	string temp = value.get_code ( );
	for ( int i=0; i<(int)temp.length( ); i++ ) {
	position += ( i+1 ) * ( i+1 ) * temp.at( i );
}
	return position % size;
}

template <typename T>
bool HTable<T>::checkData(LinkedList<T>* ll, T data)			//function to check if data entry is in the table
{
    ll->start();
    for (int i = 0; i < ll->getLength(); i++)
    {
        T part = ll->getFromCurrent();
        if (part == data)
        {
            return true;
        }
        else
        {
        ll->forward();
        }
    }
    return false;
}

template <typename T>
ostream& operator <<(ostream& out, HTable<T>& hashTable)	//overloading the output operator
{
	hashTable.display();
	out << "";
	return out;
}