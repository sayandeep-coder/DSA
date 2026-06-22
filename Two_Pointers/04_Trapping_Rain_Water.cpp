/*
=========================================================
Problem: Trapping Rain Water
Difficulty: Hard
Pattern: Two Pointers
LeetCode: #42

Problem Statement:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example:

Input:
height = [0,1,0,2,1,0,1,3,2,1,2,1]

Output:
6

Explanation:
Intuition: The water trapped above any column `i` is determined by the minimum of the highest bars to its left and right, minus its own height. That is, `Water[i] = min(max_left, max_right) - height[i]`.
Approach: Using two pointers (`left` at 0, `right` at n-1), we maintain `maxLeft` and `maxRight`. We always move the pointer that points to the shorter max height. If `maxLeft < maxRight`, the bottleneck is on the left, so we can definitively calculate the water for the `left` column as `maxLeft - height[left]`, and then advance `left`. Otherwise, we calculate for `right` and decrement `right`.
Why it works: By moving the pointer with the smaller max boundary, we know for sure that the other boundary is at least as high. This guarantees that `min(maxLeft, maxRight)` is completely accurate for the current position being processed, allowing O(1) space complexity.
Complexity Analysis:

Time Complexity: O(N) where N is the number of elements in height. We process each element once.
Space Complexity: O(1) as we only use pointers and variables to track max heights and total water.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Use two pointers to track the max heights from both ends.
    // The amount of water is bounded by the shorter of the two max heights.
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = height[left];
        int maxRight = height[right];
        int water = 0;

        while (left < right) {
            if (maxLeft < maxRight) {
                left++;
                maxLeft = max(maxLeft, height[left]);
                water += maxLeft - height[left];
            } else {
                right--;
                maxRight = max(maxRight, height[right]);
                water += maxRight - height[right];
            }
        }

        return water;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Execute solution
    int result = obj.trap(height);
    
    cout << "Trapped Rain Water: " << result << endl;

    return 0;
}
