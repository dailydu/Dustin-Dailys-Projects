//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

	//Definition of the Node
template <class elemType>
struct nodeType
{
	elemType			info;
	nodeType<elemType>  *llink;
	nodeType<elemType>  *rlink;
};
	
	//Definition of the class
template <class elemType>
class binaryTreeType
{
public:
      //Function to return true or false if in tree
      //Input: element to be searched
      //Output: true or false
      //Precondition:  must be exsisting
      //Postcondition: None
	bool search(const elemType& searchItem);
	
      //Function to return number of nodes with one child
      //Input: none
      //Output: the number of nodes with one child
      //Precondition:  none
      //Postcondition: Returns the number of nodes with one child
	int oneChildCount() const;
	
      //Function to return number of nodes with two children
      //Input: none
      //Output: the number of nodes with two children
      //Precondition:  none
      //Postcondition: Returns the number of nodes with two children
	int twoChildrenCount() const;

      //Function to return number of nodes that are not leaves
      //Input: none
      //Output: the number of nodes that are not leaves
      //Precondition:  none
      //Postcondition: Returns the number of nodes that are not leaves
	int nonLeavesCount() const;

      //Function to do a breadth first traversal of the tree
      //Input: a pointer to a function to execute on each item
      //Output: none
      //Precondition:  none
      //Postcondition: the traversal visits each node
	void breadthFirstTraversal(void (*visit) (elemType&)) const;
	
      //Function to return whether the tree is balanced (by definition) or not
      //Input: none
      //Output: whether tree is balanced or not (bool)
      //Precondition:  none
      //Postcondition: Returns true if tree is balanced, false otherwise
	bool balanced() const;
	
      //Function to output the path from the item to the root with each
      //     item separated with a blank
      //Input: item to find the path
      //Output: none
      //Precondition:  item must be in the tree
      //Postcondition: the path is output
	void path(const elemType& item) const;
	
      //Function to return whether the items are siblings (by definition) or not
      //Input: two items of the type stored in the tree
      //Output: true if the items are siblings, otherwise false
      //Precondition: none 
      //Postcondition: whether items are siblings is returned
	bool siblings(const elemType& item1, const elemType& item2) const;
	
      //Input: none
      //Output: whether tree is full or not (bool)
      //Function to return whether the tree is full (by definition) or not
      //Precondition:  none
      //Postcondition: Returns true if tree is full, false otherwise
	bool full() const;

    const binaryTreeType<elemType>& operator=
                 (const binaryTreeType<elemType>&); 
      //Overload the assignment operator.
    bool isEmpty() const;
      //Function to determine whether the binary tree
	  //is empty.
	  //Postcondition: Returns true if the binary tree is empty;
      //               otherwise, returns false.
    void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.
	  //Postcondition: Nodes are printed in inorder sequence.
    void preorderTraversal() const;
      //Function to do a preorder traversal of the binary tree.
	  //Postcondition: Nodes are printed in preorder sequence.
    void postorderTraversal() const;
      //Function to do a postorder traversal of the binary tree.
	  //Postcondition: Nodes are printed in postorder sequence.

	void inorderTraversal(void (*visit) (elemType&)) const;
	  //Function to do an inorder traversal of the binary tree.
	  //The parameter visit, which is a function, specifies
	  //the action to be taken at each node.
	  //Postcondition: The action specified by the function visit
	  //               is applied to each node of the binary tree.

    int treeHeight() const;
      //Funtion to determine the height of a binary tree.
	  //Postcondition: Returns the height of the binary tree.
    int treeNodeCount() const;
      //Funtion to determine the number of nodes in a 
	  //binary tree.
      //Postcondition: Returns the number of nodes in the 
	  //               binary tree.
    int treeLeavesCount() const;
      //Funtion to determine the number of leaves in a 
	  //binary tree.
      //Postcondition: Returns the number of leaves in the 
	  //               binary tree.
    void destroyTree();
      //Function to destroy the binary tree.
	  //Postcondition: Memory space occupied by each node 
	  //               is deallocatd.
      //               root = NULL;

    binaryTreeType(const binaryTreeType<elemType>& otherTree); 
      //copy constructor

    binaryTreeType();   
      //default constructor

    ~binaryTreeType();   
      //destructor

protected:
    nodeType<elemType>  *root;

private:
    void copyTree(nodeType<elemType>* &copiedTreeRoot,
                  nodeType<elemType>* otherTreeRoot);
      //Makes a copy of the binary tree to which 
      //otherTreeRoot points. 
	  //Postcondition: The pointer copiedTreeRoot points to
      //               the root of the copied binary tree.
    void destroy(nodeType<elemType>* &p);
      //Function to destroy the binary tree to which p points. 
      //Postcondition: Memory space occupied by each node, in the
	  //               binary tree to which p points, is deallocatd.
      //               p = NULL;

    void inorder(nodeType<elemType> *p) const;
      //Function to do an inorder traversal of the binary
      //tree to which p points.  
	  //Postcondition: Nodes of the binary tree, to which p
	  //               points, are printed in inorder sequence.
    void preorder(nodeType<elemType> *p) const;
      //Function to do a preorder traversal of the binary
      //tree to which p points.  
	  //Postcondition: Nodes of the binary tree, to which p
	  //               points, are printed in preorder sequence.
    void postorder(nodeType<elemType> *p) const;
      //Function to do a postorder traversal of the binary
      //tree to which p points.  
	  //Postcondition: Nodes of the binary tree, to which p
	  //               points, are printed in postorder sequence.

	void inorder(nodeType<elemType> *p, void (*visit) (elemType&)) const;
	  //Function to do an inorder traversal of the binary
	  //tree starting at the node specified by the parameter p. 
	  //The parameter visit, which is a function, specifies the
	  //action to be taken at each node.
	  //Postcondition: The action specified by the function visit
	  //               is applied to each node of the binary tree
	  //               to which p points.

    int height(nodeType<elemType> *p) const;
      //Function to determine the height of the binary tree
      //to which p points. 
	  //Postcondition: Height of the binary tree to which 
	  //               p points is returned.
    int max(int x, int y) const;
      //Function to determine the larger of x and y.
	  //Postcondition: Returns the larger of x and y.
    int nodeCount(nodeType<elemType> *p) const;
      //Function to determine the number of nodes in 
      //the binary tree to which p points. 
  	  //Postcondition: The number of nodes in the binary 
	  //               tree to which p points is returned.
    int leavesCount(nodeType<elemType> *p) const;
      //Function to determine the number of leaves in  
      //the binary tree to which p points 
 	  //Postcondition: The number of leaves in the binary 
	  //               tree to which p points is returned.
	  
      //Function to return true or false if in tree
      //Input: element to be searched, root pointer
      //Output: true or false
      //Precondition:  must be exsisting
      //Postcondition: None
      bool searchRec(const elemType& searchItem, nodeType<elemType> *p);
	  
      //Function to return number of nodes with one child
      //Input: root pointer
      //Output: the number of nodes with one child
      //Precondition:  none
      //Postcondition: Returns the number of nodes with one child
	  int oneChildCountRec(nodeType<elemType> *p) const;
	  
      //Function to return number of nodes with two children
      //Input: root pointer
      //Output: the number of nodes with two children
      //Precondition:  none
      //Postcondition: Returns the number of nodes with two children
	  int twoChildrenCountRec(nodeType<elemType> *p) const;
	  
      //Function to return number of nodes that are not leaves
      //Input: root pointer
      //Output: the number of nodes that are not leaves
      //Precondition:  none
      //Postcondition: Returns the number of nodes that are not leaves
	  int nonLeavesCountRec(nodeType<elemType> *p) const;

      //Function to do a breadth first traversal of the tree
      //Input: a pointer to a function to execute on each item, an int, and pointer to a function 
      //Output: none
      //Precondition:  none
      //Postcondition: the traversal visits each node
	void breadthFirstTraversalRec(nodeType<elemType> *p, int num, void (*visit) (elemType&)) const;
	

	void pathRec(const elemType& item, nodeType<elemType> *p, stack<elemType>& stacker) const;
	
      //Function to return whether the items are siblings (by definition) or not
      //Input: two items of the type stored in the tree, and a root pointer
      //Output: true if the items are siblings, otherwise false
      //Precondition: none 
      //Postcondition: whether items are siblings is returned
	bool siblingsRec(const elemType& item1, const elemType& item2, nodeType<elemType> *p) const;
	  
      //Function to return whether the tree is balanced (by definition) or not
      //Input: root pointer
      //Output: whether tree is balanced or not (bool)
      //Precondition:  none
      //Postcondition: Returns true if tree is balanced, false otherwise
	  bool balancedRec(nodeType<elemType> *p) const;
};

	//Definition of member functions

template<class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = NULL;
}

template<class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
	return (root == NULL);
}

template<class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
	inorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
	preorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
	postorder(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
	return height(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
	return nodeCount(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
	return leavesCount(root);
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree
                      (nodeType<elemType>* &copiedTreeRoot,
		               nodeType<elemType>* otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new nodeType<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
} //end copyTree

template<class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p) const
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info << " ";
		inorder(p->rlink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p) const
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p) const
{
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}		
}

   //Overload the assignment operator
template<class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
           operator=(const binaryTreeType<elemType>& otherTree)
{ 
	if (this != &otherTree) //avoid self-copy
	{
		if (root != NULL)  //if the binary tree is not empty, 
			              //destroy the binary tree
			destroy(root);

		if (otherTree.root == NULL) //otherTree is empty
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}//end else

   return *this; 
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(nodeType<elemType>* &p)
{
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
	destroy(root);
}

	//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
              (const binaryTreeType<elemType>& otherTree)
{
	if (otherTree.root == NULL) //otherTree is empty
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}

template<class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p) const
{
	if(p == NULL)
		return 0;
	else
		return 1 + (max(height(p->llink), height(p->rlink)));
}

template<class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}

template<class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType> *p) const
{
	if(p == NULL)
		return 0;
	else
		return 1 + (nodeCount(p->llink) + nodeCount(p->rlink));
}

template<class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p) const
{
	if(p == NULL)
		return 0;
	else if(p->llink == NULL && p->rlink == NULL)
		return 1;
	else
		return (leavesCount(p->llink) + leavesCount(p->rlink));
	
		
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal
			                  (void (*visit) (elemType& item)) const
{ 
	inorder(root, *visit);
}

template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType>* p,
							   void (*visit) (elemType& item)) const
{
	if (p != NULL)
	{
		inorder(p->llink, *visit);
		(*visit)(p->info);
		inorder(p->rlink, *visit);
	}
}

template <class elemType>
bool binaryTreeType<elemType>::search(const elemType& searchItem)
{
	return searchRec(searchItem, root);
}

template <class elemType>
bool binaryTreeType<elemType>::searchRec(const elemType& searchItem, nodeType<elemType> *p)
{

    if (root == NULL)
        cout << "Cannot search an empty tree." << endl;
    else
    { 
		
		if(searchItem == p->info)
		{
			return true;
		}
		else if(searchItem < p->info)
		{
			if(p->llink == NULL)
				return false;
			else
				return (searchRec(searchItem, p->llink));
		}
		else if(searchItem > p->info)
		{
			if(p->rlink == NULL)
				return false;
			else
				return (searchRec(searchItem, p->rlink));
		}
		
		return false;
		
	}
}

template <class elemType>
int binaryTreeType<elemType>::oneChildCount() const
{
	return oneChildCountRec(root);
}

template <class elemType>
int binaryTreeType<elemType>::oneChildCountRec(nodeType<elemType> *p) const
{
	if(p==NULL)
		return 0;
	else if((p->llink != NULL && p->rlink == NULL) || (p->rlink != NULL && p->llink == NULL))
		return 1 + (oneChildCountRec(p->llink) + oneChildCountRec(p->rlink));
	else
		return (oneChildCountRec(p->llink) + oneChildCountRec(p->rlink));
}

template <class elemType>
int binaryTreeType<elemType>::twoChildrenCount() const
{
	return twoChildrenCountRec(root);
}

template <class elemType>
int binaryTreeType<elemType>::twoChildrenCountRec(nodeType<elemType> *p) const
{
	if(p==NULL)
		return 0;
	else if(p->llink != NULL && p->rlink != NULL)
		return 1 + (twoChildrenCountRec(p->llink) + twoChildrenCountRec(p->rlink));
	else
		return (twoChildrenCountRec(p->llink) + twoChildrenCountRec(p->rlink));
}

template <class elemType>
int binaryTreeType<elemType>::nonLeavesCount() const
{
	return nonLeavesCountRec(root);
}

template <class elemType>
int binaryTreeType<elemType>::nonLeavesCountRec(nodeType<elemType> *p) const
{
	if(p==NULL)
		return 0;
	else if(p->llink != NULL || p->rlink != NULL)
		return 1 + (nonLeavesCountRec(p->llink) + nonLeavesCountRec(p->rlink));
	else
		return (nonLeavesCountRec(p->llink) + nonLeavesCountRec(p->rlink));
}


template <class elemType>
void binaryTreeType<elemType>::breadthFirstTraversal(void (*visit) (elemType&)) const
{

	for(int i=0; i<height(root)+1; i++)
	{
	  breadthFirstTraversalRec(root, i, *visit);
	}
}

template <class elemType>
void binaryTreeType<elemType>::breadthFirstTraversalRec(nodeType<elemType> *p, int num, void (*visit) (elemType&)) const
{
  
	if(p==NULL)
	  return;
	else if(num == 1)
	  visit(p->info);
	else
	{
	  breadthFirstTraversalRec(p->llink, num-1, *visit);
	  breadthFirstTraversalRec(p->rlink, num-1, *visit);	  
	}


}


template <class elemType>
bool binaryTreeType<elemType>::balanced() const
{
	return balancedRec(root);
}

template <class elemType>
bool binaryTreeType<elemType>::balancedRec(nodeType<elemType> *p) const
{
  int left;
  int right;
  
      if(p == NULL)
	return true;
      else
      {
      	left = height(p->llink);
	right = height(p->rlink);
      }
      
      	if(abs(left - right) <= 1 && balancedRec(p->llink) && balancedRec(p->rlink))
		return true;
	else
		return false;
}

template <class elemType>
void binaryTreeType<elemType>::path(const elemType& item) const
{
   stack<elemType> stacker;
  
   pathRec(item, root, stacker);
    
   cout << endl;
}

template <class elemType>
void binaryTreeType<elemType>::pathRec(const elemType& item, nodeType<elemType> *p, stack<elemType>& stacker) const
{
  
    if (p == NULL)
        cout << "Cannot path an empty tree." << endl;
    else
    { 
		
		if(item == p->info)
		{
			cout << p->info << ' ';
			while(!(stacker.empty()))
			{
			  cout << stacker.top() <<' ';
			  stacker.pop();
			}
		}
		else if(item < p->info)
		{
			if(p->llink != NULL)
			  stacker.push(p->info);
			  pathRec(item, p->llink, stacker);
		}
		else if(item > p->info)
		{
			if(p->rlink != NULL)
			  stacker.push(p->info);
			  pathRec(item, p->rlink, stacker);
		}
		
	}
    
}

template <class elemType>
bool binaryTreeType<elemType>::siblings(const elemType& item1, const elemType& item2) const
{
    siblingsRec(item1, item2, root);
}

template <class elemType>
bool binaryTreeType<elemType>::siblingsRec(const elemType& item1, const elemType& item2, nodeType<elemType> *p) const
{
      nodeType<elemType> *left = p;
      nodeType<elemType> *right = p;

      if(p->llink != NULL)
      nodeType<elemType> *left = p->llink;
      if(p->rlink != NULL)
      nodeType<elemType> *right = p->rlink; 
    
    if(p == NULL)
	return false;
     else
     {
	if(left->info == item1 || left->info == item2)
	{
	  if(right->info == item2 || right->info == item1)
	    return true;
	  else
	    return false;
	}
	else if(right->info == item1 || right->info == item2)
	{
	    if(left->info == item2 || left->info == item1)
	      return true;
	    else
	      return false;
	}
	else
	{
	
	  if(p->llink != NULL)
	    siblingsRec(item1, item2, p->llink);

	  if(p->rlink != NULL)
	    siblingsRec(item1, item2, p->rlink);

	}
    }
    
}
  
template <class elemType>
bool binaryTreeType<elemType>::full() const
{
  
    if(root == NULL)
    {
      return false;
    }
    else if(root != NULL && root->llink == NULL && root->rlink ==NULL)
    {
      return true;
    }
    else if(oneChildCount()>=1)
    {
      return false;
    }
    else if(leavesCount(root)%2  == 1)
    {
      return false;
    }
    else
    {
      return true;
    }
}

#endif

