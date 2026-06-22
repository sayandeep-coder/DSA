/*
=========================================================
Problem: Word Break
Difficulty: Medium
Pattern: Dynamic Programming
LeetCode: #139

Problem Statement:
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example:

Input:
s = "leetcode", wordDict = ["leet","code"]

Output:
true

Explanation:
Intuition: If a string up to index `j` can be broken down into dictionary words, and the substring from `j` to `i` is also a dictionary word, then the string up to index `i` can be broken down into dictionary words.
Approach: We can use a 1D DP array of booleans `dp` where `dp[i]` is true if the substring `s[0...i-1]` (length `i`) can be segmented. Initialize `dp[0] = true` (empty string). Iterate `i` from 1 to `s.length()`. For each `i`, iterate `j` from 0 to `i-1`. If `dp[j]` is true AND the substring `s[j...i-1]` is in the dictionary, then set `dp[i] = true` and break the inner loop (since we just need one valid segmentation to reach `i`). Return `dp[s.length()]`.
Why it works: This dynamically builds upon smaller successful segmentations. If we know a prefix is valid, we just need to check if the remaining suffix is a valid word.
Complexity Analysis:

Time Complexity: O(N^3) where N is the length of the string. The nested loops take O(N^2), and extracting the substring takes O(N). (Can be optimized to O(N^2 * M) where M is max word length).
Space Complexity: O(N) for the DP array of size `N + 1`. Also O(W) where W is the total characters in the dictionary if we convert it to a Hash Set for O(1) lookups.
=========================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // dp[i] is true if s[0...i-1] can be segmented into dictionary words.
    // Check all prefixes j. If dp[j] is true and s[j...i-1] is a word, dp[i] becomes true.
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        
        dp[0] = true; // Base case: empty string
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                // If substring up to j is valid, and j to i is in dictionary
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break; // No need to check other j's for this i
                }
            }
        }
        
        return dp[s.length()];
    }
};

int main() {

    // Sample test case
    Solution obj;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    // Execute solution
    bool result = obj.wordBreak(s, wordDict);
    
    cout << "Word Break possible: " << (result ? "true" : "false") << endl;

    return 0;
}
