/*
=========================================================
Problem: Merge Two Sorted Lists
Difficulty: Easy
Pattern: Linked List / Two Pointers
LeetCode: #21

Problem Statement:
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example:

Input:
list1 = [1,2,4], list2 = [1,3,4]

Output:
[1,1,2,3,4,4]

Explanation:
Intuition: Since both lists are already sorted, we can use a two-pointer approach, comparing the heads of the two lists and attaching the smaller node to a new merged list.
Approach: Create a dummy node to simplify edge cases. Use a `tail` pointer to keep track of the end of the new list. While both `list1` and `list2` are not empty, compare their values. Append the smaller one to `tail->next` and advance the corresponding list pointer. Finally, if one list is exhausted, append the remaining part of the other list directly to the `tail`.
Why it works: By iteratively taking the smallest available element from the front of the two lists, we build a sorted merged list.
Complexity Analysis:

Time Complexity: O(N + M) where N and M are the lengths of the two lists. We traverse each node at most once.
Space Complexity: O(1) as we just reuse the existing nodes and change their pointers.
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
    // Use a dummy head to easily construct the merged list.
    // Iteratively append the smaller of the two head nodes.
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Append any remaining nodes
        if (list1 != nullptr) {
            tail->next = list1;
        } else if (list2 != nullptr) {
            tail->next = list2;
        }
        
        return dummy.next;
    }
};

int main() {

    // Sample test case
    Solution obj;
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    // Execute solution
    ListNode* mergedHead = obj.mergeTwoLists(list1, list2);
    
    cout << "Merged List: ";
    ListNode* curr = mergedHead;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // Clean up memory
    curr = mergedHead;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
