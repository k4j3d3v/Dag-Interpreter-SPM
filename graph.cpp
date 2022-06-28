#include "graph.h"
#include "node.h"
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include <algorithm> 

int Graph::addNode(Node node)
{
	nodes.push_back(node);
	std::cout<<"Node added, id: "<<node.id<<std::endl;

	return 0;
}
void Graph::topologicalSort()
{

	// L will contain ordered nodes
	std::vector<Node> L(nodes.size());
	// S a support "queue"
	std::vector<Node> S = Graph::getIndepentNodes();

	// std::cout<<"Independent nodes: \n \t ";
	// for (Node i_n : S) {
	// 	std::cout<<"Node: "<<i_n.id<<std::endl;
	// }
	
	while (!S.empty()) {
		Node n =  S.back();
		//std::cout<<"extracted n: "<<n.id<<std::endl;
		S.pop_back();
		
		/*std::cout<<"S after pop_back: \n  ";
		for (Node i_n : S) {
			std::cout<<"\t Node: "<<i_n.id<<std::endl;
		}*/
		L.push_back(n);
		std::vector<std::reference_wrapper<Node>> nodes_ref;
		// n->m edges: nodes m that depends from n aka that have n in dependeces
		std::transform(nodes.begin(), nodes.end(),
						std::back_inserter(nodes_ref),
						[](auto &x){return std::ref<Node>(x);}
			);
		std::vector<std::reference_wrapper<Node>> n_adj;

		std::copy_if (nodes_ref.begin(), nodes_ref.end(), std::back_inserter(n_adj), 
		[&n](std::reference_wrapper<Node> i)
		{	
			std::vector<Node> v = i.get().dependence;
			return std::find(v.begin(), v.end(),n)!=v.end();

		});

		// std::cout<<"Scanning n_adj"<<std::endl;
		for (Node &m : n_adj) {

			int m_pos = std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(),m));
			Node m_ref = nodes.at(m_pos);
			m.dependence.erase(std::remove(m.dependence.begin(), m.dependence.end(), n), m.dependence.end());
			
		
			if(m.dependence.empty())
					S.push_back(m);
		}
	}
	std::cout<<"Remaining edges analysis \n";
	bool remaining_edges = false;
	for(Node n : nodes)
	{
		std::cout<<"n: "<<n.id<<" remaining dependences: \n";
		for (Node d_n : n.dependence) {
				std::cout<<"\t "<<d_n.id<<std::endl;
			}

		if(!n.dependence.empty())
			remaining_edges=true;
	}
	if(remaining_edges)
		std::cout<<"Error: exist a cycle!";
	else
		for(Node node : L)
			std::cout<<node.id<<" ";

}
std::vector<Node> Graph::getIndepentNodes()
{
	std::cout<<"kitemmu"<<std::endl;
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
