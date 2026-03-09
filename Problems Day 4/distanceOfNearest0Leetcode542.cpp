#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                } else {
                    visited[i][j] = 0;
                }
            }
        }

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            dist[r][c] = d;

            for (int i = 0; i < 4; i++) {

                int nrow = r +  directions[i][0];
                int ncol = c + directions[i][1];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    visited[nrow][ncol] != 1) {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, d + 1});
                }
            }
        }

        return dist;
    }
};

int main(){
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}} ;

    Solution sol ;

    vector<vector<int>> res = sol.updateMatrix(mat) ;

    for(int i = 0 ; i < res.size() ; i++){
        for(int j = 0 ; j < res[0].size() ; j++){
            cout<<res[i][j]<<" " ;
        }
        cout<<endl ;
        }
    
}