/*
=========================================================
Problem: Permutation in String
Difficulty: Medium
Pattern: Sliding Window / Hash Map
LeetCode: #567

Problem Statement:
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example:

Input:
s1 = "ab", s2 = "eidbaooo"

Output:
true

Explanation:
Intuition: A permutation of a string means it has the exact same character frequencies. So, we are looking for a substring in `s2` of length `s1.length()` that has the same character frequencies as `s1`.
Approach: We can use a fixed-size sliding window of length `s1.length()` over `s2`. We maintain frequency arrays (or maps) for both `s1` and the current window in `s2`. As we slide the window one character at a time, we add the new character to the window's frequency array and remove the old character that fell out of the window. We compare the frequency arrays to check if they match.
Why it works: Comparing two arrays of size 26 (for lowercase letters) takes O(1) time. By using a sliding window, we update the frequency map incrementally rather than recounting characters from scratch for every substring.
Complexity Analysis:

Time Complexity: O(N) where N is the length of s2. We iterate through s2 once, and array comparisons take constant time.
Space Complexity: O(1) since we use fixed-size arrays of length 26 to store character counts.
=========================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Use an array of size 26 to track character frequencies.
    // Slide a window of size s1.length() over s2.
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        // Initialize frequencies for the first window
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) {
                matches++;
            }
        }

        // Slide the window
        for (int i = s1.length(); i < s2.length(); i++) {
            if (matches == 26) return true;

            // Character added to window
            int right = s2[i] - 'a';
            s2Count[right]++;
            if (s2Count[right] == s1Count[right]) {
                matches++;
            } else if (s2Count[right] == s1Count[right] + 1) {
                matches--;
            }

            // Character removed from window
            int left = s2[i - s1.length()] - 'a';
            s2Count[left]--;
            if (s2Count[left] == s1Count[left]) {
                matches++;
            } else if (s2Count[left] == s1Count[left] - 1) {
                matches--;
            }
        }

        return matches == 26;
    }
};

int main() {

    // Sample test case
    Solution obj;
    string s1 = "ab";
    string s2 = "eidbaooo";

    // Execute solution
    bool isPermutation = obj.checkInclusion(s1, s2);
    
    cout << "Permutation exists: " << (isPermutation ? "true" : "false") << endl;

    return 0;
}
