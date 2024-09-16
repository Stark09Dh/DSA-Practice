#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Tree {
public:
    Tree(int n, const vector<vector<int>>& edges) {
        adjList.resize(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    int countGoodNodes() {
        vector<int> subtreeSize(adjList.size(), 0);
        unordered_map<int, vector<int>> childMap;
        
        // Compute subtree sizes and child relationships
        dfs(0, -1, subtreeSize, childMap);
        
        int goodNodeCount = 0;
        // Check each node if it is a good node
        for (int node = 0; node < adjList.size(); ++node) {
            if (isGoodNode(node, childMap, subtreeSize)) {
                ++goodNodeCount;
            }
        }
        
        return goodNodeCount;
    }

private:
    vector<vector<int>> adjList;

    int dfs(int node, int parent, vector<int>& subtreeSize, unordered_map<int, vector<int>>& childMap) {
        int size = 1; // The size of the subtree rooted at `node`, including itself
        for (int neighbor : adjList[node]) {
            if (neighbor == parent) continue; // Skip the parent node
            int childSize = dfs(neighbor, node, subtreeSize, childMap);
            size += childSize;
            childMap[node].push_back(neighbor);
        }
        subtreeSize[node] = size;
        return size;
    }

    bool isGoodNode(int node, const unordered_map<int, vector<int>>& childMap, const vector<int>& subtreeSize) {
        if (childMap.find(node) == childMap.end() || childMap.at(node).empty()) {
            return true; // Leaf nodes or nodes with no children are always good
        }
        
        int expectedSize = subtreeSize.at(childMap.at(node)[0]);
        for (int child : childMap.at(node)) {
            if (subtreeSize.at(child) != expectedSize) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n = 9;
    vector<vector<int>> edges = {
        {0,1},{1,2},{2,3},{3,4},{0,5},{1,6},{2,7},{3,8}
    };
    
    Tree tree(n, edges);
    cout << "Number of good nodes: " << tree.countGoodNodes() << endl;
    
    return 0;
}
