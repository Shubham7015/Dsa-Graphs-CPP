#include<bits/stdc++.h>
using namespace std ;

class Solution {
private: 
    void dfs(int row , int col , vector<vector<int>> &visited , vector<vector<int>> &grid , vector<vector<int>> &dir) {
        visited[row][col] = 1 ;

        int n = grid.size() ;
        int m = grid[0].size() ;

        for(int i = 0 ; i < 4 ; i++) {
            int nrow = row + dir[i][0] ;
            int ncol = col + dir[i][1] ;

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow,ncol,visited,grid,dir) ;
            }
        }


    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n   = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<int>> visited(n,vector<int>(m,0)) ;

        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}} ;

        for(int i = 0 ; i < n ; i++) {
            if(!visited[i][0] && grid[i][0] == 1) {
                dfs(i,0,visited,grid,dir) ;
            }

            if(!visited[i][m-1] && grid[i][m-1] == 1) {
                dfs(i,m-1,visited,grid,dir) ;
            }
        }


        
        for(int j = 0 ; j  < m  ; j++) {
            if(!visited[0][j] && grid[0][j] == 1) {
                dfs(0,j,visited,grid,dir) ;
            }

            if(!visited[n-1][j] && grid[n-1][j] == 1) {
                dfs(n-1,j,visited,grid,dir) ;
            }
        }


        int ans ;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(!visited[i][j] && grid[i][j] == 1) ans++ ;
            }
        }
        return ans ;





    }

    int numEnclavesBFS(vector<vector<int>> &grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<int>> vis(n,vector<int>(m,0)) ;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}} ;

        queue<pair<int,int>> q ;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1 && !vis[i][j]) {
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }


        while(!q.empty()) {
            int row = q.front().first ;
            int col = q.front().second ;

            for(int d = 0 ; d < 4 ; d++) {
                int nrow = row + dir[d][0] ;
                int ncol = col + dir[d][1] ;

                if(nrow >= 0 && ncol >=0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1 ;
                    q.push({nrow,ncol}) ;
                }
            }
        }

        int ans = 0 ;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(!vis[i][j] && grid[i][j] == 1) ans++ ;
            }
        }

        return ans ;
    }
};

int main() {
    Solution sol ;

    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}} ;

     cout<<sol.numEnclaves(grid)<<endl ;
     cout<<sol.numEnclavesBFS(grid)<<endl ;
}