//Header File Binary Search Tree

#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>
#include <cassert>
#include "binaryTree.h"

using namespace std;

template<class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem) const;
      //Function to determine if searchItem is in the binary 
      //search tree.
      //Postcondition: Returns true if searchItem is found in the 
      //               binary search tree; otherwise, returns false.

    void insert(const elemType& insertItem);
      //Function to insert insertItem in the binary search tree.
      //Postcondition: If there is no node in the binary search
      //               tree that has the same info as insertItem,
      //               a node with the info insertItem is created
      //               and inserted in the binary search tree.


    void deleteNode(const elemType& deleteItem);
      //Function to delete deleteItem from the binary search tree 
      //Postcondition: If a node with the same info as deleteItem 
      //               is found, it is deleted from the binary 
      //               search tree.
	  //               If the binary tree is empty or deleteItem
      //               is not in the binary tree, an appropriate
      //               message is ptinted.
    
    
      //Function to return the level of the tree where item is.
      //     The level is the number of branches from the root to the node. 
      //     The root is at level 0.
      //Input: item to find the level where it's at
      //Output: level where item is
      //Precondition:  item must be in the tree
      //Postcondition: Returns the level where item is
    int level(const elemType& item) const;
    
      //Function to output all items at the same level as item 
      //     (including the item itself) separated with a blank
      //Input: item to find the generation
      //Output: none
      //Precondition:  item must be in the tree
      //Postcondition: the items at the same level as item are output
    void generation(const elemType& item) const;

private:
    void deleteFromTree(nodeType<elemType>* &p);
      //Function to delete the node to which p points is deleted
      //from the binary search tree.
      //Postcondition: The node to which p points is deleted
      //               from the binary search tree.
 
      //Function to return the level of the tree where item is.
      //     The level is the number of branches from the root to the node. 
      //     The root is at level 0.
      //Input: item to find the level where it's at, root pointer
      //Output: level where item is
      //Precondition:  item must be in the tree
      //Postcondition: Returns the level where item is
    int levelRec(const elemType& item, nodeType<elemType> *p) const;
    
      //Function to output all items at the same level as item 
      //     (including the item itself) separated with a blank
      //Input: item to find the generation, root pointer
      //Output: none
      //Precondition:  item must be in the tree
      //Postcondition: the items at the same level as item are output
    void generationRec(const elemType& item, int levelOn, nodeType<elemType> *p) const;
    
};


template<class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem) const
{
    nodeType<elemType> *current;
    bool found = false;

    if (binaryTreeType<elemType>::root == NULL)
        cout << "Cannot search an empty tree." << endl;
    else
    { 
       current = binaryTreeType<elemType>::root;

       while (current != NULL && !found)
       {
             if (current->info == searchItem)
                 found = true;
              else
                  if (current->info > searchItem)
                      current = current->llink;
                  else
                      current = current->rlink;
       }//end while
    }//end else

    return found;
}//end search


template<class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)
{
    nodeType<elemType> *current;  //pointer to traverse the tree
    nodeType<elemType> *trailCurrent; //pointer behind current
    nodeType<elemType> *newNode;  //pointer to create the node

    newNode = new nodeType<elemType>;
    assert(newNode != NULL);
    newNode->info = insertItem;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (binaryTreeType<elemType>::root == NULL)
       binaryTreeType<elemType>::root = newNode;
    else
    {
       current = binaryTreeType<elemType>::root;
 
       while (current != NULL)
       {
           trailCurrent = current;

           if (current->info == insertItem)
           {
               cout << "The item to be inserted is already in ";
               cout << "the list -- duplicates are not allowed."
                    << endl;
               return;
           }
           else
               if (current->info > insertItem)
                   current = current->llink;
               else
                   current = current->rlink;
       }//end while

       if (trailCurrent->info > insertItem)
           trailCurrent->llink = newNode;
       else
           trailCurrent->rlink = newNode;
   }
}//end insert

template<class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem)
{
	nodeType<elemType> *current;  //pointer to traverse the tree
	nodeType<elemType> *trailCurrent; //pointer behind current
	bool found = false;

	if (binaryTreeType<elemType>::root == NULL)
		cout << "Cannot delete from an empty tree." 
		     << endl;
	else
	{
		current = binaryTreeType<elemType>::root;
		trailCurrent = binaryTreeType<elemType>::root;

		while (current != NULL && !found)
		{
			if (current->info == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;

				if (current->info > deleteItem)
					current = current->llink;
				else
					current = current->rlink;
			}
		}//end while

		if (current == NULL)
			cout << "The item to be deleted is not in the tree." 
			     << endl;
		else
			if (found)
			{
				if (current == binaryTreeType<elemType>::root)
					deleteFromTree(binaryTreeType<elemType>::root);
				else
					if (trailCurrent->info > deleteItem)
						deleteFromTree(trailCurrent->llink);
					else
						deleteFromTree(trailCurrent->rlink);
			}//end if
	}
}//end deleteNode

template<class elemType>
void bSearchTreeType<elemType>::deleteFromTree
                                 (nodeType<elemType>* &p)
{
     nodeType<elemType> *current;    //pointer to traverse 
                                     //the tree
     nodeType<elemType> *trailCurrent;   //pointer behind current
     nodeType<elemType> *temp;        //pointer to delete the node

     if (p == NULL)
         cout << "Error: The node to be deleted is NULL."
              << endl;
     else if (p->llink == NULL && p->rlink == NULL)
          {
             temp = p;
             p = NULL;
             delete temp;
          }
     else if (p->llink == NULL)
          {
             temp = p;
             p = temp->rlink;
             delete temp;
          }
     else if (p->rlink == NULL)
          {
             temp = p;
             p = temp->llink;
             delete temp;
          }
     else
     {
        current = p->llink;
        trailCurrent = NULL;

        while (current->rlink != NULL)
        {
            trailCurrent = current;
            current = current->rlink;
        }//end while

        p->info = current->info;

        if (trailCurrent == NULL) //current did not move; 
                                  //current == p->llink; adjust p
            p->llink = current->llink;
        else
            trailCurrent->rlink = current->llink;
 
        delete current;
     }//end else
}//end deleteFromTree

template <class elemType>
int bSearchTreeType<elemType>::level(const elemType& item) const
{
	return levelRec(item, binaryTreeType<elemType>::root);
}

template <class elemType>
int bSearchTreeType<elemType>::levelRec(const elemType& item, nodeType<elemType> *p) const
{

	if(p->info == item)
		return 0;
	else if(item < p->info)
	{
		if(p == NULL)
		{
			return 0;
		}
		else
		{
			return 1 + (levelRec(item, p->llink));			
		}
	}
	else if(item > p->info)
	{
		if(p == NULL)
		{
			return 0;
		}
		else
		{
			return 1 + (levelRec(item, p->rlink));			
		}

	}
	else
	{
		return 0;
	}

}

template <class elemType>
void bSearchTreeType<elemType>::generation(const elemType& item) const
{
	int i = level(item)+1;
	generationRec(item, i, binaryTreeType<elemType>::root);
	cout << endl;
}

template <class elemType>
void bSearchTreeType<elemType>::generationRec(const elemType& item, int levelOn, nodeType<elemType> *p) const
{
	if(p == NULL)
		return;
	else if(1 == levelOn)
		cout << p->info << ' ';
	else
	{
		generationRec(item, levelOn-1, p->llink);
		generationRec(item, levelOn-1, p->rlink);	
	}

}
	
	

#endif

