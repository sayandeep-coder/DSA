/*
=========================================================
Problem: Merge Intervals
Difficulty: Medium
Pattern: Sorting / Intervals
LeetCode: #56

Problem Statement:
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example:

Input:
intervals = [[1,3],[2,6],[8,10],[15,18]]

Output:
[[1,6],[8,10],[15,18]]

Explanation:
Intuition: If we sort the intervals by their start times, overlapping intervals will be adjacent to each other. We can then iterate through the sorted list and merge them one by one.
Approach: First, sort the array based on the start time of each interval. Create an empty `merged` array. Iterate through the intervals. If `merged` is empty or the last interval in `merged` does not overlap with the current interval, add the current interval to `merged`. Otherwise, if they overlap, merge them by updating the end time of the last interval in `merged` to the maximum of its end time and the current interval's end time.
Why it works: Sorting ensures that any interval that could potentially overlap with the current one must appear immediately after it. We only need to compare with the last merged interval.
Complexity Analysis:

Time Complexity: O(N log N) where N is the number of intervals. Sorting takes O(N log N), and merging takes O(N). Overall time is dominated by sorting.
Space Complexity: O(log N) or O(N) depending on the sorting algorithm used by the language (C++ std::sort uses O(log N)). The space used for the output array doesn't count towards auxiliary space.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Sort intervals by start time to make merging easier.
    // Compare the current interval with the last merged interval and merge if they overlap.
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals by their start times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // Get the last interval in our merged list
            vector<int>& lastMerged = merged.back();

            // Check if there is an overlap (start of current <= end of last merged)
            if (intervals[i][0] <= lastMerged[1]) {
                // Merge by taking the maximum end time
                lastMerged[1] = max(lastMerged[1], intervals[i][1]);
            } else {
                // No overlap, add the current interval
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Execute solution
    vector<vector<int>> result = obj.merge(intervals);
    
    cout << "Merged Intervals: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
