#include <bits/stdc++.h>
using namespace std;

vector<int> fun(int n, vector<vector<int>> &edges)
{

    // Create adjacency list from edge list
    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    // Vector to keep track of visited nodes
    vector<int> visited(n, 0);
    vector<int> ans;
  

    

    for (int i = 0; i < n; i++) // for traversing all the unconnected components 
    {
        if (!visited[i]) // if never seen this yet
        {
            queue<int> q ;
            q.push(i) ;// push to queue
            visited[i] = 1 ; // mark 

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                ans.push_back(node);// push to ans 

                for (auto it : adj[node]) // traverse in the  adj[node]
                {
                    if (!visited[it]) //  if not visted yet 
                    {
                        visited[it] = 1; // mark it 
                        q.push(it);// push to queue
                    }
                }
            }
        }
    }

    return ans;
}

int main()
{
    // Number of vertices
    int V = 5;

    // List of undirected edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};

    vector<int> adj = fun(V, edges);

    for (int i = 0; i < adj.size(); i++)
    {
        cout << adj[i] << "->";
    }

    return 0;
}
