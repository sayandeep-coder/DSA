/*
=========================================================
Problem: Validate Binary Search Tree
Difficulty: Medium
Pattern: Tree / DFS
LeetCode: #98

Problem Statement:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
1. The left subtree of a node contains only nodes with keys less than the node's key.
2. The right subtree of a node contains only nodes with keys greater than the node's key.
3. Both the left and right subtrees must also be binary search trees.

Example:

Input:
root = [2,1,3]

Output:
true

Explanation:
Intuition: A common mistake is just checking if a node's left child is smaller and right child is greater. This isn't enough; every node in the left subtree must be smaller than the root, and every node in the right subtree must be greater. We need to pass down boundaries (min and max limits) to each recursive call.
Approach: Use a recursive DFS function that takes a node and its valid range `(min_val, max_val)`. For the root, this range is `(-infinity, +infinity)`. For any node, check if its value falls within its assigned range. If not, return false. Then recursively validate its left child with range `(min_val, node->val)` and its right child with range `(node->val, max_val)`.
Why it works: By narrowing the valid range as we go down the tree, we strictly enforce that every node satisfies the BST property relative to all of its ancestors, not just its immediate parent. (Pointers are used for limits to easily represent infinity).
Complexity Analysis:

Time Complexity: O(N) where N is the number of nodes in the tree. We visit every node exactly once.
Space Complexity: O(H) where H is the height of the tree, representing the recursion stack. Worst case O(N), average O(log N).
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
    bool validate(TreeNode* node, long* lower, long* upper) {
        if (node == nullptr) {
            return true;
        }

        // The value must be strictly between the lower and upper bounds
        if ((lower != nullptr && node->val <= *lower) || 
            (upper != nullptr && node->val >= *upper)) {
            return false;
        }

        // Left child must be smaller than current node's value (upper bound)
        // Right child must be larger than current node's value (lower bound)
        long currentVal = node->val;
        return validate(node->left, lower, &currentVal) && 
               validate(node->right, &currentVal, upper);
    }

public:
    // Detailed explanation comments
    // Helper function passes down min and max allowed values.
    // Use pointers for boundaries to easily handle +/- infinity for the root.
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};

int main() {

    // Sample test case
    Solution obj;
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    // Execute solution
    bool isValid = obj.isValidBST(root);
    
    cout << "Is Valid BST: " << (isValid ? "true" : "false") << endl;

    // Memory cleanup omitted for brevity

    return 0;
}
