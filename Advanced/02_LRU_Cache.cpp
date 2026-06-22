/*
=========================================================
Problem: LRU Cache
Difficulty: Medium
Pattern: Doubly Linked List + Hash Map
LeetCode: #146

Problem Statement:
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
- LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
- int get(int key) Return the value of the key if the key exists, otherwise return -1.
- void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example:

Input:
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]

Output:
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation:
Intuition: To achieve O(1) time complexity for both `get` and `put`, we need a combination of data structures. A Hash Map allows O(1) lookups by key. However, a Hash Map cannot maintain the order of usage. A Doubly Linked List can maintain order and allows O(1) additions and removals (if we have a pointer to the node).
Approach: Use an `unordered_map` that maps integer keys to pointers to nodes in a Doubly Linked List. The Doubly Linked List will store the key-value pairs. 
- Most recently used node is kept right after a dummy `head`.
- Least recently used node is kept right before a dummy `tail`.
- `get(key)`: If key exists, look up the node in the map, move it to the front (right after head) to mark it as most recently used, and return its value.
- `put(key, value)`: If key exists, update its value and move it to the front. If not, create a new node, insert it at the front, and add it to the map. If the capacity is exceeded, remove the node before `tail` (the LRU node) from the list and the map.
Why it works: The Hash Map provides O(1) access to nodes. The Doubly Linked List allows O(1) removal of nodes from anywhere (using the map's pointer) and O(1) insertion at the front. The combination perfectly fulfills the LRU requirements.
Complexity Analysis:

Time Complexity: O(1) for both `get` and `put` operations.
Space Complexity: O(capacity) for the Hash Map and Doubly Linked List.
=========================================================
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    // Doubly Linked List Node
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cacheMap;
    Node* head; // Dummy head
    Node* tail; // Dummy tail

    // Helper function to insert a node right after the dummy head
    void insertNode(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    // Helper function to remove a node from the linked list
    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    // Detailed explanation comments
    // If key exists, return value and move to front (Most Recently Used)
    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* resNode = cacheMap[key];
            int res = resNode->value;
            deleteNode(resNode);
            insertNode(resNode);
            return res;
        }
        return -1;
    }
    
    // If key exists, update and move to front.
    // If not, insert at front. Evict from tail if over capacity.
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* existingNode = cacheMap[key];
            cacheMap.erase(key);
            deleteNode(existingNode);
            delete existingNode; // Prevent memory leak
        }
        
        if (cacheMap.size() == capacity) {
            Node* lruNode = tail->prev;
            cacheMap.erase(lruNode->key);
            deleteNode(lruNode);
            delete lruNode; // Prevent memory leak
        }
        
        Node* newNode = new Node(key, value);
        insertNode(newNode);
        cacheMap[key] = newNode;
    }
};

int main() {

    // Sample test case
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    cout << "get(1): " << lRUCache->get(1) << endl;    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << "get(2): " << lRUCache->get(2) << endl;    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << "get(1): " << lRUCache->get(1) << endl;    // return -1 (not found)
    cout << "get(3): " << lRUCache->get(3) << endl;    // return 3
    cout << "get(4): " << lRUCache->get(4) << endl;    // return 4

    return 0;
}
