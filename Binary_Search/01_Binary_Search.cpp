/*
=========================================================
Problem: Binary Search
Difficulty: Easy
Pattern: Binary Search
LeetCode: #704

Problem Statement:
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

Example:

Input:
nums = [-1,0,3,5,9,12], target = 9

Output:
4

Explanation:
Intuition: Since the array is sorted, we can check the middle element. If it's the target, we are done. If it's larger than the target, the target must be in the left half. If it's smaller, the target must be in the right half.
Approach: Use two pointers, `left` and `right`. Calculate the `mid` index. If `nums[mid]` is the target, return `mid`. If `nums[mid] < target`, update `left = mid + 1`. If `nums[mid] > target`, update `right = mid - 1`. Repeat while `left <= right`.
Why it works: By dividing the search space in half at each step, we exponentially reduce the number of elements to check, resulting in a logarithmic time complexity.
Complexity Analysis:

Time Complexity: O(log N) where N is the number of elements in the array. The search space is halved in each iteration.
Space Complexity: O(1) since we only use a few variables for pointers.
=========================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Standard binary search using left and right pointers.
    // Calculate mid carefully to avoid overflow: left + (right - left) / 2
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] < target) {
                left = mid + 1; // Target must be in the right half
            } else {
                right = mid - 1; // Target must be in the left half
            }
        }

        return -1; // Target not found
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    // Execute solution
    int result = obj.search(nums, target);
    
    cout << "Index of Target: " << result << endl;

    return 0;
}
