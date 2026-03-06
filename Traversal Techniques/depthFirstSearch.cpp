#include <bits/stdc++.h>
using namespace std;

void dfs(int node , vector<vector<int>>&adj , vector<int>& visited , vector<int>&ans) { // TC O(N) + (2E)  for undirected graph  and O(N) + O(E) for directed one 
    visited[node] = 1 ; 
    ans.push_back(node) ;

    for(auto it : adj[node]) {
        if(!visited[it]){
            dfs(it,adj,visited,ans);
        }
    }
}
int main() {
   
    vector<vector<int>> adj = {{}, {2,3}, {1,5,6}, {1,4,7}, {3,8},{2},{2},{3,8},{4,7}}; // adjacency list representation of the graph
    vector<int>visited(adj.size(),0) ;//O(N)

     // to keep track of visited nodes 

     int start = 1 ;

    vector<int>ans ;//O(N)
     dfs(start,adj,visited,ans) ;

     for(auto it : ans){
        cout << it << "->" ; 
     }

     //S.C = O(n)





    
}
