/*
=========================================================
Problem: Merge k Sorted Lists
Difficulty: Hard
Pattern: Heap / Priority Queue / Divide and Conquer
LeetCode: #23

Problem Statement:
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example:

Input:
lists = [[1,4,5],[1,3,4],[2,6]]

Output:
[1,1,2,3,4,4,5,6]

Explanation:
Intuition: If we want to merge `k` sorted lists, the smallest element overall must be one of the `k` heads of the lists. If we pull the smallest element out, the new smallest must be either the next element from that same list or one of the heads of the other lists. We need an efficient way to repeatedly find the minimum of `k` elements.
Approach: A Min-Heap (Priority Queue) is perfect for this. First, push the head node of all `k` lists into the Min-Heap. The heap will order them based on their node values. Then, while the heap is not empty, extract the minimum node and append it to our result list. If the extracted node has a `next` node, push that `next` node into the heap. Repeat until the heap is empty.
Why it works: A Min-Heap allows extracting the minimum element and inserting a new element both in O(log k) time. Thus, comparing elements from the current front of each list remains extremely efficient.
Complexity Analysis:

Time Complexity: O(N log k) where N is the total number of nodes across all lists, and k is the number of linked lists. Each extraction and insertion takes O(log k) time.
Space Complexity: O(k) for the priority queue, which stores at most one node from each of the k lists at any time.
=========================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Custom comparator for the priority queue to create a Min-Heap based on ListNode values
struct CompareNode {
    bool operator()(ListNode* const& p1, ListNode* const& p2) {
        // Return true if p1 should be ordered AFTER p2 (which creates a min-heap)
        return p1->val > p2->val;
    }
};

class Solution {
public:

    // Detailed explanation comments
    // Use a Min-Heap (priority_queue) to keep track of the smallest current head among the k lists.
    // Continually extract the min and push its next node back into the heap.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;
        
        // Push the head of each list into the heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        
        ListNode dummy;
        ListNode* tail = &dummy;
        
        // Process the heap
        while (!minHeap.empty()) {
            // Get the smallest node
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            
            // Append it to our result list
            tail->next = minNode;
            tail = tail->next;
            
            // If there's a next node in the list we just pulled from, push it to heap
            if (minNode->next != nullptr) {
                minHeap.push(minNode->next);
            }
        }
        
        return dummy.next;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<ListNode*> lists;
    lists.push_back(new ListNode(1, new ListNode(4, new ListNode(5))));
    lists.push_back(new ListNode(1, new ListNode(3, new ListNode(4))));
    lists.push_back(new ListNode(2, new ListNode(6)));

    // Execute solution
    ListNode* mergedHead = obj.mergeKLists(lists);
    
    cout << "Merged k Sorted Lists: [";
    ListNode* curr = mergedHead;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << ", ";
        curr = curr->next;
    }
    cout << "]" << endl;

    // Clean up memory
    curr = mergedHead;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
