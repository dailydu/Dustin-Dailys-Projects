// File:     graph.cpp
// Author:   Dustin Daily

// Description
// This file defines the class and methods for Graph class

#ifndef H_GRAPH
#define H_GRAPH

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

namespace GraphNameSpace
{
	
	enum formatType {WEIGHTED, DIRECTED, UNWEIGHTED, UNDIRECTED};
	
	template <class T>
	class Graph
	{
		public:
      // method - constructor
      // description - construct a new graph object
      // preconditions - none
      // postconditions - graph object created and initialized 
      // method input - none
      // method output - none
		Graph();
		
      // method - constructor (formatType)
      // description - construct a new graph object
      // preconditions - none
      // postconditions - graph object created and initialized 
      // method input - ENUM formatType
      // method output - none
		Graph(formatType);
		
      // method - constructor (formatType, formatType)
      // description - construct a new graph object
      // preconditions - none
      // postconditions - graph object created and initialized 
      // method input - 2 formatTypes
      // method output - none
		Graph(formatType, formatType);
		
      // method - destroy
      // description - destroy all edges and vertices
      // preconditions - vector has elements
      // postconditions - none
      // method input - none
      // method output - none
		void destroy();
		
      // method - isEmpty
      // description - checks if the vector is empty
      // preconditions - vector is created
      // postconditions - none
      // method input - none
      // method output - none
		bool isEmpty();
		
      // method - isFull
      // description - checks if the vector is full
      // preconditions - vecor is created
      // postconditions - none
      // method input - none
      // method output - none
		bool isFull();
		
      // method - isAdjacentTo (Vector element, Vector element)
      // description - checks if two elements in a Vector are connected by an edge
      // preconditions - vector is created
      // postconditions - none
      // method input - two vector elements
      // method output - true or false
		bool isAdjacentTo(T, T);
		
      // method - edgeWeight (Vector element, Vector element)
      // description - returns the weight of an edges connecting two vector elements
      // preconditions - vector is created, edge is exsisting
      // postconditions - none
      // method input - two vector elements
      // method output - integer
		int edgeWeight(T, T) throw (runtime_error);
		
      // method - edgeCount
      // description - sorts through the array and returns the number of edges
      // preconditions - vector is created and edges are in the array
      // postconditions - none
      // method input - none
      // method output - integer
		int edgeCount();
		
      // method - vertexCount
      // description - returns vertexCounter
      // preconditions - vector is created
      // postconditions - none
      // method input - none
      // method output - integer
		int vertexCount() const;
		
      // method - insertVertex(Vector element)
      // description - inserts a Vertex into the vector
      // preconditions - vector is created and is not already in the vector
      // postconditions - none
      // method input - Vector element
      // method output - none
		void insertVertex(T) throw (runtime_error);
		
      // method - insertEdge (Vector element, Vector element, int weight)
      // description - inserts an edge between two Vectors  
      // preconditions - vector is created and there are at least two vectors
      // postconditions - none
      // method input - two vector elements and an optional weight value
      // method output - none
		void insertEdge(T, T, int weight) throw (runtime_error);
		
      // method - deleteEdge (Vector element, Vector element)
      // description - deletes the edge between two vector elements
      // preconditions - vector is created and edge is exsisting
      // postconditions - none
      // method input - two vector elements
      // method output - none
		void deleteEdge(T, T) throw (runtime_error);
		
      // method - deleteVertex (Vector element)
      // description - deletes the vertex if it exsists
      // preconditions - vector is created
      // postconditions - none
      // method input - vector element
      // method output - none
		void deleteVertex(T) throw (runtime_error);
		
      // method - findVertex (Vector element)
      // description - finds the location of an vertex element in the vector
      // preconditions - vector is created
      // postconditions - none
      // method input - vector element
      // method output - integer
		int findVertex(T);
		
      // method - dump
      // description - displays the Graph objects information
      // preconditions - object has been created
      // postconditions - none
      // method input - two vector elements
      // method output - table
		void dump();
		
		
		private:
		
		vector<T> vertex;
		int array[100][100];
		
		int vertexCounter;
		int edgeCounter;
		
		bool weighted;//false is UNWEIGHTED
		bool directed;//false is UNDIRECTED
		
		
	};
	
	
template <class T>
Graph<T>::Graph()
{
	weighted = false;
	directed = false;
	
	vertexCounter = 0;
	edgeCounter = 0;
	
	vector<T> vertex(0);
	
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<100; j++)
		{
			array[i][j]=-1;
		}
	}	
}

template <class T>
Graph<T>::Graph(formatType format)
{
	weighted = false;
	directed = false;
	
	vertexCounter = 0;
	edgeCounter = 0;
	
	vector<T> vertex(0);
	
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<100; j++)
		{
			array[i][j]=-1;
		}
	}

	if(format == DIRECTED)
	{
		directed = true;
	}
	if(format == WEIGHTED)
	{
		weighted = true;
	}
}
	
template <class T>
Graph<T>::Graph(formatType format1, formatType format2)
{
	weighted = false;
	directed = false;
	
	vertexCounter = 0;
	edgeCounter = 0;
	
	vector<T> vertex(0);
	
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<100; j++)
		{
			array[i][j]=-1;
		}
	}

	if(format1 == DIRECTED)
	{
		directed = true;

	}
	if(format1 == WEIGHTED)
	{
		weighted = true;

	}
	if(format2 == DIRECTED)
	{
		directed = true;
	
	}
	if(format2 == WEIGHTED)
	{
		weighted = true;
	
	}
}	

template <class T>
void Graph<T>::destroy()
{
	
	//vertex.erase(vertex.begin(), vertex.begin()+vertexCounter);
	
	while((!isEmpty()))
	{
		deleteVertex(vertex.at(vertexCounter-1));
	}

}
	
template <class T>
bool Graph<T>::isEmpty()
{
	if(vertex.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Graph<T>::isFull()
{
	if(vertex.size() == 100)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Graph<T>::isAdjacentTo(T here, T toHere)
{

	if(array[findVertex(here)][findVertex(toHere)] > -1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
/*
	if(directed == true)
	{
		if(array[findVertex(here)][findVertex(toHere)] > -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(directed == false)
	{
		
		if(array[findVertex(here)][findVertex(toHere)] > -1 || 
		array[findVertex(toHere)][findVertex(here)] > -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
*/
	
}

template <class T>
int Graph<T>::edgeWeight(T here, T toHere) throw(runtime_error)
{
	
	
	if((!isEmpty()) && vertexCounter >= 2)//not enough in vertex
	{
		if(findVertex(here) != -1 && findVertex(toHere) != -1)//they do not exsist
		{
			if(findVertex(here) != findVertex(toHere))//they are the same
			{

				return array[findVertex(here)][findVertex(toHere)];				
			}
			else
			{
				throw(runtime_error ("These are the same vertices!\n"));
			}
		}
		else
		{
			throw(runtime_error ("One or both vertices do not exsist!\n"));
		}
	}
	else
	{
		throw(runtime_error ("There is not enough vertices!\n"));
	}
}

template <class T>
int Graph<T>::edgeCount()
{
	edgeCounter = 0;
	
		for(int i=0; i<vertexCounter; i++)
		{
			for(int j=0; j<vertexCounter; j++)
			{
				if(array[i][j] > -1)
				{
					edgeCounter++;
				}
			}
		}

	
	return edgeCounter;
}

template <class T>
int Graph<T>::vertexCount()const
{
	return vertexCounter;
}

template <class T>
void Graph<T>::insertVertex(T here) throw (runtime_error)
{
	if(findVertex(here) == -1)//does not exsist
	{
		if((!isFull()))
		{
			vertex.push_back(here);
			vertexCounter++;
		}
		else
		{
			throw(runtime_error ("No more vertices allowed, limit reached!\n"));
		}
	}
	else
	{
		throw(runtime_error ("Vertex does already exsist!\n"));
	}
}

template <class T>
void Graph<T>::insertEdge(T here, T toHere, int weight = 1) throw (runtime_error)
{

	if((!isEmpty()) && vertexCounter >= 2)//not enough in vertex
	{
		if(findVertex(here) != -1 && findVertex(toHere) != -1)//they do not exsist
		{
			if(findVertex(here) != findVertex(toHere))//they are the same
			{
				if(weighted == true)
				{
					if(directed == true)
					{
						array[findVertex(here)][findVertex(toHere)] = weight;
					}
					if(directed == false)
					{
						array[findVertex(here)][findVertex(toHere)] = weight;
						array[findVertex(toHere)][findVertex(here)] = weight;
					}	
				}
				if(weighted == false)
				{
					if(directed == true)
					{
						array[findVertex(here)][findVertex(toHere)] = 1;
					}
					if(directed == false)
					{
						array[findVertex(here)][findVertex(toHere)] = 1;
						array[findVertex(toHere)][findVertex(here)] = 1;
					}					
				}
			}
			else
			{
				throw(runtime_error ("These are the same vertices!\n"));
			}
		}
		else
		{
			throw(runtime_error ("One or both vertices do not exsist!\n"));
		}
	}
	else
	{
		throw(runtime_error ("There is not enough vertices!\n"));
	}	

}

template <class T>
void Graph<T>::deleteVertex(T here) throw (runtime_error)
{
	if((!isEmpty()))
	{
		if(findVertex(here) != -1)
		{
			if(directed == false)
			{
				for(int i=0; i<vertexCounter; i++)
				{
					array[findVertex(here)][i] = -1;
					array[i][findVertex(here)] = -1;
				}
			}
			if(directed == true)
			{
				for(int i=0; i<vertexCounter; i++)
				{
					array[findVertex(here)][i] = -1;
					array[i][findVertex(here)] = -1;
				}
			}
			
			for(int i=findVertex(here); i<vertexCounter; i++)
			{
				for(int j=findVertex(here); j<vertexCounter; j++)
				{
					if(directed == true)
					{
						array[j][i] = array[j+1][i+1];
					}
					if(directed == false)
					{
						array[j][i] = array[j+1][i+1];					
					}

				}
			}

			vertex.erase(vertex.begin()+findVertex(here));
			vertexCounter--;
		}
		else
		{
			throw(runtime_error ("Vertex does not exsist!\n"));
		}
	}
	else
	{
		throw(runtime_error ("Vertex is empty!\n"));
	}
}

template <class T>
void Graph<T>::deleteEdge(T here, T toHere) throw (runtime_error)
{
	if((!isEmpty()) && vertexCounter >= 2)//not enough in vertex
	{
		if(findVertex(here) != -1 && findVertex(toHere) != -1)//they do not exsist
		{
			if(findVertex(here) != findVertex(toHere))//they are the same
			{
				if(isAdjacentTo(here, toHere) == true)//edge does exsist
				{
					if(weighted == true)
					{
						if(directed == true)
						{
							array[findVertex(here)][findVertex(toHere)] = -1;
						}
						if(directed == false)
						{
							array[findVertex(here)][findVertex(toHere)] = -1;
							array[findVertex(toHere)][findVertex(here)] = -1;
						}	
					}
					if(weighted == false)
					{
						if(directed == true)
						{
							array[findVertex(here)][findVertex(toHere)] = -1;
						}
						if(directed == false)
						{
							array[findVertex(here)][findVertex(toHere)] = -1;
							array[findVertex(toHere)][findVertex(here)] = -1;
						}					
					}			
				}
				else
				{
					throw(runtime_error ("The edge does not exsist!\n"));
				}
			}
			else
			{
				throw(runtime_error ("These are the same vertices!\n"));
			}
		}
		else
		{
			throw(runtime_error ("One or both vertices do not exsist!\n"));
		}
	}
	else
	{
		throw(runtime_error ("There is not enough vertices!\n"));
	}	
}

template <class T>
int Graph<T>::findVertex(T here)
{
	for(int i=0; i<vertexCounter; i++)
	{
		if(here == vertex.at(i))
		{
			return i;
		}
	}
	return -1;
}
	
template <class T>
void Graph<T>::dump()
{
	cout<<"Dumping Graph:  ";
	
	if(directed == true)
	{
		cout << "DIRECTED  ";
	}
	else
	{
		cout << "UNDIRECTED  ";
	}
	if(weighted == true)
	{
		cout << "WEIGHTED  ";
	}
	else
	{
		cout << "UNWEIGHTED  ";
	}
	
	cout << "Vertices: " << vertexCounter << "  ";
	cout << "Edges: " << edgeCount() << endl;

	cout << "VERTEX" << '\t' << '\t' << '\t' << "ADJACENT VERTICES" << endl;
	
	cout << "----------------" << '\t' << "-------------------------------------------" << endl;
	
	for(int i=0; i<vertexCounter; i++)
	{
		cout << "[" << i << "]" << '\t' << vertex.at(i) << '\t' << '\t';
		
		for(int j=0; j<vertexCounter; j++)
		{
			if(isAdjacentTo(vertex.at(i),vertex.at(j)) == true)
			{
				cout << "[" << j << "]" << vertex.at(j) << "   ";
			}	
		}
		cout << endl;
	}
}
	
	
}//end of namespace

#endif