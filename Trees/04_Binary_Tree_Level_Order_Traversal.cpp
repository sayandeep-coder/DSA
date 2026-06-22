/*
=========================================================
Problem: Binary Tree Level Order Traversal
Difficulty: Medium
Pattern: Tree / BFS
LeetCode: #102

Problem Statement:
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example:

Input:
root = [3,9,20,null,null,15,7]

Output:
[[3],[9,20],[15,7]]

Explanation:
Intuition: To traverse a tree level by level, we need to visit all nodes at depth D before visiting any nodes at depth D+1. Breadth-First Search (BFS) is the standard algorithm for this.
Approach: Use a Queue to perform BFS. Initially, push the root into the queue. Then, run a loop while the queue is not empty. Inside the loop, determine the number of elements currently in the queue (`levelSize`). This represents all nodes at the current level. Process all `levelSize` nodes: pop them, add their values to a temporary level list, and push their non-null children into the queue. After the inner loop, add the level list to the final result.
Why it works: A queue operates First-In-First-Out (FIFO). By processing elements in the order they were discovered (level by level) and explicitly counting elements per level, we easily segregate the output list.
Complexity Analysis:

Time Complexity: O(N) where N is the number of nodes in the tree. Every node is enqueued and dequeued exactly once.
Space Complexity: O(N) to hold nodes in the queue. In the worst case (a perfectly balanced tree), the last level will have N/2 nodes, taking O(N) space.
=========================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    // Detailed explanation comments
    // Use a queue to track nodes. Process them level by level by taking the size
    // of the queue at the start of each level's processing loop.
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            // Process all nodes in the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                currentLevel.push_back(node->val);
                
                // Add children to queue for the next level
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            
            result.push_back(currentLevel);
        }
        
        return result;
    }
};

int main() {

    // Sample test case
    Solution obj;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    // Execute solution
    vector<vector<int>> result = obj.levelOrder(root);
    
    cout << "Level Order Traversal:" << endl;
    cout << "[" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "  [";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << (j < result[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < result.size() - 1 ? "," : "") << endl;
    }
    cout << "]" << endl;

    return 0;
}
