/*
=========================================================
Problem: Reverse Linked List
Difficulty: Easy
Pattern: Linked List
LeetCode: #206

Problem Statement:
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example:

Input:
head = [1,2,3,4,5]

Output:
[5,4,3,2,1]

Explanation:
Intuition: We need to change the `next` pointers of each node so they point to the previous node instead of the next node.
Approach: We can use an iterative approach with two pointers: `prev` (initially NULL) and `current` (initially `head`). In a loop, we first temporarily save `current->next`. Then we reverse the pointer by setting `current->next = prev`. We then advance `prev` to `current` and `current` to the saved next node. When `current` reaches NULL, `prev` will be the new head.
Why it works: By keeping track of the previous node, we can incrementally reverse the direction of links one node at a time without losing the reference to the rest of the list.
Complexity Analysis:

Time Complexity: O(N) where N is the number of nodes in the linked list. We traverse the list exactly once.
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
    // Iteratively reverse links. Keep track of previous node.
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        
        while (current != nullptr) {
            // Save the next node
            ListNode* nextTemp = current->next;
            
            // Reverse the link
            current->next = prev;
            
            // Move prev and current one step forward
            prev = current;
            current = nextTemp;
        }
        
        // prev is the new head of the reversed list
        return prev;
    }
};

int main() {

    // Sample test case
    Solution obj;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    // Execute solution
    ListNode* reversedHead = obj.reverseList(head);
    
    cout << "Reversed List: ";
    ListNode* curr = reversedHead;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // Clean up memory
    curr = reversedHead;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
