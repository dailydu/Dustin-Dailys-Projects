#ifndef H_hashtable
#define H_hashtable

#include <iostream>
#include <stdexcept>


using namespace std;

template <class T>
class HashEntry 
{     
public:
  // method - constructor
  // description - creates an object that takes in a T class and an int
  // preconditions - none
  // postconditions - none
  // method input - int, T class
  // method output - none
  HashEntry(int key, T value) 
   {
     this->key = key;
     this->value = value;
   }
      
  // method - getKey
  // description - returns the int
  // preconditions - none
  // postconditions - none
  // method input - none
  // method output - gives an int
   int getKey() 
   {
     return key;
   }
  // method - getValue
  // description - returns the value
  // preconditions - none
  // postconditions - none
  // method input - none
  // method output - outputs ths values
   T getValue() 
   {
     return value;
   }
  // method - operator==
  // description - compares the two values to see if they are the same
  // preconditions - none
  // postconditions - none
  // method input - another object
  // method output - true or false
    bool operator==(const HashEntry& hsh) const
    {
      return (key == hsh.key && value == hsh.value);
    }
private:
  int key;
  T value;
};
	
template <class T>
class HashTable
{
public:
  // method - constructor
  // description - creates an object that takes in a int, and fucntion pointer
  // preconditions - none
  // postconditions - none
  // method input - int, pointer to function
  // method output - none
  HashTable(int TABLE_SIZE, int (*) (const T&));
  // method - hash
  // description - pointer to the fuction in main.cpp called hash
  // preconditions - none
  // postconditions - none
  // method input - an int
  // method output - an int
  int (*hash) (const T&);
  // method - destructor
  // description - destroys the table
  // preconditions - contructor called
  // postconditions - none
  // method input - none
  // method output - none
  ~HashTable();
  // method - HashTable (other HashTable)
  // description - creates a hashtable from the exsisting properties of a HashTable
  // preconditions - none
  // postconditions - none
  // method input - another HashTable
  // method output - none
  HashTable(const HashTable<T> &);
  // method - retrieve
  // description - mutates the placeholders value and uses a symbol method to record it
  // preconditions - none
  // postconditions - none
  // method input - T object
  // method output - none
  void retrieve(T&) const;
  // method - insert
  // description - inserts an object into the array based on 
  // preconditions - none
  // postconditions - none
  // method input - T object
  // method output - none
  void insert(const T&);
  // method - search
  // description - searches for the T object and returns a true if found.
  // preconditions - array exsists
  // postconditions - none
  // method input - T object
  // method output - true or false
  bool search(const T&);
  // method - incrementCollisions
  // description - increments the static int
  // preconditions - none
  // postconditions - none
  // method input - none
  // method output - none
  static void incrementCollisions();
  // method - Collisions
  // description - returns the static int
  // preconditions - none
  // postconditions - none
  // method input - none
  // method output - int
  static int Collisions();
    

private:
  static int collision;
  HashEntry<T> **table;
  int tableSize;
};

template <class T>
int HashTable<T>::collision = 0;

template <class T>
HashTable<T>::HashTable(const int TABLE_SIZE, int(*z) (const T&))
{
  table = new HashEntry<T>*[TABLE_SIZE*10];
  
  for(int i=0; i<TABLE_SIZE; i++)
  {
    table[i] = NULL;
  }
  
  tableSize = TABLE_SIZE *10;
  hash = z;
}

template <class T>
HashTable<T>::~HashTable()
{
  for(int i=0; i<tableSize; i++)
  {
    if (table[i] != NULL)
      delete table[i];
  }
  delete[] table;
}

template <class T>
bool HashTable<T>::search(const T& item)
{
  int key = hash(item);
  while (key < tableSize)
  {

    if (table[key] != NULL && table[key] -> getValue() == item)
      return true;
    key = key+13;
  }
  
  return false;
}

template <class T>
void HashTable<T>::insert(const T& item)
{
  int key = hash(item);
  bool collided = false;

   if(key > tableSize)
   {
     throw runtime_error("Hash size is bigger than the table!");
   }
   while(key < tableSize)
   {
      if(table[key] == NULL)
      {
	table[key] = new HashEntry<T>(key, item);
	break;
      }
      else
      {
		key = key + 13;
		if(collided == false)
		{
			collided = true;
			incrementCollisions();
		}
		if(key > tableSize)
		{
			throw runtime_error("The table cannot take anymore collisions!");
		}
      }
   }
}

template <class T>
void HashTable<T>::retrieve(T& symbol) const
{
  int retr = hash(symbol);
  
  while(retr < tableSize)
  {
    if(table[retr] -> getValue() == symbol)
    {
      symbol.setValue(retr);
      break;
    }
    else
    {
      retr = retr + 13;
    }
  }
}

template <class T>
void HashTable<T>::incrementCollisions()
{
  collision = collision + 1;
}

template <class T>
int HashTable<T>::Collisions()
{
  return collision;
}


template <class T>
HashTable<T>::HashTable(const HashTable<T> & other)
{
    table = other.table;
    tableSize = other.tableSize;
    hash = other.hash;
}

#endif

