#include <vector>
#include "node.h"

class Graph{
	std::vector<Node> nodes;

	private:
	
		std::vector<Node> getIndepentNodes();
	public:
		int addNode(Node);
		void printNodes();
		void topologicalSort();
};
