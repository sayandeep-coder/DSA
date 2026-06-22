/*
=========================================================
Problem: Course Schedule
Difficulty: Medium
Pattern: Graph / Topological Sort (Kahn's Algorithm)
LeetCode: #207

Problem Statement:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
Return true if you can finish all courses. Otherwise, return false.

Example:

Input:
numCourses = 2, prerequisites = [[1,0]]

Output:
true

Explanation:
Intuition: This problem is a classic example of detecting a cycle in a directed graph. The courses are nodes, and the prerequisites are directed edges (e.g., `bi -> ai`). If there is a cycle, we can't complete the courses.
Approach: We can use Topological Sorting via Kahn's Algorithm (BFS). We construct an adjacency list to represent the graph and an `inDegree` array to track the number of prerequisites for each course. We enqueue all courses with `inDegree == 0` (no prerequisites). Then, we repeatedly dequeue a course, increment our count of completed courses, and reduce the `inDegree` of its neighbors. If a neighbor's `inDegree` becomes 0, we enqueue it. Finally, if the count of completed courses equals `numCourses`, there's no cycle, and we return true.
Why it works: Kahn's Algorithm peels off nodes with no dependencies. If the graph is a Directed Acyclic Graph (DAG), it will successfully peel off all nodes. If there is a cycle, the nodes in the cycle will never reach an `inDegree` of 0, so they won't be processed.
Complexity Analysis:

Time Complexity: O(V + E) where V is `numCourses` and E is the length of `prerequisites`. We build the graph and traverse each node and edge once.
Space Complexity: O(V + E) to store the adjacency list and the `inDegree` array.
=========================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    // Detailed explanation comments
    // Use Kahn's algorithm for Topological Sort.
    // If we process all nodes, there is no cycle.
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Build the adjacency list and in-degree array
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        // Queue for courses with no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int completedCount = 0;

        // BFS traversal
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCount++;

            // Reduce in-degree of neighbors
            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return completedCount == numCourses;
    }
};

int main() {

    // Sample test case
    Solution obj;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};

    // Execute solution
    bool result = obj.canFinish(numCourses, prerequisites);
    
    cout << "Can Finish Courses: " << (result ? "true" : "false") << endl;

    return 0;
}
