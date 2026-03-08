#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool detect(int node , int parentnode , vector<vector<int>>&adj , vector<int>&visited) {
        visited[node] = 1 ; // mark the visit 
        
        for(auto &adjacentnode : adj[node]){
           if(!visited[adjacentnode]) {
                if(detect(adjacentnode,node,adj,visited))  return true ; 
            }
            // if already visited and parent node is not adjacent node then cycle                 
            else if(parentnode != adjacentnode) return true ;
        }
        return false ;
    }
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
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
                if (detect(i,-1, adj, visited)) // 0,-1 , node , parent 
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
