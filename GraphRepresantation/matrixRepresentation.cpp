#include<bits/stdc++.h>

using namespace std ;

int main() {
    // represantation of undirected graph using matrix 

    //2D vector to store edges b/w nodes 

    //1-2 1-3 2-4 3-4 3-5 4-5 
    // n = 5 here so we need n+1 space to store this because nodes are starting from 1 not from 0 

    int n,m ;
    cin >> n >> m ; 

    vector<vector<int>> adjacencyMatrix(n+1,vector<int>(m+1,0)) ; // graph will stored here if adj[1][2] = 1 means there is edge between 1 and 2 as well as 2 and 1 ;
    // int adj[n+1][n+1] ;

    for(int i = 0 ; i < m ; i++){ // O(n) // s.c O(n^2)
        int u , v ; 
        cin >> u >> v ;
        adjacencyMatrix[u][v] = 1 ;
        adjacencyMatrix[v][u] = 1 ;

    }



    // weighted graph 

    for(int i = 0 ; i < m ; i++){ // O(n) // s.c O(n^2)
        int u , v , wt ;
        cin >> u >> v >> wt ;
        adjacencyMatrix[u][v] = wt ;
        adjacencyMatrix[v][u] = wt;

    }


}