#include "graph.h"
#include "node.h"
#include <iostream>
#include <vector>
#include <algorithm> 

int Graph::addNode(Node node)
{
	nodes.push_back(node);
	return 0;
}
void Graph::topologicalSort()
{
	std::vector<Node> L(nodes.size());
	std::vector<Node> S = Graph::getIndepentNodes();
	while (!S.empty()) {
		Node n =  S.back();
		S.pop_back();
		L.push_back(n);
		std::vector<Node> n_adj;
		// n->m edges: nodes m that depends from n aka that have n in dependeces
		std::copy_if (nodes.begin(), nodes.end(), std::back_inserter(n_adj), 
		[&n](Node i)
		{	auto v = i.dependence;
			return std::find(v.begin(), v.end(),n)!=v.end();
		});
		for (Node m : n_adj) {
			//m.dependence.pop_back(n);
			m.dependence.erase(std::remove(m.dependence.begin(), m.dependence.end(), n), m.dependence.end());
			if(m.dependence.empty())
					S.push_back(m);
		}
	}
	bool remaining_edges = false;
	for(Node n : nodes)
		if(!n.dependence.empty())
			remaining_edges=true;
	
	if(remaining_edges)
		std::cout<<"Error: exist a cycle!";
	else
		for(Node node : L)
			std::cout<<node.id<<" ";






}
std::vector<Node> Graph::getIndepentNodes()
{
	std::vector<Node> v;
	for (auto n : nodes) {
		if(n.dependence.empty())	
			v.push_back(n);
	}
	return v;
}
/*
void Graph::printNodes()
{
	for (auto i: nodes)
		std::cout << i << ' ';
}
*/
