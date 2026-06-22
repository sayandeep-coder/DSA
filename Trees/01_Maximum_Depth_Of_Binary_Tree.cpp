/*
=========================================================
Problem: Maximum Depth of Binary Tree
Difficulty: Easy
Pattern: Tree / DFS
LeetCode: #104

Problem Statement:
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example:

Input:
root = [3,9,20,null,null,15,7]

Output:
3

Explanation:
Intuition: The maximum depth of a tree is 1 (for the root itself) plus the maximum depth of its left or right subtrees. This naturally lends itself to a recursive approach.
Approach: Use Depth-First Search (DFS) recursively. If the node is NULL, the depth is 0. Otherwise, recursively find the maximum depth of the left child and the right child. The depth of the current node will be `1 + max(left_depth, right_depth)`.
Why it works: By recursively breaking down the tree into smaller subtrees, we compute the maximum depth from the bottom up, accumulating the height along the longest path.
Complexity Analysis:

Time Complexity: O(N) where N is the number of nodes in the tree. We visit each node exactly once.
Space Complexity: O(H) where H is the height of the tree, representing the maximum depth of the recursion stack. In the worst case (a skewed tree), this is O(N). In a balanced tree, it is O(log N).
=========================================================
*/

#include <iostream>
#include <algorithm>
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
    // Recursively find the max depth of left and right subtrees.
    // The depth is 1 + max of both subtrees.
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return 1 + max(leftDepth, rightDepth);
    }
};

int main() {

    // Sample test case: [3,9,20,null,null,15,7]
    Solution obj;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Execute solution
    int depth = obj.maxDepth(root);
    
    cout << "Maximum Depth: " << depth << endl;

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
