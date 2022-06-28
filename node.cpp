#include "node.h"
#include <iostream>

Node::Node()
{
	Node(-1, 0, 0);

}
Node::Node(int id, int in_a, int out_a)
{
	Node::id = id;
	input_arity = in_a;
	out_arity = out_a;
	std::cout<<"Node created, id: "<<Node::id<<std::endl;

}
int Node::addDependence(Node dp)
{
	std::cout<<"addDep method"<<std::endl;
	Node::dependence.push_back(dp);
	return 0;
}
bool operator==(const Node& lhs, const Node& rhs)
{ 
	return lhs.id==rhs.id;
}

/*
std::ostream& operator<< (std::ostream& out, const Node& node)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Node(id=" << node.id<< ", in_a" << node.input_arity  << ", out_a" << node.output_arity << ')';

    return out;
}

*/
