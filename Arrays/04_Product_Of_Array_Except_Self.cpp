/*
=========================================================
Problem: Product of Array Except Self
Difficulty: Medium
Pattern: Prefix & Suffix Arrays / Prefix Sum
LeetCode: #238

Problem Statement:
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example:

Input:
nums = [1,2,3,4]

Output:
[24,12,8,6]

Explanation:
Intuition: Since we cannot use division, we can compute the product of all elements to the left of each index, and the product of all elements to the right. Multiplying these two gives the answer for each index.
Approach: Instead of using two extra arrays for prefix and suffix products, we can use the result array. First, traverse from left to right, accumulating the prefix products in the result array. Then, traverse from right to left, maintaining a running suffix product and multiplying it with the values in the result array.
Why it works: For any element at index `i`, its result must be `(product of elements from 0 to i-1) * (product of elements from i+1 to n-1)`. Our two passes calculate exactly this without redundant multiplications.
Complexity Analysis:

Time Complexity: O(N) where N is the number of elements in the array. We make two passes over the array.
Space Complexity: O(1) extra space (excluding the output array). The output array does not count as extra space for complexity analysis.
=========================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // We compute prefix products first and store them in the answer array
    // Then we traverse backwards, computing the postfix product on the fly
    // and multiplying it with the prefix product to get the final answer.
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        // Compute prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        
        // Compute postfix products and multiply with prefix
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }
        
        return ans;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<int> nums = {1, 2, 3, 4};

    // Execute solution
    vector<int> result = obj.productExceptSelf(nums);
    
    cout << "Product Array: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
