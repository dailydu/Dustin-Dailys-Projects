#include <iostream>
using namespace std;

#include "linkedQueue.h"


int main()
{
   linkedQueueType<int> list;
   linkedQueueType<int> list2;
   list.addQueue(43);
   list.addQueue(17);
   list.addQueue(-50);
   list.addQueue(37);
   list.addQueue(21);
   list2 = list;
   
      cout<<"list1 is: ";
   while (!list.isEmptyQueue())
   {
      cout << list.front() << ' ';
      list.deleteQueue();
   }
  	
   cout << endl;
   
   cout<<"list2 is: ";
   while (!list2.isEmptyQueue())
   {
      cout << list2.front() << ' ';
      list2.deleteQueue();
   }
   cout << endl << endl;
   
   list.addQueue(43);

   cout<<"before destroy(): ";
   while (!list.isEmptyQueue())
   {
      cout << list.front() << ' ';
      list.deleteQueue();
   }   
   
    list.addQueue(43);

   list.destroyQueue();
  
  cout << endl << endl;  
   
   cout<<"if nothin outputs then destroy works: ";
   while (!list.isEmptyQueue())
   {
      cout << list.front() << ' ';
      list.deleteQueue();
   }
   cout << endl;
   cout << endl;


   return 0;
}
   
   
