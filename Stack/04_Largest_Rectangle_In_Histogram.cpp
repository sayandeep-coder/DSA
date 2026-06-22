/*
=========================================================
Problem: Largest Rectangle in Histogram
Difficulty: Hard
Pattern: Monotonic Stack
LeetCode: #84

Problem Statement:
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example:

Input:
heights = [2,1,5,6,2,3]

Output:
10

Explanation:
Intuition: For each bar, the largest rectangle including that bar (with that bar as the minimum height) extends as far left and right as possible until a shorter bar is encountered. 
Approach: We can use a monotonically increasing stack to keep track of the bars. We store the indices of the bars in the stack. When we encounter a bar that is shorter than the bar at the top of the stack, it means the taller bar at the top cannot be extended any further to the right. So, we pop the top bar and calculate the area of the rectangle formed by it. The width is the difference between the current index (right boundary) and the new top of the stack (left boundary) minus 1. We keep track of the maximum area found.
Why it works: The stack efficiently helps us find the left and right boundaries for every bar. It ensures that we calculate the maximum area for every bar as the bottleneck height exactly once.
Complexity Analysis:

Time Complexity: O(N) where N is the length of heights. Each bar is pushed and popped from the stack at most once.
Space Complexity: O(N) for the stack.
=========================================================
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Use an increasing monotonic stack.
    // When a shorter bar is found, calculate the area for bars in the stack.
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> st; // Stores indices
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            // Append a 0 height bar at the end to force popping all remaining bars
            int currentHeight = (i == n) ? 0 : heights[i];

            // If current bar is shorter, process the bars in the stack
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                // If stack is empty, the bar extended from the very beginning
                // Otherwise, it extended from the previous bar in the stack
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    // Execute solution
    int max_area = obj.largestRectangleArea(heights);
    
    cout << "Largest Rectangle Area: " << max_area << endl;

    return 0;
}
