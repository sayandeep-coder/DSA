/*
=========================================================
Problem: Valid Parentheses
Difficulty: Easy
Pattern: Stack
LeetCode: #20

Problem Statement:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Example:

Input:
s = "()[]{}"

Output:
true

Explanation:
Intuition: We need to ensure that every closing bracket matches the most recently opened unmatched bracket. This LIFO (Last-In-First-Out) requirement makes a Stack the perfect data structure.
Approach: Iterate through the string. If the current character is an opening bracket, push it onto the stack. If it's a closing bracket, check if the stack is empty (meaning there's no matching opening bracket) or if the top of the stack doesn't match the correct opening bracket type. If they don't match, return false. If they do match, pop the top element from the stack. Finally, return true only if the stack is empty (meaning all opened brackets were properly closed).
Why it works: A stack intrinsically enforces the "correct order" requirement by ensuring the most recently seen opening bracket is the one matched with the current closing bracket.
Complexity Analysis:

Time Complexity: O(N) where N is the length of the string. We iterate through the string once, and stack operations (push/pop) take O(1) time.
Space Complexity: O(N) in the worst case (e.g., all opening brackets "((((("), where all characters are pushed onto the stack.
=========================================================
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Use a stack to keep track of opening brackets.
    // Match closing brackets with the top of the stack.
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // Handle closing brackets
            else {
                // If stack is empty, there's no matching opening bracket
                if (st.empty()) return false;
                
                char top = st.top();
                // Check if the top matches the corresponding closing bracket
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    // Mismatch found
                    return false;
                }
            }
        }
        
        // If stack is empty, all brackets matched correctly
        return st.empty();
    }
};

int main() {

    // Sample test case
    Solution obj;
    string s = "()[]{}";

    // Execute solution
    bool result = obj.isValid(s);
    
    cout << "Is Valid Parentheses: " << (result ? "true" : "false") << endl;

    return 0;
}
