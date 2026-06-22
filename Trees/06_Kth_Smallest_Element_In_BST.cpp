/*
=========================================================
Problem: Kth Smallest Element in a BST
Difficulty: Medium
Pattern: Tree / Inorder Traversal
LeetCode: #230

Problem Statement:
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example:

Input:
root = [3,1,4,null,2], k = 1

Output:
1

Explanation:
Intuition: The key property of a Binary Search Tree (BST) is that an in-order traversal (left-root-right) visits the nodes in strictly ascending sorted order.
Approach: We can perform an in-order traversal. As we visit each node (after exploring its left subtree), we increment a counter. When the counter reaches `k`, we have found our answer. We can store the answer and stop the traversal early to optimize.
Why it works: Because in-order traversal visits smaller elements before larger elements, the kth element visited is guaranteed to be the kth smallest element in the entire BST.
Complexity Analysis:

Time Complexity: O(H + k) where H is the height of the tree. We go down to the leftmost leaf (O(H)), and then traverse `k` nodes. In the worst case (skewed tree), this could be O(N).
Space Complexity: O(H) for the recursion stack. Worst case O(N), average O(log N).
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
private:
    int count = 0;
    int result = -1;

    void inorder(TreeNode* node, int k) {
        if (node == nullptr) return;

        // Traverse left subtree
        inorder(node->left, k);

        // Process current node
        count++;
        if (count == k) {
            result = node->val;
            return; // Found the answer, can stop traversing deeper
        }

        // If we haven't found it yet, traverse right subtree
        if (count < k) {
            inorder(node->right, k);
        }
    }

public:
    // Detailed explanation comments
    // In-order traversal processes nodes in sorted order.
    // Count nodes as they are processed and stop when count reaches k.
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        inorder(root, k);
        return result;
    }
};

int main() {

    // Sample test case
    Solution obj;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int k = 1;

    // Execute solution
    int result = obj.kthSmallest(root, k);
    
    cout << "Kth Smallest Element: " << result << endl;

    // Memory cleanup omitted for brevity

    return 0;
}
