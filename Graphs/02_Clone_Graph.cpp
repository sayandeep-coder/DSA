/*
=========================================================
Problem: Clone Graph
Difficulty: Medium
Pattern: Graph / BFS / DFS
LeetCode: #133

Problem Statement:
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

Example:

Input:
adjList = [[2,4],[1,3],[2,4],[1,3]]

Output:
[[2,4],[1,3],[2,4],[1,3]]

Explanation:
Intuition: We need to traverse the entire graph and create a new node for every existing node. However, graphs can have cycles. If we are not careful, we might get stuck in an infinite loop or create multiple clones of the same node.
Approach: Use Depth-First Search (DFS) and a Hash Map. The Hash Map will map original nodes to their cloned counterparts (`unordered_map<Node*, Node*>`). When we visit a node, we first check if it's already in the map. If it is, we simply return the cloned node. If not, we create a new cloned node, add it to the map, and then recursively iterate through the original node's neighbors, appending the cloned neighbors to the new node's neighbor list.
Why it works: The Hash Map acts as a "visited" set that also gives us direct access to the cloned nodes. This ensures every node is cloned exactly once and all cyclic references are correctly established.
Complexity Analysis:

Time Complexity: O(V + E) where V is the number of vertices (nodes) and E is the number of edges. We visit each node and edge exactly once.
Space Complexity: O(V) for the Hash Map and the recursion stack.
=========================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> copies;

public:
    // Detailed explanation comments
    // Use DFS and a hash map to keep track of already cloned nodes.
    // Map maps OriginalNode -> ClonedNode.
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        // If the node is already cloned, return the clone
        if (copies.find(node) != copies.end()) {
            return copies[node];
        }
        
        // Create a clone for the current node and save it in the map
        Node* copy = new Node(node->val);
        copies[node] = copy;
        
        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return copy;
    }
};

int main() {

    // Sample test case
    Solution obj;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    // Execute solution
    Node* clonedGraph = obj.cloneGraph(node1);
    
    if (clonedGraph) {
        cout << "Cloned Graph Root Val: " << clonedGraph->val << endl;
        cout << "Neighbors of Cloned Root: ";
        for (Node* neighbor : clonedGraph->neighbors) {
            cout << neighbor->val << " ";
        }
        cout << endl;
    }

    return 0;
}
