/*
=========================================================
Problem: Longest Substring Without Repeating Characters
Difficulty: Medium
Pattern: Sliding Window
LeetCode: #3

Problem Statement:
Given a string s, find the length of the longest substring without repeating characters.

Example:

Input:
s = "abcabcbb"

Output:
3

Explanation:
Intuition: As we scan through the string, we want to maintain a window of characters that has no duplicates. If we encounter a duplicate, we must shrink the window from the left until the duplicate is removed.
Approach: Use a sliding window defined by two pointers, `left` and `right`. Use a Hash Set (or Hash Map) to keep track of characters currently in the window. Expand the `right` pointer and add characters to the set. If a character is already in the set, advance the `left` pointer, removing characters from the set until the duplicate is removed. Keep track of the maximum window size.
Why it works: By sliding a valid window over the string and storing unique elements, we avoid re-evaluating substrings redundantly, allowing us to find the longest one efficiently.
Complexity Analysis:

Time Complexity: O(N) where N is the length of the string. Each character is processed by the right pointer and left pointer at most once.
Space Complexity: O(min(N, M)) where M is the size of the character set (e.g., 26 for lowercase English letters, 128 for ASCII) as we store elements in the unordered set.
=========================================================
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Use a sliding window with a left and right pointer.
    // Expand the window with right pointer. If a duplicate is found,
    // shrink the window from the left until it's valid again.
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // While a duplicate exists in the window, shrink from left
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            // Add current character to set and update max length
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

int main() {

    // Sample test case
    Solution obj;
    string s = "abcabcbb";

    // Execute solution
    int result = obj.lengthOfLongestSubstring(s);
    
    cout << "Longest Substring Length: " << result << endl;

    return 0;
}
