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
	
	int randomNode = rand() % nodeCluster.size();
	for (auto& i : nodeCluster[node].key)
	{
		nodeCluster[randomNode].key.push_back(i);
	}
	nodeCluster.erase(nodeCluster.begin() + node);

	return randomNode;
}

std::vector<int> ConsistentHashing::addNode()
{
	std::vector<int> result;
	int randomNode = rand() % nodeCluster.size();
	Node node{ nodeCluster.size(), nodeCluster[randomNode].key };
	nodeCluster.push_back(node);
	result.push_back(nodeCluster.size());
	result.push_back(randomNode);
	return result;
}

std::vector<int> ConsistentHashing::getKeysInNode(int node)
{
	std::vector<int> result;
	for (auto& i : nodeCluster[node].key)
	{
		result.push_back(i);
	}
	return result;
}
