/*
=========================================================
Problem: House Robber II
Difficulty: Medium
Pattern: Dynamic Programming
LeetCode: #213

Problem Statement:
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example:

Input:
nums = [2,3,2]

Output:
3

Explanation:
Intuition: Because the houses are in a circle, the first house and the last house are adjacent. This means we cannot rob both the first and the last house. So, the optimal solution will either exclude the first house or exclude the last house.
Approach: We can reuse the solution from House Robber I. We run the House Robber I logic on two subarrays: one from `nums[0]` to `nums[n-2]` (excluding the last house), and another from `nums[1]` to `nums[n-1]` (excluding the first house). The maximum of these two results will be our answer. (Don't forget to handle the edge case where there is only one house).
Why it works: By breaking the circular dependency into two separate linear problems, we cover all valid possibilities (robbing first but not last, robbing last but not first, robbing neither) and safely reuse the O(N) DP logic.
Complexity Analysis:

Time Complexity: O(N) where N is the number of houses. We do two passes of length N-1.
Space Complexity: O(1) as we use our O(1) space helper function twice.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    // Helper function from House Robber I
    int robLinear(vector<int>& nums, int start, int end) {
        int rob1 = 0;
        int rob2 = 0;

        for (int i = start; i <= end; i++) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }

public:
    // Detailed explanation comments
    // Run linear House Robber logic twice: 
    // Once excluding the last element, once excluding the first element.
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        // Return the max of robbing houses 0 to n-2 OR houses 1 to n-1
        int max1 = robLinear(nums, 0, nums.size() - 2);
        int max2 = robLinear(nums, 1, nums.size() - 1);
        
        return max(max1, max2);
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {2, 3, 2};

    // Execute solution
    int result = obj.rob(nums);
    
    cout << "Maximum amount to rob (Circle): " << result << endl;

    return 0;
}
