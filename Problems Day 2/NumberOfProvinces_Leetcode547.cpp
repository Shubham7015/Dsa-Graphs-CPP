#include <bits/stdc++.h>
using namespace std ;

class Solution
{
private:
    void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj)
    {    // dfs
        visited[node] = true; // visit the node

        for (auto &e : adj[node])
        { // iterate on current node list
            if (!visited[e])
                dfs(e, visited, adj); // not visited till apply dfs on current [e]  of adj[node]
        }
    }

public:
    int numProvinces(vector<vector<int>> &nums)
    {
        int n = nums.size();

        vector<vector<int>> adj(n, vector<int>(n)); // to store adjacency list

        // make adjacency list
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[i][j] == 1 && i != j)
                { // if [i][j] == 1 and i&j are not equal only then make push to list
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false); // visted array

        int provinces = 0; // total provinces(total no. of components (connected and not connected ))

        for (int i = 0; i < n; i++)
        { // iterate on all components
            if (!visited[i])
            {                         // if not viisted till now
                dfs(i, visited, adj); // apply dfs
                provinces++;          // increase no. of provinces
            }
        }

        return provinces; // return provinces
    }
};


int main() {
    // Adjacency matrix input
    vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };


    // Create object of Solution
    Solution obj;

    // Call the function and print result
    cout << obj.numProvinces(adj) << endl;

    return 0;
}