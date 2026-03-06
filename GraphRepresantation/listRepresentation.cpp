#include<bits/stdc++.h>

using namespace std ;

int main() {
    // represantation of undirected graph using adjacency list 

    //list  to store edges b/w nodes 

    //1-2 1-3 2-4 3-4 3-5 4-5 
    // n = 5 here so we need n+1 space to store this because nodes are starting from 1 not from 0 

    int n,m ;
    cin >> n >> m ; 



    vector<int>adj[n+1] ; // s.c = O(2E) and in undirected graph is O(E)
    // 0 = {} , 1 = {} , 2 = {} , 3 = {} , 4 = {} , 5 = { }

    for(int i = 0 ; i < m ; i++) { // O(n)
        int u , v ;
        cin >> u >> v  ;
        // in directed graph u--> v only not v -> u  
        // adj[u].push_back(v) ;

        // in undirected graph 
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;

    }


    // weighted graph

    // store pair of edge and wt 

    vector<pair<int,int>> adja[n+1] ;

    for(int i = 0 ; i < m ; i++) { // O(n)
        int u , v , wt ;
        cin >> u >> v >> wt ;
        // in directed graph u--> v only not v -> u  
        // adj[u].push_back(v) ;

        // in undirected graph 
        adja[u].push_back({v,wt}) ;
        adja[v].push_back({u,wt}) ;

    }

}