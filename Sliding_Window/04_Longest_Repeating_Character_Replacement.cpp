/*
=========================================================
Problem: Longest Repeating Character Replacement
Difficulty: Medium
Pattern: Sliding Window
LeetCode: #424

Problem Statement:
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Intuition: A valid window is one where `(length of window) - (count of most frequent character in window) <= k`. This means the number of characters we need to change is at most `k`.
Approach: Use a sliding window with `left` and `right` pointers. Maintain an array for character counts and a `maxFreq` variable representing the frequency of the most common character in the current window. Expand the right pointer. If the window becomes invalid (`right - left + 1 - maxFreq > k`), shrink it by advancing the `left` pointer and decrementing the count of the character leaving the window. The maximum valid window size seen is our answer.
Why it works: By keeping track of the most frequent character, we know how many replacements are needed to make all characters in the window the same. If the required replacements exceed `k`, we simply slide the left edge of the window.
Complexity Analysis:

Time Complexity: O(N) where N is the length of string s. The `right` and `left` pointers move linearly. We update `maxFreq` without re-scanning the counts array.
Space Complexity: O(1) as we only use an array of size 26 for counting character frequencies.
=========================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Use a sliding window and track the most frequent character.
    // If the window size minus max frequency > k, it's invalid, so shrink it.
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxFreq = 0;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // If the window is invalid, shrink from left
            // Note: We don't strictly need a 'while' loop here. An 'if' works 
            // because the window size only needs to stay the same or grow.
            if ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {

    // Sample test case
    Solution obj;
    string s = "AABABBA";
    int k = 1;

    // Execute solution
    int result = obj.characterReplacement(s, k);
    
    cout << "Longest Repeating Character Replacement: " << result << endl;

    return 0;
}
