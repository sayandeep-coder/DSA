/*
=========================================================
Problem: Daily Temperatures
Difficulty: Medium
Pattern: Monotonic Stack
LeetCode: #739

Problem Statement:
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example:

Input:
temperatures = [73,74,75,71,69,72,76,73]

Output:
[1,1,4,2,1,1,0,0]

Explanation:
Intuition: We want to find the next greater element for each item in the array. A brute force approach would be O(N^2). We can optimize this by keeping track of elements we haven't found a warmer day for yet.
Approach: We use a Monotonic Decreasing Stack. The stack will store the indices of the temperatures. As we iterate through the array, we compare the current temperature with the temperature at the index stored at the top of the stack. If the current temperature is higher, it means we found a warmer day for the day at the top of the stack. We pop the index from the stack, calculate the difference in days (current index - popped index), and store it in our result array. We repeat this while the stack is not empty and the current temperature is higher. Then, we push the current index onto the stack.
Why it works: By storing indices in a monotonically decreasing order (based on their temperatures), we ensure that we only process each element twice (once pushed, once popped). This turns an O(N^2) problem into an O(N) problem.
Complexity Analysis:

Time Complexity: O(N) where N is the length of temperatures. Each element is pushed and popped from the stack at most once.
Space Complexity: O(N) in the worst case (e.g., temperatures are monotonically decreasing), where the stack will store all indices.
=========================================================
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Use a stack to store indices of days we haven't found a warmer day for.
    // If the current day is warmer than the day at the top of the stack,
    // we found the answer for the day at the top of the stack.
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; // Stores indices

        for (int i = 0; i < n; i++) {
            // While stack is not empty and current temp is greater than temp at top of stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                // Calculate the number of days waited
                result[prevIndex] = i - prevIndex;
            }
            // Push current index onto the stack
            st.push(i);
        }

        return result;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    // Execute solution
    vector<int> result = obj.dailyTemperatures(temperatures);
    
    cout << "Daily Temperatures: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
