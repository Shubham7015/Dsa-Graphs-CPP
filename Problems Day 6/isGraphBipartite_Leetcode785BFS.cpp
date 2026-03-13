#include<bits/stdc++.h>
using namespace std ;

// Class to solve the bipartite graph problem using BFS
class Solution {
private:
    // Helper function to check if the component containing 'node' is bipartite
    bool check(int node, vector<int>& color, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(node);
        color[node] = 0; // Start coloring the node with color 0

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Traverse all adjacent nodes
            for (int it : graph[node]) {

                // If the adjacent node is not colored, color it with opposite color
                if (color[it] == -1) {
                    q.push(it);
                    color[it] = !color[node];
                }
                // If the adjacent node has the same color, graph is not bipartite
                else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true; // Component is bipartite
    }

public:
    // Main function to check if the entire graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1); // Initialize all nodes as uncolored

        // Check each component of the graph
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // If node is not colored
                if (check(i, color, graph) == false)
                    return false; // If any component is not bipartite
            }
        }
        return true; // All components are bipartite
    }
};

int main() {
    // Example graph: 4 nodes, edges between 0-1, 0-3, 1-2, 2-3
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}} ;
    Solution sol ;

    cout<< sol.isBipartite(graph) ; // Output: 1 (true)
}