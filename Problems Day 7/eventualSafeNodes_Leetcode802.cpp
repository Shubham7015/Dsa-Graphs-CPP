#include<bits/stdc++.h>
using namespace std ;

// Solution class to find all eventual safe nodes in a directed graph
class Solution {
private:
    // Helper DFS function to detect cycles and mark safe nodes
    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited,
             vector<int>& count, vector<vector<int>>& adj) {
        // Mark the current node as visited and part of the current path
        pathVisited[node] = 1;
        visited[node] = 1;
        count[node] = 0; // Assume not safe initially

        // Traverse all adjacent nodes
        for (int it : adj[node]) {
            // If the adjacent node is not visited, recurse
            if (!visited[it]) {
                if (dfs(it, visited, pathVisited, count, adj)) {
                    count[it] = 0; // Not safe if cycle found
                    return true;   // Cycle detected
                }
            }
            // If the adjacent node is visited and also in the current path, cycle detected
            else if (pathVisited[it]) {
                count[it] = 0; // Not safe
                return true;   // Cycle detected
            }
        }

        // Backtrack: remove the node from the current path
        pathVisited[node] = 0;
        count[node] = 1; // Mark as safe
        return false;    // No cycle found
    }

public:
    // Main function to return all eventual safe nodes
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size(); // Number of nodes

        vector<int> visited(V, 0);      // Track visited nodes
        vector<int> pathVisited(V, 0);  // Track nodes in the current DFS path
        vector<int> count(V, 0);        // Mark safe nodes

        // Run DFS for all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, pathVisited, count, adj);
            }
        }

        vector<int> ans;
        // Collect all nodes marked as safe
        for (int i = 0; i < V; i++) {
            if (count[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
   // Example graph: each index represents a node, and the vector at that index represents its neighbors
   vector<vector<int>> graph= {{1,2},{2,3},{5},{0},{5},{},{}};
   Solution sol ;

   // Get all eventual safe nodes
   vector<int> ans = sol.eventualSafeNodes(graph) ;

   // Print the safe nodes
   for(int it : ans){
    cout<< it << endl ;
   }
}