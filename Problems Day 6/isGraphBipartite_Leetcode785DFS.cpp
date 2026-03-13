#include<bits/stdc++.h>
using namespace std ;

class Solution {
    private:
    bool check(int node , int col, vector<int>&color , vector<vector<int>>&adj) {
        color[node] = col ; 
        
        for(int it : adj[node]) {
            if(color[it] == -1) {
                if(check(it,!col,color,adj) == false) return false ;
            }
            else if(color[it] == col) return false ;
        }
        return true ;
    }
  public:
    bool isBipartite(int n, vector<vector<int>> &edges) {
         vector<vector<int>> adj(n) ;
         
         for(auto e  :edges){
             adj[e[0]].push_back(e[1]) ;
             adj[e[1]].push_back(e[0]) ;
         }
        vector<int>color(n,-1) ;
        
        for(int i = 0; i < n ; i++) {
            if(color[i] == -1){
                if(check(i,0,color,adj) == false) return false ;
            }
        }
        return true ;
        
    }
};

int main() {
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}} ;
    int n = graph.size() ;
    Solution sol ;

    cout<< sol.isBipartite(n,graph) ;
}