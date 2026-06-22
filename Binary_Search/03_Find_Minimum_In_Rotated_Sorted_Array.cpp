/*
=========================================================
Problem: Find Minimum in Rotated Sorted Array
Difficulty: Medium
Pattern: Binary Search
LeetCode: #153

Problem Statement:
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.

Example:

Input:
nums = [3,4,5,1,2]

Output:
1

Explanation:
Intuition: In a rotated sorted array, the minimum element is the only element whose previous element is greater than it. Also, if we look at the middle element, it can tell us which half contains the minimum.
Approach: Use binary search. Maintain `left` and `right` pointers. Calculate `mid`. If `nums[mid] > nums[right]`, it means the sequence is out of order in the right half (e.g., [3,4,5,1,2]), so the minimum must be to the right of `mid`. Thus, `left = mid + 1`. If `nums[mid] <= nums[right]`, the right half is sorted, meaning the minimum is either at `mid` or in the left half. Thus, `right = mid`. We repeat until `left == right`, at which point they point to the minimum.
Why it works: By comparing the middle element with the rightmost element of our current search space, we can definitively rule out half of the array at each step, maintaining O(log N) complexity.
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
    // Compare mid with the rightmost element to find where the drop occurs.
    // If mid is greater, min is to the right. Else, min is mid or to the left.
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum must be in the right half
                left = mid + 1;
            } else {
                // Minimum is mid or in the left half
                right = mid;
            }
        }

        // When left == right, we found the minimum
        return nums[left];
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {3, 4, 5, 1, 2};

    // Execute solution
    int min_val = obj.findMin(nums);
    
    cout << "Minimum Element: " << min_val << endl;

    return 0;
}
