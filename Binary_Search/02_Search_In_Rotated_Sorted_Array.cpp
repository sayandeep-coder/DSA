/*
=========================================================
Problem: Search in Rotated Sorted Array
Difficulty: Medium
Pattern: Binary Search
LeetCode: #33

Problem Statement:
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example:

Input:
nums = [4,5,6,7,0,1,2], target = 0

Output:
4

Explanation:
Intuition: Although the array is rotated, at least one half of the array (from mid) is always perfectly sorted. We can use this property to decide which half to search.
Approach: Use binary search. At each step, find `mid`. Check if `nums[mid]` is the target. If not, check if the left half is sorted (`nums[left] <= nums[mid]`). If it is, check if the target lies within this sorted left half. If it does, search the left half (`right = mid - 1`); otherwise, search the right half (`left = mid + 1`). If the left half is not sorted, the right half must be sorted. Apply the same logic: check if the target is in the sorted right half, and adjust pointers accordingly.
Why it works: By determining which half is properly sorted, we can definitively know if the target lies within that half or the other half, allowing us to discard half the search space at each step.
Complexity Analysis:

Time Complexity: O(log N) where N is the length of the array. The search space is halved every iteration.
Space Complexity: O(1) as we only use pointers.
=========================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Check which half is sorted.
    // Then check if the target lies within the boundaries of the sorted half.
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // Check if left half is sorted
            if (nums[left] <= nums[mid]) {
                // Check if target is in the left sorted half
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1; // Target is in left half
                } else {
                    left = mid + 1; // Target is in right half
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                // Check if target is in the right sorted half
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1; // Target is in right half
                } else {
                    right = mid - 1; // Target is in left half
                }
            }
        }

        return -1; // Target not found
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    // Execute solution
    int result = obj.search(nums, target);
    
    cout << "Target Index: " << result << endl;

    return 0;
}
