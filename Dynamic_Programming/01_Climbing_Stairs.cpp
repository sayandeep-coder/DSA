/*
=========================================================
Problem: Climbing Stairs
Difficulty: Easy
Pattern: Dynamic Programming / Fibonacci
LeetCode: #70

Problem Statement:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example:

Input:
n = 3

Output:
3

Explanation:
Intuition: To reach step `n`, you could only have come from step `n-1` (by taking 1 step) or step `n-2` (by taking 2 steps). Therefore, the total number of ways to reach step `n` is the sum of the ways to reach `n-1` and `n-2`.
Approach: This is a classic Fibonacci sequence problem: `dp[i] = dp[i-1] + dp[i-2]`. Instead of using an array of size `n` which would take O(N) space, we can just keep track of the previous two values (`oneStepBefore` and `twoStepsBefore`). We iteratively compute the current value and update our variables up to `n`.
Why it works: It builds the solution optimally from the bottom up, avoiding the exponential overlapping subproblems that a pure recursive approach would suffer from.
Complexity Analysis:

Time Complexity: O(N) since we calculate the number of ways iteratively up to n.
Space Complexity: O(1) as we only use two integer variables.
=========================================================
*/

#include <iostream>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // The number of ways to reach step i is ways(i-1) + ways(i-2).
    // We optimize space by only storing the last two values.
    int climbStairs(int n) {
        if (n <= 3) return n;

        int twoStepsBefore = 2; // ways to reach step 2
        int oneStepBefore = 3;  // ways to reach step 3
        int currentWays = 0;

        for (int i = 4; i <= n; i++) {
            currentWays = oneStepBefore + twoStepsBefore;
            twoStepsBefore = oneStepBefore;
            oneStepBefore = currentWays;
        }

        return currentWays;
    }
};

int main() {

    // Sample test case
    Solution obj;
    int n = 5;

    // Execute solution
    int result = obj.climbStairs(n);
    
    cout << "Distinct ways to climb " << n << " stairs: " << result << endl;

    return 0;
}
