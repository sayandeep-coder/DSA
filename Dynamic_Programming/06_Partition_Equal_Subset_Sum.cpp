/*
=========================================================
Problem: Partition Equal Subset Sum
Difficulty: Medium
Pattern: Dynamic Programming (0/1 Knapsack)
LeetCode: #416

Problem Statement:
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example:

Input:
nums = [1,5,11,5]

Output:
true

Explanation:
Intuition: If we can partition the array into two subsets with equal sums, then each subset must sum to exactly half of the total sum of the array. This reduces the problem to: Can we find a subset of `nums` that sums up to `total_sum / 2`? This is a classic 0/1 Knapsack problem.
Approach: First, calculate the total sum. If it's odd, return false (we can't divide an odd integer into two equal integers). The target sum is `total_sum / 2`. We can use a 1D DP array of booleans `dp` where `dp[i]` is `true` if a subset with sum `i` can be formed. Initialize `dp[0] = true`. Iterate through each number in `nums`. For each number, iterate backwards through the `dp` array from `target` down to `number`. If `dp[j - number]` is `true`, it means we can form the sum `j` by adding the current number to the subset that forms `j - number`. Set `dp[j] = true`. Finally, return `dp[target]`.
Why it works: Iterating backwards ensures we don't reuse the same element multiple times (which is the rule of 0/1 Knapsack). By tracking all reachable sums dynamically, we verify if the target sum is achievable.
Complexity Analysis:

Time Complexity: O(N * S) where N is the length of `nums` and S is the `total_sum / 2`.
Space Complexity: O(S) for the DP array of size `total_sum / 2 + 1`.
=========================================================
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Convert to a subset sum problem where target is total_sum / 2.
    // Use a 1D DP array to track achievable sums. Iterate backwards to prevent element reuse.
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If the total sum is odd, it's impossible to partition into equal integer halves
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // We can always make a sum of 0 with an empty subset

        for (int num : nums) {
            // Iterate backwards to ensure each element is used at most once
            for (int i = target; i >= num; i--) {
                // If we can make (i - num), we can make i by adding num
                if (dp[i - num]) {
                    dp[i] = true;
                }
            }
        }

        return dp[target];
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {1, 5, 11, 5};

    // Execute solution
    bool result = obj.canPartition(nums);
    
    cout << "Can partition equal subset sum: " << (result ? "true" : "false") << endl;

    return 0;
}
