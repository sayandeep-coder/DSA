/*
=========================================================
Problem: Maximum Subarray
Difficulty: Medium
Pattern: Kadane's Algorithm / Dynamic Programming
LeetCode: #53

Problem Statement:
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Example:

Input:
nums = [-2,1,-3,4,-1,2,1,-5,4]

Output:
6

Explanation:
Intuition: If the sum of the subarray leading up to the current element is negative, it will only decrease the total sum. Therefore, we should discard the prefix and start a new subarray from the current element.
Approach: This is solved optimally using Kadane's Algorithm. We maintain two variables: `currentSum` and `maxSum`. We iterate through the array, adding each element to `currentSum`. If `currentSum` ever becomes negative, we reset it to 0. At each step, we update `maxSum` with the maximum of `maxSum` and `currentSum`. (Note: To handle arrays with all negative numbers, we reset `currentSum` *after* checking, or compare the element itself to `currentSum + element`).
Why it works: By resetting the sum when it drops below zero, we effectively ignore parts of the array that would drag down our maximum sum. This greedy choice guarantees finding the maximum contiguous sum.
Complexity Analysis:

Time Complexity: O(N) where N is the length of the array, as we iterate through it exactly once.
Space Complexity: O(1) since we only use a few variables for tracking the sums.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // We use Kadane's Algorithm to track the maximum sum subarray ending at the current position.
    // If the current sum becomes negative, we reset it, effectively starting a new subarray.
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // Add current number to current sum
            currentSum += nums[i];
            
            // Update maxSum if current sum is greater
            maxSum = max(maxSum, currentSum);
            
            // If current sum drops below zero, it's better to start a new subarray
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        
        return maxSum;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Execute solution
    int max_sum = obj.maxSubArray(nums);
    
    cout << "Maximum Subarray Sum: " << max_sum << endl;

    return 0;
}
