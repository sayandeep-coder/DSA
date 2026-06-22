/*
=========================================================
Problem: Valid Palindrome
Difficulty: Easy
Pattern: Two Pointers
LeetCode: #125

Problem Statement:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example:

Input:
s = "A man, a plan, a canal: Panama"

Output:
true

Explanation:
Intuition: A palindrome reads the same forwards and backwards. We can use two pointers, one starting from the beginning and one from the end, to compare characters. We should ignore non-alphanumeric characters and case.
Approach: Initialize a `left` pointer to 0 and a `right` pointer to the end of the string. While `left < right`, skip any non-alphanumeric characters by advancing `left` or decrementing `right`. Then, compare the characters at `left` and `right` (converted to lowercase). If they don't match, return `false`. Otherwise, move both pointers inward. If the loop finishes, return `true`.
Why it works: Two pointers allow checking for symmetry efficiently in a single pass without allocating extra memory for a cleaned string.
Complexity Analysis:

Time Complexity: O(N) where N is the length of the string. Each character is visited at most once.
Space Complexity: O(1) since we only use two integer pointers.
=========================================================
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Use two pointers starting from both ends.
    // Skip non-alphanumeric characters and compare in lowercase.
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Move left pointer to next alphanumeric char
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right pointer to previous alphanumeric char
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters ignoring case
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {

    // Sample test case
    Solution obj;
    string s = "A man, a plan, a canal: Panama";

    // Execute solution
    bool result = obj.isPalindrome(s);
    
    cout << "Is Valid Palindrome: " << (result ? "true" : "false") << endl;

    return 0;
}
