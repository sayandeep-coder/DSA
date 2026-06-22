/*
=========================================================
Problem: Same Tree
Difficulty: Easy
Pattern: Tree / DFS
LeetCode: #100

Problem Statement:
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example:

Input:
p = [1,2,3], q = [1,2,3]

Output:
true

Explanation:
Intuition: Two trees are the same if their root values are the same and both their left subtrees and right subtrees are identical.
Approach: We can use a recursive Depth-First Search (DFS) approach. Base cases: If both nodes are NULL, they match (return true). If one is NULL and the other is not, or if their values differ, they don't match (return false). Recursive step: Check if `p->left` is the same as `q->left` AND `p->right` is the same as `q->right`.
Why it works: The problem naturally breaks down into checking the current nodes and then recursively ensuring the entire subtrees on both sides mirror each other perfectly.
Complexity Analysis:

Time Complexity: O(min(N, M)) where N and M are the number of nodes in trees p and q respectively. We traverse nodes until we find a mismatch or check all corresponding nodes.
Space Complexity: O(min(H1, H2)) where H1 and H2 are heights of the trees. This is for the call stack during recursion. Worst case O(N) for skewed trees, O(log N) for balanced ones.
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
    // Base cases handle null nodes and value mismatches.
    // Recursive calls ensure structure and values match all the way down.
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both nodes are null
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // One is null or values don't match
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }
        
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {

    // Sample test case
    Solution obj;
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    // Execute solution
    bool result = obj.isSameTree(p, q);
    
    cout << "Is Same Tree: " << (result ? "true" : "false") << endl;

    // Memory cleanup omitted for brevity in template

    return 0;
}
