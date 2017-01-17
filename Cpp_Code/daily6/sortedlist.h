// File:     sortedList.h
// Author:   Dustin Daily

// Description
// This file defines the class and methods for sortedList class

#ifndef _SORTEDLIST_H_
#define _SORTEDLIST_H_


#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

enum formatType {ASCENDING, DESCENDING};

template <class T>
class SortedList : public list<T>
{
	public:
	
      // method - constructor
      // description - construct a new SortedList object
      // preconditions - none
      // postconditions - SortedList object created and initialized 
      // method input - none
      // method output - none
		SortedList();
		
      // method - constructor (formatType)
      // description - construct a new SortedList object
      // preconditions - none
      // postconditions - SortedList object created and initialized 
      // method input - none
      // method output - none
		SortedList(formatType format);
		
      // method - traverse (pointer to a function)
      // description - takes a pointer to a function and passes the 
	  // function call to traverse the list
      // preconditions - function and list need to be exsisting
      // postconditions - none
      // method input - function name
      // method output - none
		void traverse(void (*) (const T&)) const;
		
      // method - traverse (const pointer to a function)
      // description - takes a const pointer to a function and passes the 
	  // function call to traverse the list
      // preconditions - list need to be exsisting
      // postconditions - none
      // method input - function name
      // method output - none		
		void traverse(void (*) (T&));
		
      // method - insert (const T &item)
      // description - takes a const <T> item and inserts it into the list in order
	  // corresponding to the formatType(ASCENDING or DESCENDING)
      // preconditions - list needs to be exsisting
      // postconditions - none
      // method input - <T> item
      // method output - none
		void insert (const T &item);
		
      // method - erase (T item)
      // description - deletes the item out of the list
      // preconditions - list needs to be exsisting and item exsists
      // postconditions - none
      // method input - <T> item
      // method output - none
		void erase(T item);
		
      // method - remove (T item)
      // description - removes all elements that are the same as <T> item
      // preconditions - list needs to be exsisting and elements exsist
      // postconditions - none
      // method input - <T> item
      // method output - none
		void remove(T item);
		
      // method - reset
      // description - moves the itorator to the begining of the list
      // preconditions - list needs to be exsisting and elements exsist
      // postconditions - none
      // method input - none
      // method output - none
		void reset();
		
      // method - current
      // description - shows the element that the itorator is on gives a range_error
	  // if the current is at the end of the list
      // preconditions - list needs to be exsisting and elements exsist
      // postconditions - none
      // method input - none
      // method output - <T> item that current is on
		T current() throw(range_error);
		
      // method - next
      // description - moves the itorator to the next element will give a range_error
	  // if it tries to access the element beyond the last
      // preconditions - list needs to be exsisting and elements exsist
      // postconditions - none
      // method input - none
      // method output - none
		void next() throw(range_error);
		
      // method - prev
      // description - moves the itorator to the previous element will give a range_error
	  // if it tries to access the element before the beginning
      // preconditions - list needs to be exsisting and elements exsist
      // postconditions - none
      // method input - none
      // method output - none
		void prev() throw(range_error);
		
      // method - endOfList
      // description - will give a true if the itorator is at the end of the list
      // preconditions - list needs to be exsisting and elements exsist
      // postconditions - none
      // method input - none
      // method output - true or false
		bool endOfList();
		
      // method - inList (<T> item)
      // description - will give a true if the element exsists in the list
      // preconditions - list needs to be exsisting and elements exsist
      // postconditions - none
      // method input - none
      // method output - true or false
		bool inList(T);
		
      // method - count (<T> item)
      // description - will return the count in the list
      // preconditions - list needs to be exsisting and elements exsist
      // postconditions - none
      // method input - none
      // method output - an integer of how big the list is
		int count(T);
		
      // method - reverse
      // description - calls the list function to reverse the list elements order
	  // locally will switch the formatType and reverse the order of the list
      // preconditions - list needs to be exsisting and elements exsist
      // postconditions - none
      // method input - none
      // method output - none
		void reverse();
		
      // method - merge(SortedList& other list)
      // description - will switch the formatType and order of elements 
	  // if different and insert the elements from the other list into list.
	  // At the end of the method the order and formatType will be changed back
	  // to normal if changed.
      // preconditions - list needs to be exsisting and elements exsist in 
	  // at least one list
      // postconditions - none
      // method input - none
      // method output - none
		void merge(SortedList& other);
	
	
	private:
		
		typename list<T>::iterator itorate;
		
		int counter;
		
		bool ascend;
		bool descend;
		bool otherAscendFlag;
		bool otherDescendFlag;
};


template <class T>
SortedList<T>::SortedList() : list<T>()
{
	ascend = true;
	descend = false;

	itorate = this->begin();
}

template <class T>
SortedList<T>::SortedList(formatType format) : list<T>()
{
	ascend = false;
	descend = false;
	
	if(format == ASCENDING)
	{
		ascend = true;
	}
	else
	{
		descend = true;
	}
	
	itorate = this->begin();
}

template <class T>
void SortedList<T>::traverse(void (*foo) (T&))
{
	typename list<T>::iterator itorate;
	
	for(itorate = list<T>::begin(); itorate!=list<T>::end(); itorate++)
	{
		func(*itorate);
	}
}

template <class T>
void SortedList<T>::traverse(void (*foo) (const T&)) const
{
	typename list<T>::const_iterator itorate;
	
	for(itorate = list<T>::begin(); itorate!=list<T>::end(); itorate++)
	{
		func(*itorate);
	}
}

template <class T>
void SortedList<T>::insert(const T &item)
{
	itorate = this->begin();
	
	if(this->size() > 0)
	{
		if(ascend == true)
		{
			while(itorate != this->end())
			{
				if((*itorate) >= item)
				{
					list<T>::insert(itorate, item);
					break;
				}
				itorate++;
				if(itorate == this->end())//if its at the end while looping
				{
					list<T>::insert(itorate, item);
				}
				
			}
		}
		if(descend == true)
		{
			while(itorate != this->end())
			{
				if((*itorate) <= item)
				{
					list<T>::insert(itorate, item);
					break;
				}
				itorate++;
				if(itorate == this->end())//if its at the end while looping
				{
					list<T>::insert(itorate, item);
				}
				
			}
		}
	}
	else
	{
		list<T>::insert(itorate, item);	
	}
}

template <class T>
void SortedList<T>::erase(T item)
{
	typename list<T>::iterator itorate;
	
	for(itorate = list<T>::begin(); itorate!=list<T>::end(); itorate++)
	{
		if((*itorate) == item)//needs to only happen once
		{
			list<T>::erase(itorate);//FUTURE REFERENCE: make sure to pass the location and not the item in erase()
			break;
		}
	}
}

template <class T>
void SortedList<T>::remove(T item)
{
	list<T>::remove(item);
}


template <class T>
void SortedList<T>::reset()
{
	itorate = this->list<T>::begin();
}

template <class T>
T SortedList<T>::current() throw (range_error)
{
	if(itorate != this->list<T>::end())
	{
		return *itorate;
	}
	else
	{
		throw(range_error("Attempt to access past end of list!"));
	}
}

template <class T>
void SortedList<T>::next() throw (range_error)
{
	if(!(endOfList()))
	{
		itorate++;
	}
	else
	{
		throw(range_error("Attempted next already past end of the list!"));
	}
}

template <class T>
void SortedList<T>::prev() throw (range_error)
{
	if(itorate != list<T>::begin())
	{
		itorate--;
	}
	else
	{
		throw(range_error("Attempt to move before the beginning of the list!"));
	}	
}

template <class T>
bool SortedList<T>::endOfList()
{
	if(itorate == (this->list<T>::end()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool SortedList<T>::inList(T item)
{
	typename list<T>::const_iterator itorate;
	
	for(itorate = list<T>::begin(); itorate!=list<T>::end(); itorate++)
	{
		if((*itorate) == item)
		{
			return true;
		}
	}	
	return false;
}

template <class T>
int SortedList<T>::count(T item)
{
	counter = 0;
	
	for(itorate = list<T>::begin(); itorate!=list<T>::end(); itorate++)
	{
		if((*itorate) == item)
		{
			counter++;
		}
	}
	return counter;
}

template <class T>
void SortedList<T>::reverse()
{
	if(ascend == true)
	{
		ascend = false;
		descend = true;
	}
	else if(descend == true)//make sure only one runs
	{
		descend = false;
		ascend = true;
	}
	
	list<T>::reverse();
}

template <class T>
void SortedList<T>::merge(SortedList& other)
{
	otherAscendFlag = false;
	otherDescendFlag = false;
	
	if(ascend == true)
	{
		if(other.ascend != true)
		{
			other.ascend = true;
			other.descend = false;
			otherAscendFlag = true;
			other.list<T>::reverse();
		}
	}
	else if(descend == true)
	{
		if(other.descend != true)
		{
			other.descend = true;
			other.ascend = false;
			otherDescendFlag = true;
			other.list<T>::reverse();
		}
	}

	for(other.itorate = other.list<T>::begin(); other.itorate!=other.list<T>::end(); other.itorate++)
	{
		insert(*other.itorate);
	}
		
	if(otherAscendFlag == true)
	{
		other.ascend = false;
		other.descend = true;
		other.list<T>::reverse();
	}
	if(otherDescendFlag == true)
	{
		other.descend = false;
		other.ascend = true;
		other.list<T>::reverse();
	}
}







#endif