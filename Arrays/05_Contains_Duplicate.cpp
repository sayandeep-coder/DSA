/*
=========================================================
Problem: Contains Duplicate
Difficulty: Easy
Pattern: Hash Set
LeetCode: #217

Problem Statement:
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example:

Input:
nums = [1,2,3,1]

Output:
true

Explanation:
Intuition: To find duplicates efficiently, we need a way to keep track of the elements we have already seen. A Hash Set is ideal for this since it provides O(1) average time complexity for both insertions and lookups.
Approach: Iterate through the array. For each element, check if it is already present in a Hash Set. If it is, we found a duplicate, so return `true`. If not, add the element to the set. If we finish checking all elements without finding any duplicates, return `false`.
Why it works: A set only stores unique elements. If an attempt to insert an element or find an element in the set succeeds while iterating, it guarantees the element appeared earlier in the array.
Complexity Analysis:

Time Complexity: O(N) where N is the length of the array. We visit each element at most once. Hash set lookups and insertions take O(1) on average.
Space Complexity: O(N) to store up to N elements in the hash set in the worst case (when all elements are distinct).
=========================================================
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // We use an unordered_set to track numbers we've seen.
    // If a number is already in the set, it's a duplicate.
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int i = 0; i < nums.size(); i++) {
            // If the element is already in the set, we found a duplicate
            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }
            // Otherwise, add it to the set
            seen.insert(nums[i]);
        }
        
        // No duplicates found
        return false;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {1, 2, 3, 1};

    // Execute solution
    bool hasDuplicate = obj.containsDuplicate(nums);
    
    cout << "Contains Duplicate: " << (hasDuplicate ? "true" : "false") << endl;

    return 0;
}
