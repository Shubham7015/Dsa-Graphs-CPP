#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // DFS to mark all connected 'O' cells as visited
    void dfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<int>>& directions, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Mark current cell as visited
        visited[row][col] = 1;

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + directions[i][0];
            int ncol = col + directions[i][1];

            // Check bounds, visited status, and if cell contains 'O'
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visited, directions, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        // Direction vectors: up, down, right, left
        vector<vector<int>> directions =
        { {-1, 0},
          {1, 0},
          {0, 1},
          {0, -1} } ;

        // Mark all 'O' cells connected to top and bottom borders
        for (int j = 0; j < m; j++) {
            if (!visited[0][j] && board[0][j] == 'O') {
                dfs(0, j, visited, directions, board);
            }
            if (!visited[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, visited, directions, board);
            }
        }

        // Mark all 'O' cells connected to left and right borders
        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && board[i][0] == 'O') {
                dfs(i, 0, visited, directions, board);
            }
            if (!visited[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, visited, directions, board);
            }
        }

        // Convert unvisited 'O' cells to 'X' (surrounded regions)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
int main() {
    // Test case: board with surrounded and non-surrounded regions
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}} ;

    Solution sol ;
    sol.solve(board) ;

    // Print the modified board
    for(int i = 0 ; i < board.size() ; i++) {
        for(int j = 0 ; j < board[0].size() ; j++) {
            cout<< board[i][j] << " " ;
        }
        cout<<endl ;
    }
}
