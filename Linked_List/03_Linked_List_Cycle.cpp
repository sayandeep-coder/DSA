/*
=========================================================
Problem: Linked List Cycle
Difficulty: Easy
Pattern: Fast and Slow Pointers (Floyd's Cycle-Finding Algorithm)
LeetCode: #141

Problem Statement:
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Return true if there is a cycle in the linked list. Otherwise, return false.

Example:

Input:
head = [3,2,0,-4], pos = 1 (where -4 connects back to 2)

Output:
true

Explanation:
Intuition: If there is a cycle, a faster runner will eventually catch up to a slower runner moving on the same track. This is analogous to two people running on a circular track at different speeds.
Approach: Use Floyd's Cycle-Finding Algorithm (Tortoise and Hare). Initialize two pointers, `slow` and `fast`, both at the head. `slow` moves one step at a time, while `fast` moves two steps. If there is a cycle, the `fast` pointer will eventually overlap with the `slow` pointer. If `fast` or `fast->next` reaches NULL, there is no cycle.
Why it works: The relative speed between the fast and slow pointers is 1 node per iteration. Once both pointers are inside the cycle, the fast pointer will close the distance to the slow pointer by 1 node each step, guaranteeing they meet.
Complexity Analysis:

Time Complexity: O(N) where N is the number of nodes. In the worst case (no cycle), we traverse the list once. If there is a cycle, the fast pointer will catch the slow pointer in less than N steps.
Space Complexity: O(1) as we only use two pointers.
=========================================================
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // Detailed explanation comments
    // Use fast and slow pointers. If they meet, there's a cycle.
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move 1 step
            fast = fast->next->next;    // Move 2 steps

            // If they meet, a cycle exists
            if (slow == fast) {
                return true;
            }
        }

        return false; // Fast pointer reached the end, so no cycle
    }
};

int main() {

    // Sample test case
    Solution obj;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    
    // Create a cycle
    head->next->next->next->next = head->next;

    // Execute solution
    bool result = obj.hasCycle(head);
    
    cout << "Has Cycle: " << (result ? "true" : "false") << endl;

    // Note: To avoid memory leak in actual code, you'd need to break the cycle before deleting.
    // We skip memory cleanup here due to the intentional cycle.

    return 0;
}
