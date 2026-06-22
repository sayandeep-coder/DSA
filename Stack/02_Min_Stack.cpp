/*
=========================================================
Problem: Min Stack
Difficulty: Medium
Pattern: Stack
LeetCode: #155

Problem Statement:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example:

Input:
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output:
[null,null,null,null,-3,null,0,-2]

Explanation:
Intuition: A standard stack supports push, pop, and top in O(1) time. However, finding the minimum element would require scanning the stack in O(N) time. To make `getMin()` O(1), we need to store the minimum value alongside the elements.
Approach: We can use two stacks: a main stack to store the actual values, and a `minStack` to keep track of the minimum values. When pushing a value, we push it to the main stack. We also push the minimum of the new value and the current minimum (top of `minStack`) onto the `minStack`. When popping, we simply pop from both stacks, keeping them synchronized.
Why it works: At any given point, the top of `minStack` holds the minimum value among all elements currently in the main stack. Since we push/pop from both stacks simultaneously, the minimum is always correctly maintained.
Complexity Analysis:

Time Complexity: O(1) for all operations (push, pop, top, getMin).
Space Complexity: O(N) where N is the number of elements pushed, as we use an additional stack to store the minimums.
=========================================================
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    // Initialize the stack object.
    MinStack() {
        
    }
    
    // Detailed explanation comments
    // Push the value onto the main stack.
    // Also push the new minimum onto the minStack.
    void push(int val) {
        mainStack.push(val);
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(min(val, minStack.top()));
        }
    }
    
    // Pop the element from both stacks to maintain synchronization.
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    // Get the top element of the main stack.
    int top() {
        return mainStack.top();
    }
    
    // Get the minimum element from the top of minStack.
    int getMin() {
        return minStack.top();
    }
};

int main() {

    // Sample test case
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);

    // Execute solution
    cout << "getMin: " << obj->getMin() << endl; // Returns -3
    obj->pop();
    cout << "top: " << obj->top() << endl;       // Returns 0
    cout << "getMin: " << obj->getMin() << endl; // Returns -2

    delete obj;
    return 0;
}
