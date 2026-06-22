/*
=========================================================
Problem: Remove Nth Node From End of List
Difficulty: Medium
Pattern: Linked List / Fast & Slow Pointers
LeetCode: #19

Problem Statement:
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example:

Input:
head = [1,2,3,4,5], n = 2

Output:
[1,2,3,5]

Explanation:
Intuition: If we want to find the nth node from the end in a single pass, we can use two pointers with a gap of 'n' between them. When the front pointer reaches the end, the trailing pointer will be right before the node we need to remove.
Approach: Create a dummy node pointing to the head to handle edge cases easily (like removing the very first node). Initialize two pointers, `left` and `right`, both pointing to the dummy node. Move the `right` pointer `n + 1` steps forward. Then, move both `left` and `right` pointers one step at a time until `right` reaches NULL. Now, `left` is pointing to the node immediately preceding the one we want to remove. Update `left->next` to skip the target node.
Why it works: The constant gap of `n` between the pointers guarantees that when the right pointer falls off the end of the list, the left pointer is exactly where it needs to be to perform the deletion.
Complexity Analysis:

Time Complexity: O(N) where N is the length of the list. We traverse the list once.
Space Complexity: O(1) as we only use a few pointers.
=========================================================
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    // Detailed explanation comments
    // Use two pointers. Move the fast pointer n steps ahead.
    // Then move both until the fast pointer reaches the end.
    // The slow pointer will be right before the node to delete.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* left = &dummy;
        ListNode* right = &dummy;
        
        // Move right pointer n + 1 steps ahead
        for (int i = 0; i <= n; i++) {
            right = right->next;
        }
        
        // Move both pointers until right reaches the end
        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }
        
        // Delete the nth node from the end
        ListNode* nodeToDelete = left->next;
        left->next = left->next->next;
        delete nodeToDelete; // Optional but good practice in C++
        
        return dummy.next;
    }
};

int main() {

    // Sample test case
    Solution obj;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int n = 2;

    // Execute solution
    ListNode* resultHead = obj.removeNthFromEnd(head, n);
    
    cout << "List after removal: ";
    ListNode* curr = resultHead;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // Clean up memory
    curr = resultHead;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
