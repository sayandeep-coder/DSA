/*
=========================================================
Problem: Median of Two Sorted Arrays
Difficulty: Hard
Pattern: Binary Search
LeetCode: #4

Problem Statement:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example:

Input:
nums1 = [1,3], nums2 = [2]

Output:
2.00000

Explanation:
Intuition: The median divides an array into two equal halves. We want to partition both arrays such that the total number of elements on the left side of the partitions equals the total number on the right side, and all elements on the left are less than or equal to all elements on the right.
Approach: We can do a binary search on the smaller array to find the correct partition. Let's say we partition `nums1` at index `i` and `nums2` at index `j`. Then `i + j = (m + n + 1) / 2`. We need to ensure `nums1[i-1] <= nums2[j]` and `nums2[j-1] <= nums1[i]`. We adjust the partition `i` based on these conditions.
Why it works: By doing binary search on the smaller array, we find the correct partition in O(log(min(m, n))) time.
Complexity Analysis:

Time Complexity: O(log(min(m, n))) since we binary search on the smaller array.
Space Complexity: O(1) as we only use a few variables.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Binary search on the smaller array to find the correct partition.
    // Partition such that max(left_elements) <= min(right_elements).
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); // Ensure nums1 is smaller
        }
        
        int x = nums1.size();
        int y = nums2.size();
        int low = 0;
        int high = x;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            // Handle edge cases using INT_MIN and INT_MAX
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            
            // Check if we found the correct partition
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If total number of elements is even
                if ((x + y) % 2 == 0) {
                    return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                } 
                // If total number of elements is odd
                else {
                    return (double)max(maxLeftX, maxLeftY);
                }
            } 
            // Move partition to the left
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } 
            // Move partition to the right
            else {
                low = partitionX + 1;
            }
        }
        
        return 0.0;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    // Execute solution
    double median = obj.findMedianSortedArrays(nums1, nums2);
    
    cout << "Median of Two Sorted Arrays: " << median << endl;

    return 0;
}
