/*
=========================================================
Problem: House Robber
Difficulty: Medium
Pattern: Dynamic Programming
LeetCode: #198

Problem Statement:
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example:

Input:
nums = [2,7,9,3,1]

Output:
12

Explanation:
Intuition: For each house, we have a choice: either we rob it (which means we couldn't have robbed the previous house) or we skip it (which means we keep whatever maximum profit we had up to the previous house).
Approach: Let `dp[i]` be the maximum profit up to house `i`. The recurrence relation is: `dp[i] = max(dp[i-1], nums[i] + dp[i-2])`. Since we only need the last two calculations at any step, we don't need a full array. We can use two variables, `rob1` and `rob2`, representing the max profit up to `i-2` and `i-1` respectively. As we iterate through the houses, we calculate `temp = max(nums[i] + rob1, rob2)`, then update `rob1 = rob2` and `rob2 = temp`.
Why it works: By building the solution from the ground up and only storing the essential state variables, we find the optimal sequence of robberies efficiently in a single pass.
Complexity Analysis:

Time Complexity: O(N) where N is the number of houses. We iterate through the array exactly once.
Space Complexity: O(1) as we only use two integer variables to store our dynamic programming state.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // At each house, decide whether to rob it + profit from two houses ago,
    // or skip it and take the max profit from the previous house.
    int rob(vector<int>& nums) {
        int rob1 = 0; // max profit up to i-2
        int rob2 = 0; // max profit up to i-1

        for (int num : nums) {
            int temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {2, 7, 9, 3, 1};

    // Execute solution
    int result = obj.rob(nums);
    
    cout << "Maximum amount to rob: " << result << endl;

    return 0;
}
