/*
=========================================================
Problem: Best Time to Buy and Sell Stock
Difficulty: Easy
Pattern: Sliding Window / Two Pointers
LeetCode: #121

Problem Statement:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example:

Input:
prices = [7,1,5,3,6,4]

Output:
5

Explanation:
Intuition: We want to buy at the lowest possible price and sell at the highest possible price afterwards. We can keep track of the minimum price seen so far and the maximum profit we can get by selling at the current price.
Approach: Initialize a `minPrice` variable to infinity and `maxProfit` to 0. Iterate through the array. Update `minPrice` if the current price is lower. Otherwise, calculate the profit if we sell today (`current price - minPrice`) and update `maxProfit` if this profit is greater than the previous `maxProfit`.
Why it works: By tracking the minimum price seen *before* the current day, we ensure we only consider valid buy-then-sell transactions. This elegantly tracks the largest difference between a smaller preceding number and a larger succeeding number.
Complexity Analysis:

Time Complexity: O(N) where N is the length of the prices array. We only iterate through the array once.
Space Complexity: O(1) since we only use two variables for tracking state.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Track the minimum price encountered so far
    // Track the maximum profit we can achieve by selling on the current day
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            // Update the minimum price if a lower price is found
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } 
            // Calculate profit if sold today and update maxProfit if it's higher
            else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
        
        return maxProfit;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Execute solution
    int profit = obj.maxProfit(prices);
    
    cout << "Maximum Profit: " << profit << endl;

    return 0;
}
