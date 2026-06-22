/*
=========================================================
Problem: Reorder List
Difficulty: Medium
Pattern: Linked List / Fast & Slow Pointers / Reverse Linked List
LeetCode: #143

Problem Statement:
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example:

Input:
head = [1,2,3,4]

Output:
[1,4,2,3]

Explanation:
Intuition: The reordered list is a combination of the first half of the list going forward, and the second half of the list going backward.
Approach: We can break this problem into three steps:
1. Find the middle of the linked list using fast and slow pointers.
2. Reverse the second half of the linked list.
3. Merge the two halves alternately.
Why it works: By finding the middle, we naturally split the list into two halves. Reversing the second half allows us to easily access the nodes from the end (Ln, Ln-1, etc.) in order. Merging them alternately gives the desired L0 -> Ln -> L1 -> Ln-1 pattern.
Complexity Analysis:

Time Complexity: O(N) where N is the number of nodes. Finding the middle takes O(N), reversing takes O(N), and merging takes O(N).
Space Complexity: O(1) as we only re-arrange existing nodes and use a few pointers.
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
    // 1. Find middle, 2. Reverse second half, 3. Merge alternately
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find the middle using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half
        ListNode* second = slow->next;
        slow->next = nullptr; // Split the list into two
        ListNode* prev = nullptr;
        while (second) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        // 3. Merge the two halves
        ListNode* first = head;
        second = prev;
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

int main() {

    // Sample test case
    Solution obj;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    // Execute solution
    obj.reorderList(head);
    
    cout << "Reordered List: ";
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // Clean up memory
    curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
