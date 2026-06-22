/*
=========================================================
Problem: Lowest Common Ancestor of a Binary Search Tree
Difficulty: Medium
Pattern: Tree / BST Property
LeetCode: #235

Problem Statement:
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes p and q in the BST.
The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).

Example:

Input:
root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8

Output:
6

Explanation:
Intuition: In a BST, all nodes in the left subtree are smaller than the root, and all nodes in the right subtree are larger. If both `p` and `q` are smaller than the current node, their LCA must be in the left subtree. If they are both larger, it must be in the right subtree. If they split (one is smaller, one is larger, or one is equal to the current node), then the current node is the Lowest Common Ancestor.
Approach: Start at the root. If both `p->val` and `q->val` are less than `root->val`, move to the left child. If they are both greater, move to the right child. Repeat this process until you find a node where the values split (or one value equals the node's value). That node is the LCA. This can be done iteratively or recursively.
Why it works: The split point is guaranteed to be the LCA because taking any step further down would mean excluding one of the target nodes from the ancestor's subtree.
Complexity Analysis:

Time Complexity: O(H) where H is the height of the tree. In the worst case, we traverse from the root to a leaf. Worst case O(N), average O(log N).
Space Complexity: O(1) if implemented iteratively (as shown below), or O(H) if implemented recursively due to the call stack.
=========================================================
*/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    // Detailed explanation comments
    // Use BST property: if both values are less than current, LCA is left.
    // If both are greater, LCA is right. Else, current is LCA.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* current = root;
        
        while (current != nullptr) {
            // Both p and q are greater than parent
            if (p->val > current->val && q->val > current->val) {
                current = current->right;
            } 
            // Both p and q are smaller than parent
            else if (p->val < current->val && q->val < current->val) {
                current = current->left;
            } 
            // We have found the split point, i.e. the LCA node.
            else {
                return current;
            }
        }
        return nullptr;
    }
};

int main() {

    // Sample test case
    Solution obj;
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    TreeNode* p = root->left;   // Node with value 2
    TreeNode* q = root->right;  // Node with value 8

    // Execute solution
    TreeNode* lca = obj.lowestCommonAncestor(root, p, q);
    
    if (lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    }

    // Memory cleanup omitted for brevity

    return 0;
}
