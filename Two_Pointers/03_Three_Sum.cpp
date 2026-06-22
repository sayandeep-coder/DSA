/*
=========================================================
Problem: 3Sum
Difficulty: Medium
Pattern: Sorting / Two Pointers
LeetCode: #15

Problem Statement:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example:

Input:
nums = [-1,0,1,2,-1,-4]

Output:
[[-1,-1,2],[-1,0,1]]

Explanation:
Intuition: Finding three numbers that sum to zero is an extension of Two Sum. If we pick one number `nums[i]`, we just need to find two other numbers that sum to `-nums[i]`. To handle duplicates easily, we can sort the array first.
Approach: First, sort the array. Iterate through the array with index `i`. For each `nums[i]`, use two pointers (`left = i + 1`, `right = n - 1`) to find pairs that sum to `-nums[i]`. If `nums[left] + nums[right] < -nums[i]`, advance `left`. If the sum is greater, decrement `right`. If a triplet is found, add it to the results and advance `left` and `right` while skipping duplicates. Also skip duplicate `nums[i]` in the outer loop.
Why it works: Sorting allows us to use two pointers to find pairs efficiently in O(N) time for each element. It also naturally groups duplicates together, making it trivial to skip them and avoid duplicate triplets in the output.
Complexity Analysis:

Time Complexity: O(N^2) where N is the number of elements. Sorting takes O(N log N) and the two loops take O(N^2) time.
Space Complexity: O(1) or O(log N) depending on the sorting algorithm. We don't consider the space used for output.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Sort the array to easily use two pointers and skip duplicates.
    // Fix one number and search for the other two using left and right pointers.
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second and third numbers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // Execute solution
    vector<vector<int>> result = obj.threeSum(nums);
    
    cout << "Triplets: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << ", " << result[i][2] << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
