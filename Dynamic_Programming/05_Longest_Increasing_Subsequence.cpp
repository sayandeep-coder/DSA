/*
=========================================================
Problem: Longest Increasing Subsequence
Difficulty: Medium
Pattern: Dynamic Programming
LeetCode: #300

Problem Statement:
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example:

Input:
nums = [10,9,2,5,3,7,101,18]

Output:
4

Explanation:
Intuition: For any element `nums[i]`, the longest increasing subsequence ending at `nums[i]` can be formed by appending `nums[i]` to the longest increasing subsequence ending at some `nums[j]` where `j < i` and `nums[j] < nums[i]`.
Approach: Create a DP array `dp` of the same size as `nums`, initialized to 1 (since the minimum length of an increasing subsequence is 1, which is the element itself). Iterate through the array with `i` from 1 to `n-1`. For each `i`, iterate through `j` from 0 to `i-1`. If `nums[i] > nums[j]`, it means we can extend the subsequence ending at `j`. So, we update `dp[i] = max(dp[i], dp[j] + 1)`. The overall longest increasing subsequence will be the maximum value in the `dp` array.
Why it works: DP systematically explores all valid increasing combinations by remembering the best subsequence length up to every index, avoiding redundant recalculations. (Note: There is an O(N log N) solution using Binary Search and Patience Sorting, but DP is O(N^2) and usually expected first).
Complexity Analysis:

Time Complexity: O(N^2) where N is the length of the array. The nested loops iterate over pairs of elements.
Space Complexity: O(N) for the DP array.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // dp[i] holds the LIS ending at index i.
    // Compare nums[i] with all previous elements to find the longest sequence to extend.
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLIS = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If it's strictly increasing, we can extend the sequence
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLIS = max(maxLIS, dp[i]);
        }

        return maxLIS;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Execute solution
    int result = obj.lengthOfLIS(nums);
    
    cout << "Length of Longest Increasing Subsequence: " << result << endl;

    return 0;
}
