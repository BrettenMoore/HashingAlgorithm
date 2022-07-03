#include "ConsistentHashing.h"

ConsistentHashing::ConsistentHashing(int initialNodes)
{
	for (int i = 0; i <= initialNodes; i++)
	{
		Node node{i};
		nodeCluster.push_back(node);
	}
}

int ConsistentHashing::getNodeForKey(int key)
{
	return 0;
}

int ConsistentHashing::removeNode(int node)
{
	return 0;
}

std::vector<int> ConsistentHashing::addNode()
{
	return std::vector<int>();
}

std::vector<int> ConsistentHashing::getKeysInNode(int node)
{
	return std::vector<int>();
}
