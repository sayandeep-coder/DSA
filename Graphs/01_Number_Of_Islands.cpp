/*
=========================================================
Problem: Number of Islands
Difficulty: Medium
Pattern: Graph / BFS / DFS
LeetCode: #200

Problem Statement:
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Input:
grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

Output:
3

Explanation:
Intuition: We can think of the grid as a graph where each '1' is a node and edges exist between horizontally or vertically adjacent '1's. The number of islands is simply the number of connected components in this graph.
Approach: Iterate through every cell in the grid. When we find a '1', we increment our island count and then perform a Depth-First Search (DFS) or Breadth-First Search (BFS) to find all connected '1's that form this island. During the traversal, we mark visited '1's as '0' (or another character) so we don't count them again. 
Why it works: Exploring all reachable land from an unvisited '1' correctly maps out the entire island. Marking them as visited prevents redundant traversals and infinite loops.
Complexity Analysis:

Time Complexity: O(M * N) where M is the number of rows and N is the number of columns. We visit every cell in the grid.
Space Complexity: O(M * N) in the worst case for the DFS recursion stack if the entire grid is filled with '1's.
=========================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Check for out of bounds or if it's water ('0')
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }

        // Mark the current land as visited by changing it to '0'
        grid[r][c] = '0';

        // Traverse all 4 adjacent directions
        dfs(grid, r - 1, c); // up
        dfs(grid, r + 1, c); // down
        dfs(grid, r, c - 1); // left
        dfs(grid, r, c + 1); // right
    }

public:
    // Detailed explanation comments
    // Iterate through grid. When a '1' is found, increment island count.
    // Use DFS to mark the entire island as visited ('0').
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    islands++;
                    dfs(grid, r, c); // Sink the island
                }
            }
        }

        return islands;
    }
};

int main() {

    // Sample test case
    Solution obj;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    // Execute solution
    int result = obj.numIslands(grid);
    
    cout << "Number of Islands: " << result << endl;

    return 0;
}
