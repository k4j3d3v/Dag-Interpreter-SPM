#ifndef NODE_H_
#define NODE_H_
#include <ostream>
#include <vector>

class Node{
	int input_arity, out_arity;
	public:
		int id; 
		std::vector<Node> dependence;
		Node();
		Node(int,int,int);
		//int addDependant(Node);
		int addDependence(Node);
		friend std::ostream& operator<< (std::ostream& out, const Node& node);
		friend bool operator==(const Node& lhs, const Node& rhs)
		{ 
			return lhs.id==rhs.id;
		}

};
#endif //NODE_H_ 
