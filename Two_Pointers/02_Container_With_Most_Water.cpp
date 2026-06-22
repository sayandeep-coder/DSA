/*
=========================================================
Problem: Container With Most Water
Difficulty: Medium
Pattern: Two Pointers
LeetCode: #11

Problem Statement:
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

Example:

Input:
height = [1,8,6,2,5,4,8,3,7]

Output:
49

Explanation:
Intuition: The area of water is determined by `min(height[left], height[right]) * (right - left)`. To maximize this area, we want the lines to be as far apart as possible and as tall as possible.
Approach: Use two pointers, `left` at the beginning and `right` at the end of the array. Calculate the area formed by these lines and update the maximum area found so far. To decide which pointer to move, we should move the one pointing to the shorter line. Moving the taller line wouldn't increase the height of the container, and it would definitely decrease the width, leading to a smaller area.
Why it works: By greedily eliminating the shorter line at each step, we explore all promising container boundaries without needing an O(N^2) brute force search.
Complexity Analysis:

Time Complexity: O(N) where N is the number of elements in the array. The two pointers traverse the array exactly once.
Space Complexity: O(1) as we only use variables for pointers and the maximum area.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Start with max width. The height is limited by the shorter line.
    // To potentially increase area, move the pointer at the shorter line inward.
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // Calculate current area
            int current_water = min(height[left], height[right]) * (right - left);
            max_water = max(max_water, current_water);

            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Execute solution
    int result = obj.maxArea(height);
    
    cout << "Max Area of Water: " << result << endl;

    return 0;
}
