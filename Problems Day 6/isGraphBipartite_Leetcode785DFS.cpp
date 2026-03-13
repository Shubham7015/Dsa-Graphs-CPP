#include<bits/stdc++.h>
using namespace std ;

class Solution {
    private:
    bool check(int node , int col, vector<int>&color , vector<vector<int>>&adj) {
        color[node] = !col ; // color it with oppose color from adjacent node 
        
        for(int it : adj[node]) {
            if(color[it] == -1) { // if not coloured till now coloured it 
                if(check(it,col,color,adj) == false) return false ; // if it is false return false 
            }
            else if(color[it] == col) return false ;// if adjacent node color and current node color is same means not a bipartite graph so return false here also 
        
        }
        return true ; // if satisfies all the condition return true ;
    }
  public:
    bool isBipartite(int n, vector<vector<int>> &edges) {
         vector<vector<int>> adj(n) ; 
         
         for(auto e  :edges){// make adjacency list 
             adj[e[0]].push_back(e[1]) ;
             adj[e[1]].push_back(e[0]) ;
         }

        vector<int>color(n,-1) ;// for coloring the nodes or vertices or checking if it is coloured or not 
        
        for(int i = 0; i < n ; i++) { // for checking all the components either connected or not connected 
            if(color[i] == -1){// if not coloured till now 
                if(check(i,0,color,adj) == false) return false ; // if it return false not a bipartite graph
            }
        }
        return true ; // return true bipartite graph 
        
    }
};

int main() {
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}} ;
    int n = graph.size() ;
    Solution sol ;

    cout<< sol.isBipartite(n,graph) ;
}