/*
=========================================================
Problem: Pacific Atlantic Water Flow
Difficulty: Medium
Pattern: Graph / BFS / DFS
LeetCode: #417

Problem Statement:
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example:

Input:
heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]

Output:
[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

Explanation:
Intuition: Instead of starting from every cell and checking if water can reach both oceans (which is redundant), we can work backwards. We start from the ocean shores and see which cells water can flow *up* to. 
Approach: Maintain two boolean matrices `pac` and `atl` to track cells reachable from the Pacific and Atlantic respectively. Run a DFS or BFS starting from all cells adjacent to the Pacific Ocean (top and left edges), marking reachable cells in `pac`. Water flows "up" if the neighbor's height is >= the current cell's height. Repeat the same process from the Atlantic Ocean (bottom and right edges), marking reachable cells in `atl`. Finally, iterate through the grid and find all cells that are `true` in both `pac` and `atl`.
Why it works: Working backwards from the goals (the oceans) prevents recalculating reachability for every internal cell independently.
Complexity Analysis:

Time Complexity: O(M * N) where M is rows and N is cols. We visit each cell a constant number of times.
Space Complexity: O(M * N) for the `pac` and `atl` matrices and the recursion stack.
=========================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c, int prevHeight) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        // Out of bounds, already visited, or water cannot flow up
        if (r < 0 || c < 0 || r >= rows || c >= cols || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }
        
        visited[r][c] = true;
        
        dfs(heights, visited, r + 1, c, heights[r][c]); // down
        dfs(heights, visited, r - 1, c, heights[r][c]); // up
        dfs(heights, visited, r, c + 1, heights[r][c]); // right
        dfs(heights, visited, r, c - 1, heights[r][c]); // left
    }

public:
    // Detailed explanation comments
    // Start DFS from the borders.
    // Find intersection of cells reachable from Pacific and Atlantic.
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        if (heights.empty() || heights[0].empty()) return res;
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));
        
        // DFS from left (Pacific) and right (Atlantic) edges
        for (int r = 0; r < rows; r++) {
            dfs(heights, pac, r, 0, heights[r][0]);
            dfs(heights, atl, r, cols - 1, heights[r][cols - 1]);
        }
        
        // DFS from top (Pacific) and bottom (Atlantic) edges
        for (int c = 0; c < cols; c++) {
            dfs(heights, pac, 0, c, heights[0][c]);
            dfs(heights, atl, rows - 1, c, heights[rows - 1][c]);
        }
        
        // Find intersection
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        
        return res;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    // Execute solution
    vector<vector<int>> result = obj.pacificAtlantic(heights);
    
    cout << "Cells that can flow to both oceans: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
