#include<bits/stdc++.h>
using namespace std ;
class Solution {
  private: 
  bool dfs(int node , vector<int>&visited , vector<int>&pathVisited , vector<vector<int>>&adj){
      // mark visited as well as path visited
      pathVisited[node] = 1 ;
      visited[node] = 1 ;
      
      for(int it  :adj[node]) {// iterate on vector[node]
        if(!visited[it]){// if not visited yet 
            if(dfs(it,visited,pathVisited,adj))
                return true ;
        }
        else if(pathVisited[it]) return true ; // if visited yet and pathvisited[it] means there is a cycle 
      }
      
      pathVisited[node] = 0 ; // set path visited = 0 
      return false ; // no cycle found 
  }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V) ;// adjacency list or vector
        
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);// directed graph
            
        }
        
        vector<int>visited(V,0) ;
        vector<int>pathVisited(V,0) ;
        
        for(int i = 0 ; i < V ; i++) {// for all the components
            if(!visited[i]) {
                if(dfs(i,visited,pathVisited,adj)) return true ;// if found true not check for further nodes or components
            }
        }
        return false ;// no cycle found 
    }
};
int main() {
    int  V = 4 ;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}} ;

    Solution sol ;
    cout<< sol.isCyclic(V,edges) ;
}