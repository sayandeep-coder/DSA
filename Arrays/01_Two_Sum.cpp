/*
=========================================================
Problem: Two Sum
Difficulty: Easy
Pattern: Hash Map
LeetCode: #1

Problem Statement:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example:

Input:
nums = [2,7,11,15], target = 9

Output:
[0,1]

Explanation:
Intuition: We need to find a pair of numbers that add up to the target. Instead of checking every pair (which takes O(n^2) time), we can store the numbers we have seen so far.
Approach: We use a Hash Map to store the numbers along with their index. As we iterate through the array, if `target - current number` is already in our map, it means we found the pair.
Why it works: As we iterate, for each number `x`, we check if `target - x` exists in our map. If it does, we have our two numbers. If not, we add `x` and its index to the map so it can be found by subsequent elements.
Complexity Analysis:

Time Complexity: O(N) where N is the number of elements in the array. We iterate through the array once and hash map lookups take O(1) on average.
Space Complexity: O(N) for storing up to N elements in the hash map.
=========================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // We use an unordered_map to store value -> index mappings
    // As we process each number, we look for its complement (target - num)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // If the complement exists in map, return its index and current index
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Otherwise, store current number and its index
            numMap[nums[i]] = i;
        }
        return {}; // Return empty if no solution found
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Execute solution
    vector<int> result = obj.twoSum(nums, target);
    
    if (result.size() == 2) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
