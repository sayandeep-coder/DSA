/*
=========================================================
Problem: Meeting Rooms II
Difficulty: Medium
Pattern: Intervals / Two Pointers / Min-Heap
LeetCode: #253

Problem Statement:
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example:

Input:
intervals = [[0, 30],[5, 10],[15, 20]]

Output:
2

Explanation:
Intuition: The number of rooms needed at any point in time is determined by how many meetings are overlapping. If a meeting ends before another starts, we can reuse the room.
Approach: We extract the start times and end times into separate arrays and sort both. Using two pointers (one for start times, one for end times), we traverse the meetings chronologically. If a meeting starts before the earliest ending meeting finishes, we need an extra room. If a meeting starts after or exactly when a meeting finishes, we can free up a room (by advancing the end pointer).
Why it works: Sorting separates the timeline into start and end events. We process chronologically. Every start event increases room usage, every end event decreases it. Tracking the maximum concurrent rooms gives the answer.
Complexity Analysis:

Time Complexity: O(N log N) where N is the number of meetings, dominated by sorting the start and end times.
Space Complexity: O(N) for storing the separated start and end times arrays.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Separate starts and ends, sort them, then use two pointers.
    // Count max overlapping meetings.
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        int n = intervals.size();
        vector<int> starts(n);
        vector<int> ends(n);
        
        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int rooms = 0;
        int maxRooms = 0;
        int s = 0, e = 0;
        
        while (s < n) {
            // If the next meeting starts before the earliest ending meeting finishes
            if (starts[s] < ends[e]) {
                rooms++;
                s++;
                maxRooms = max(maxRooms, rooms);
            } 
            // If a meeting finishes, a room frees up
            else {
                rooms--;
                e++;
            }
        }
        
        return maxRooms;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};

    // Execute solution
    int minRooms = obj.minMeetingRooms(intervals);
    
    cout << "Minimum Meeting Rooms: " << minRooms << endl;

    return 0;
}
