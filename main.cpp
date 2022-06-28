#include "node.h"
#include "graph.h"
#include <iostream>
using namespace std;
int main()
{
	Node A(1,1,2); Node B(2,1,1);
	//Node C(3,1,1); 
	Node D(4,2,1);
	//A.addDependant(B); A.addDependant(C); B.addDependant(D); C.addDependant(D);
	B.addDependence(A); //C.addDependence(A); 
	D.addDependence(B);// D.addDependence(C);
	Graph g;
	//g.addNode(C);
	g.addNode(A); g.addNode(B);  g.addNode(D);
	g.topologicalSort();
	return 0;
}

