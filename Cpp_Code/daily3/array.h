// File:     array.cpp
// Author:   Dustin Daily

// Description
// This file defines the class and methods for Array class

#ifndef _ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <stdexcept>
using namespace std;

namespace ArrayNameSpace
{
	template <class T>
	class Array
	{
		public:
			/*************************************************
			NAME: constructors, descructor, and copy constructor
			NEEDED TO RUN: none
			FUCTION: to create array or destroy it
			**************************************************/
			Array(int size=0);
			Array(int beg, int end);
			~Array();
			Array (const Array&);
			
			/*************************************************
			NAME: Resize
			NEEDED TO RUN: 1 int
			FUCTION: to resize and already made array
			**************************************************/
			void Resize(int resize);
			
			/*************************************************
			NAME: bool overloading [] operators
			NEEDED TO RUN: 1 int
			FUCTION: to made exceptions for negative numbers
			**************************************************/
			T& operator[](int index);
			const T& operator[](int index) const;
			
			/*************************************************
			NAME: operator=
			NEEDED TO RUN: 1 array
			FUCTION: to copy all values from one array to another
			**************************************************/
			const Array& operator= (const Array&);
			
			/*************************************************
			NAME: bool checking operators
			NEEDED TO RUN: 2 object or 1 object and 1 number
			FUCTION: to check if equal, less than, greater than
			**************************************************/
			bool operator==(const Array& array) const;
			bool operator<(const Array& array) const;
			bool operator!=(const Array& array) const;
			bool operator<=(const Array& array) const;
			bool operator>(const Array& array) const;
			bool operator>=(const Array& array) const;


		/*************************************************
		NAME: private variables
		NEEDED TO RUN: none
		FUCTION: to hold informaton about array and array pointer
		**************************************************/			
		private:
			int size;
			int offset;
			int beg;
			int end;
			T *theArray;
			
			
			
	};
	
  // method - constructor (default=0)
  // description - to create an array with input size
  // preconditions - none
  // postconditions - none
  // method input - 1 int or none
  // method output - true or false
template <class T>
Array<T>::Array(int s)
{
   theArray = new T[s];
   size = s;
   offset = 0;
}

  // method - constructor (2 ints)
  // description - make the size of array the difference of 2 ints
  // preconditions - 2 ints input
  // postconditions - none
  // method input - 2 int
  // method output - true or false
template <class T>
Array<T>::Array(int b, int e)
{
	size = e - b + 1;
   theArray = new T[size];
	offset = b * -1;
   
}

  // method - destructor
  // description - to destroy an array
  // preconditions - array is created
  // postconditions - none
  // method input - none
  // method output - none
template <class T>
Array<T>::~Array()
{
   delete [] theArray;
   theArray = NULL;
}

  // method - copy constructor
  // description - make a new array with all values
  // preconditions - array is created
  // postconditions - none
  // method input - 1 array
  // method output - none
template <class T>
Array<T>::Array(const Array<T>& array)
{
   theArray = new T[array.size];
   size = array.size;
	offset = array.offset;
   for (int i=0; i<size; i++)
      theArray[i] = array.theArray[i];
}

  // method - Resize (int)
  // description - resize the size of array
  // preconditions - 1 int input
  // postconditions - none
  // method input - 1 int
  // method output - none
template <class T>
void Array<T>::Resize(int resize)
{
  
  int tempSize = resize - size;
  
  if(tempSize > 0)
  {
	  size = resize;
  }
  else
  {
	  for(int i = size - 1; i >= resize; i--)
		theArray[i] = 0;
	  size = resize;	  
  }

}

  // method - operator []
  // description - to overload the [] operator
  // preconditions - 1 int entered
  // postconditions - none
  // method input - 1 int
  // method output - true or false
template <class T>
T& Array<T>::operator[](int index)
{

	int tempIndex = index + offset;
	
   if(size < 0 || tempIndex >= size)
   {
	   throw out_of_range("Out of range on Array");
   }
   else
   {
		return theArray[tempIndex];   
   }
   
}

  // method - Operator[] (pass by reference)
  // description - to overload the [] operator
  // preconditions - 1 int entered
  // postconditions - none
  // method input - 1 int
  // method output - T
template <class T>
const T& Array<T>::operator[](int index) const
{

	int tempIndex = index + offset;
	
   if(size < 0 || tempIndex >= size)
   {
	   throw out_of_range("Out of range on Array");
   }
   else
   {
		return theArray[tempIndex];   
   }
}

  // method - operator= (T)
  // description - to make array equal other array
  // preconditions - 2 array input
  // postconditions - none
  // method input - 2 array
  // method output - T
template <class T>
const Array<T>& Array<T>::operator= (const Array<T>& array)
{
   if (&array != this)
   {
      delete [] theArray;
      theArray = new T[array.size];
      size = array.size;
		offset = array.offset;
      for (int i=0; i<size; i++)
         theArray[i] = array.theArray[i];
   }
   
   return *this;
}

 // method - == operator (value)
  // description - to check is values are equal
  // preconditions - 2 values input
  // postconditions - none
  // method input - 2 values
  // method output - true or false
template <class T>
bool Array<T>::operator==(const Array& a) const
{
	bool check = false;
	int bigSize;
	
	if(size > a.size)
	{
		bigSize = size;
	}
	else
	{
		bigSize = a.size;
	}
	
	for(int i = 0; i < bigSize; i++)
	{
		if(theArray[i] == a.theArray[i])
		{
			check = true;
		}
	}	
   return check;
}

  // method - < operator (value)
  // description - to check if value is less than other value
  // preconditions - 2 values input
  // postconditions - none
  // method input - 2 values
  // method output - true or false
template <class T>
bool Array<T>::operator<(const Array& a) const
{
	bool check = false;
	int bigSize;
	
	if(size > a.size)
	{
		bigSize = size;
	}
	else
	{
		bigSize = a.size;
	}
	
	for(int i = 0; i < bigSize; i++)
	{
		if(theArray[i] < a.theArray[i])
		{
			check = true;
		}
	}	
   return check;
}

  // method - > operator (value)
  // description - to check if value is less than other value
  // preconditions - 2 values input
  // postconditions - none
  // method input - 2 values
  // method output - true or false
template <class T>
bool Array<T>::operator>(const Array& a) const
{
	return !(*this < a);
}
	
  // method - <= operator (value)
  // description - to check if value is less than other value
  // preconditions - 2 values input
  // postconditions - none
  // method input - 2 values
  // method output - true or false
template <class T>
bool Array<T>::operator<=(const Array& a) const
{
	if((*this < a) || (*this == a))
		return true;
	else
		return false;
}

  // method - >= operator (value)
  // description - to check if value is less than other value
  // preconditions - 2 values input
  // postconditions - none
  // method input - 2 values
  // method output - true or false
template <class T>
bool Array<T>::operator>=(const Array& a) const
{
	if(!(*this < a) || (*this == a))
		return true;
	else
		return false;
}

  // method - != operator (value)
  // description - to check if value is less than other value
  // preconditions - 2 values input
  // postconditions - none
  // method input - 2 values
  // method output - true or false
template <class T>
bool Array<T>::operator!=(const Array& a) const
{
	return !(*this == a);
}

	
}//end namespace

#endif
