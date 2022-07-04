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
	for (auto i : nodeCluster)
	{
		if (std::find(i.key.begin(), i.key.end(), key) != i.key.end()) return i.id;
	}

	int randomNode = rand() % nodeCluster.size();
	nodeCluster[randomNode].key.push_back(key);
	return nodeCluster[randomNode].id;
}

int ConsistentHashing::removeNode(int node)
{
	return 0;
}

std::vector<int> ConsistentHashing::addNode()
{
	std::vector<int> result;
	int randomNode = rand() % nodeCluster.size();
	Node node{ nodeCluster.size() + 1, nodeCluster[randomNode].key };
	nodeCluster.push_back(node);
	result.push_back(nodeCluster.size() + 1);
	result.push_back(randomNode);
	return result;
}

std::vector<int> ConsistentHashing::getKeysInNode(int node)
{
	return std::vector<int>();
}
