/*
=========================================================
Problem: Rotting Oranges
Difficulty: Medium
Pattern: Graph / Multi-source BFS
LeetCode: #994

Problem Statement:
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example:

Input:
grid = [[2,1,1],[1,1,0],[0,1,1]]

Output:
4

Explanation:
Intuition: The rotting process spreads outward simultaneously from all initially rotten oranges. This simultaneous spreading is best modeled by a Breadth-First Search (BFS) starting from multiple sources.
Approach: We first iterate through the grid to count the number of fresh oranges and push the coordinates of all initially rotten oranges into a queue. We then start a BFS. In each "minute" (level of BFS), we pop all currently rotten oranges and rot their adjacent fresh oranges, pushing the newly rotten oranges into the queue and decrementing the fresh orange count. We keep track of the minutes passed. If the queue is empty and there are still fresh oranges left, we return -1.
Why it works: BFS guarantees that we find the shortest path (minimum time) for the rot to reach every reachable fresh orange. Using a multi-source queue ensures that rot spreads concurrently.
Complexity Analysis:

Time Complexity: O(M * N) where M is rows and N is cols. We visit each cell at most a few times.
Space Complexity: O(M * N) for the queue in the worst case (if all oranges are initially rotten).
=========================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Multi-source BFS. Put all rotten oranges in queue initially.
    // Spread rot level by level (minute by minute).
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int, int>> q;
        int freshCount = 0;
        
        // Find all initial rotten oranges and count fresh oranges
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }
        
        if (freshCount == 0) return 0; // No fresh oranges to begin with
        
        int minutes = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // BFS
        while (!q.empty()) {
            int levelSize = q.size();
            bool rottenThisMinute = false;
            
            for (int i = 0; i < levelSize; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                // Check all 4 adjacent directions
                for (auto dir : dirs) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;
                    
                    // If neighbor is in bounds and is a fresh orange
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Rot it
                        freshCount--;
                        q.push({nr, nc});
                        rottenThisMinute = true;
                    }
                }
            }
            if (rottenThisMinute) minutes++;
        }
        
        return freshCount == 0 ? minutes : -1;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    // Execute solution
    int result = obj.orangesRotting(grid);
    
    cout << "Minutes until all oranges rot: " << result << endl;

    return 0;
}
