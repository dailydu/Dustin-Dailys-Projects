#include <iostream>
using namespace std;
#include "graph.h"
using namespace GraphNameSpace;

class V
{
   public:
      V() {}  // constructor with no arguments
      V(const string& s) : value(s) {}  // constructor with argument
      string getValue() const {return value;}
      bool operator==(const V& v) const {return getValue()==v.getValue();}
      bool operator!=(const V& v) const {return getValue()!=v.getValue();}
      bool operator<(const V& v) const {return getValue()<v.getValue();}
      bool operator<=(const V& v) const {return getValue()<=v.getValue();}
      bool operator>(const V& v) const {return getValue()>v.getValue();}
      bool operator>=(const V& v) const {return getValue()>=v.getValue();}
   private:
      string value;
};

ostream& operator<<(ostream&out, const V& v)
{
   out << v.getValue();
   return out;
}


int main()
{
   Graph<char> Graph1;  // UNDIRECTED and UNWEIGHTED
   Graph<char> Graph2(WEIGHTED,DIRECTED);
   Graph<char> Graph3(DIRECTED,WEIGHTED);
   Graph<char> Graph4(DIRECTED);  // DIRECTED and UNWEIGHTED)
   Graph<char> Graph5(WEIGHTED);  // WEIGHTED and UNDIRECTED

 
   char A = 'A';
   char B = 'B'; 
   char C = 'C';
    char D = 'D';  
    char E = 'E';  
	

	
	Graph2.insertVertex(A); 
	Graph2.insertVertex(B);
	Graph2.insertVertex(C);
	Graph2.insertVertex(D);
	Graph2.insertVertex(E);
			 
	Graph2.insertEdge(A,B, 5);
	Graph2.insertEdge(B,C,29);
	Graph2.insertEdge(A,D, 5);
	Graph2.insertEdge(D,E,50);

	
	Graph2.dump();
	Graph2.deleteVertex(A);
	Graph2.dump();
	
	Graph3.insertVertex(A); 
	Graph3.insertVertex(B);
	Graph3.insertVertex(C);
	Graph3.insertVertex(D);
	Graph3.insertVertex(E);
			 
	Graph3.insertEdge(A,B, 5);
	Graph3.insertEdge(B,C,29);
	Graph3.insertEdge(A,D, 5);
	Graph3.insertEdge(D,E,50);
	Graph3.edgeWeight(B,C);
	cout<<endl<<endl;
	
	Graph3.dump();
	Graph3.deleteVertex(A);
	Graph3.dump();
	
	Graph4.insertVertex(A); 
	Graph4.insertVertex(B);
	Graph4.insertVertex(C);
	Graph4.insertVertex(D);
	Graph4.insertVertex(E);
			 
	Graph4.insertEdge(A,B, 5);
	Graph4.insertEdge(B,C,29);
	Graph4.insertEdge(A,D, 5);
	Graph4.insertEdge(D,E,50);

	
	Graph4.dump();
	Graph4.deleteVertex(A);
	Graph4.dump();
	cout << Graph4.edgeWeight(B,C);
	cout<<endl<<endl;
	Graph4.destroy();
	Graph4.dump();
	
	
	
	
   /*
   
   if (Graph3.isEmpty())
      cout << "empty\n";
   else
      cout << "not empty\n";
   Graph3.insertVertex(A);
   Graph3.insertVertex(B);
   Graph3.insertVertex(C);
   
   Graph3.insertEdge(A,B,5);
   Graph3.insertEdge(A,C,3);
   Graph3.insertEdge(B,C,4);
  Graph3.dump();
  
   
   if (Graph3.isEmpty())
      cout << "empty\n";
   else
      cout << "not empty\n";
   if (Graph3.isFull())
      cout << "full\n";
   else
      cout << "not full\n";
  
   if (Graph3.isAdjacentTo(A,C))
      cout << A << " is adjacent to " << C << " with edge weight "
           << Graph3.edgeWeight(A,C) << endl;
   else
      cout << A << " is not adjacent to " << C << endl;
   if (Graph3.isAdjacentTo(B,A))
      cout << B << " is adjacent to " << A << " with edge weight "
           << Graph3.edgeWeight(B,A) << endl;
   else
      cout << B << " is not adjacent to " << A << endl;
  
  
   cout << "Vertices: " << Graph3.vertexCount() << endl;
   cout << "Edges: " << Graph3.edgeCount() << endl;
   Graph3.dump();
   cout << endl;
   Graph3.deleteEdge(A,C);
   Graph3.dump();
      cout << endl;
   Graph3.deleteVertex(B);
   Graph3.dump();
      cout << endl;
   Graph3.destroy();
   Graph3.dump();
      cout << endl;

   Graph<V>  g;
   V V1("Vertex1");
   V V2("Vertex2");
   V V3("Vertex3");
   g.insertVertex(V1);
   g.insertVertex(V2);
   g.insertVertex(V3);
   g.insertEdge(V1,V2);
   g.insertEdge(V3,V1);
   g.insertEdge(V3,V2);
   g.dump();   
   g.destroy();
   g.dump();

   int index;
   index = g.findVertex(V2);
   if (index != -1)
      cout << "vertex " << V2 << " is found at index " << index << endl;
   else
      cout << "vertex " << V2 << " is not in the graph\n";
   g.deleteVertex(V2);
   index = g.findVertex(V2);
   if (index != -1)
      cout << "vertex " << V2 << " is found at index " << index << endl;
   else
      cout << "vertex " << V2 << " is not in the graph\n";
*/

   
   return 0;
}

