/*
=========================================================
Problem: Minimum Window Substring
Difficulty: Hard
Pattern: Sliding Window
LeetCode: #76

Problem Statement:
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example:

Input:
s = "ADOBECODEBANC", t = "ABC"

Output:
"BANC"

Explanation:
Intuition: We need to find a substring in `s` that contains all characters of `t`. We can use a sliding window approach. We expand the window to the right until it contains all required characters, then shrink it from the left to minimize its length while still being valid.
Approach: Use two pointers, `left` and `right`. Maintain a hash map `tCount` for characters in `t`, and `window` for characters in our current window. Keep a `have` counter for characters whose frequency in the window matches the required frequency in `t`, and a `need` counter which is the size of `tCount`. When `have == need`, the window is valid. We then try to shrink it from the left by advancing the `left` pointer and updating our counts and `have`. We record the minimum window size seen.
Why it works: The sliding window explores all valid substrings efficiently without checking every possible substring from scratch, leading to an O(N) solution.
Complexity Analysis:

Time Complexity: O(m + n) where m is the length of s and n is the length of t. The right pointer moves m times, and the left pointer moves at most m times.
Space Complexity: O(C) where C is the size of the character set (e.g., 52 for uppercase and lowercase letters). The hash maps only store unique characters.
=========================================================
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Use frequency maps and a sliding window.
    // Expand window until it's valid, then shrink to find minimum.
    string minWindow(string s, string t) {
        if (t.empty() || s.length() < t.length()) return "";

        unordered_map<char, int> tCount, window;
        for (char c : t) {
            tCount[c]++;
        }

        int have = 0, need = tCount.size();
        int resLen = -1, resStart = -1;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            window[c]++;

            // If the current character is in t and its count in window matches tCount
            if (tCount.count(c) && window[c] == tCount[c]) {
                have++;
            }

            // While the window is valid, try to shrink it
            while (have == need) {
                // Update result if it's the minimum so far
                if (resLen == -1 || (right - left + 1) < resLen) {
                    resLen = right - left + 1;
                    resStart = left;
                }

                // Shrink from the left
                char leftChar = s[left];
                window[leftChar]--;
                
                // If a required character falls below its necessary count, window becomes invalid
                if (tCount.count(leftChar) && window[leftChar] < tCount[leftChar]) {
                    have--;
                }
                left++;
            }
        }

        return resLen == -1 ? "" : s.substr(resStart, resLen);
    }
};

int main() {

    // Sample test case
    Solution obj;
    string s = "ADOBECODEBANC";
    string t = "ABC";

    // Execute solution
    string result = obj.minWindow(s, t);
    
    cout << "Minimum Window Substring: " << result << endl;

    return 0;
}
