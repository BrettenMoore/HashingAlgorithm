#pragma once
#include<vector>
class ConsistentHashing
{
public:
    ConsistentHashing(int initialNodes);
    int getNodeForKey(int key);
    int removeNode(int node);
    std::vector<int> addNode();
    std::vector<int> getKeysInNode(int node);

private:
    struct Node {
        int id;
        std::vector<int> key;
    };
    
    std::vector<Node> nodeCluster;
};

