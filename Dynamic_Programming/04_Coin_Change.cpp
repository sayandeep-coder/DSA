/*
=========================================================
Problem: Coin Change
Difficulty: Medium
Pattern: Dynamic Programming (Bottom-Up Unbounded Knapsack)
LeetCode: #322

Problem Statement:
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example:

Input:
coins = [1,2,5], amount = 11

Output:
3

Explanation:
Intuition: This is an unbounded knapsack problem. To find the minimum coins for an `amount`, we can try subtracting each coin denomination from it, and see what the minimum coins needed for the remainder is. `min_coins(amount) = 1 + min(min_coins(amount - coin_i))` for all coins.
Approach: We use a bottom-up Dynamic Programming array `dp` where `dp[i]` represents the minimum number of coins needed to make amount `i`. Initialize `dp` with a value greater than any possible answer (like `amount + 1`) to signify "unreachable". Set `dp[0] = 0`. Iterate through all amounts `a` from 1 to `amount`. For each amount, iterate through all available `coins`. If `a - c >= 0`, we update `dp[a] = min(dp[a], 1 + dp[a - c])`. Finally, if `dp[amount]` is still `amount + 1`, return -1.
Why it works: By building from 0 up to `amount`, every subproblem required by a larger amount has already been optimally solved and stored in the DP array.
Complexity Analysis:

Time Complexity: O(A * C) where A is the amount and C is the number of coins. We run a nested loop of amounts and coins.
Space Complexity: O(A) where A is the amount, as we need a DP array of size `amount + 1`.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // dp[i] stores the min coins needed to make amount i.
    // Initialize with amount + 1 (an impossible high value).
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // 0 coins needed to make amount 0

        for (int a = 1; a <= amount; a++) {
            for (int c : coins) {
                // If the coin value is not greater than the current amount
                if (a - c >= 0) {
                    dp[a] = min(dp[a], 1 + dp[a - c]);
                }
            }
        }

        // If dp[amount] is still amount + 1, it means we couldn't make the amount
        return dp[amount] != amount + 1 ? dp[amount] : -1;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    // Execute solution
    int result = obj.coinChange(coins, amount);
    
    cout << "Fewest number of coins: " << result << endl;

    return 0;
}
