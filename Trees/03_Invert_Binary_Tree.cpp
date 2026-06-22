/*
=========================================================
Problem: Invert Binary Tree
Difficulty: Easy
Pattern: Tree / DFS
LeetCode: #226

Problem Statement:
Given the root of a binary tree, invert the tree, and return its root.

Example:

Input:
root = [4,2,7,1,3,6,9]

Output:
[4,7,2,9,6,3,1]

Explanation:
Intuition: Inverting a binary tree means swapping every node's left child with its right child. We can accomplish this by visiting every node and performing the swap.
Approach: We can use a recursive Depth-First Search (DFS) approach. For a given node, if it is NULL, simply return NULL. Otherwise, swap its `left` and `right` child pointers. Then recursively call the invert function on both its left and right children so that the entire subtree is inverted. Return the root.
Why it works: By recursively swapping children at every single node in the tree, the structure is completely mirrored. Doing it top-down ensures every level gets swapped appropriately.
Complexity Analysis:

Time Complexity: O(N) where N is the number of nodes in the tree. We must visit each node exactly once to swap its children.
Space Complexity: O(H) where H is the height of the tree due to the recursion stack. Worst case O(N), average O(log N).
=========================================================
*/

#include <iostream>
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
    // Swap the left and right pointers of the current node.
    // Recursively apply to all children.
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        // Swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Recursively invert subtrees
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

int main() {

    // Sample test case
    Solution obj;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));

    // Execute solution
    TreeNode* inverted = obj.invertTree(root);
    
    // Print root and its direct children to verify
    cout << "Inverted Root: " << inverted->val << endl;
    cout << "Left Child: " << (inverted->left ? to_string(inverted->left->val) : "null") << endl;
    cout << "Right Child: " << (inverted->right ? to_string(inverted->right->val) : "null") << endl;

    // Memory cleanup omitted for brevity

    return 0;
}
