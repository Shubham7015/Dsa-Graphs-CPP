#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // BFS-based cycle detection for undirected graphs
    bool detect(int src, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[src] = 1;
        queue<pair<int, int>> q;  // pair of {node, parent}

        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Check all adjacent nodes
            for (auto &adjacentNode : adj[node])
            {
                if (!visited[adjacentNode])
                {
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // If visited and not parent, cycle exists
                else if (parent != adjacentNode)
                    return true;
            }
        }

        return false;
    }

public:
    // Check if cycle exists in undirected graph
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<int> visited(V, 0);

        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Check each unvisited component
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (detect(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    int V = 4, E = 4;
    vector<vector<int>> edges{{0, 1}, {0, 2}, {1, 2}, {2, 3}};

    Solution sol;

    bool ans = sol.isCycle(V, edges);
    cout << ans << endl;  // Output: 1 (cycle exists)

    return 0;
}
