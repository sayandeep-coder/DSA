/*
=========================================================
Problem: Insert Interval
Difficulty: Medium
Pattern: Intervals
LeetCode: #57

Problem Statement:
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.

Example:

Input:
intervals = [[1,3],[6,9]], newInterval = [2,5]

Output:
[[1,5],[6,9]]

Explanation:
Intuition: Since the intervals are already sorted, we can iterate through them and find exactly where the new interval should be placed, merging as needed.
Approach: We break the problem into three phases. 
1. Add all intervals ending before the new interval starts. 
2. Merge all overlapping intervals. An interval overlaps with the new interval if its start time is <= the new interval's end time. Update the new interval's start and end times to cover the merged range.
3. Add all remaining intervals.
Why it works: By handling non-overlapping left intervals, then merging all overlapping ones, and finally adding non-overlapping right intervals, we build the resulting list in O(N) time without needing to resort.
Complexity Analysis:

Time Complexity: O(N) where N is the number of intervals. We traverse the list exactly once.
Space Complexity: O(N) to store the result, though auxiliary space is O(1) if we don't count the output array.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Iterate and partition the problem into: before overlap, merging overlap, after overlap.
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        // 1. Add all intervals coming before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        // 2. Merge all overlapping intervals into newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Add the merged interval
        result.push_back(newInterval);
        
        // 3. Add all remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    // Execute solution
    vector<vector<int>> result = obj.insert(intervals, newInterval);
    
    cout << "Inserted Intervals: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
