#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0)); // visited array
        queue<pair<pair<int, int>, int>>
            q; // for BFS traversal <<i,j>,time_to_rotten>>

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                   {
                     q.push(
                        {{i, j},
                         0}); // if it is rotten then push into the queue with
                              // with intital time (0) bcz already rotten
                visited[i][j] = 2; // mark rotten in visited array
                   }
            }
        }

        // vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<int> dirRow = {-1, 0, 1, 0};
        vector<int> dirCol = {0, 1, 0, -1};
        int time = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(t, time);

            for (int i = 0; i < 4; i++) {
                int nRow = r + dirRow[i];
                int nCol = c + dirCol[i];

                if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m &&
                    visited[nRow][nCol] != 2 && grid[nRow][nCol] == 1) {
                    q.push({{nRow, nCol}, t + 1});
                    visited[nRow][nCol] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] != 2 && grid[i][j] == 1)
                    return -1;
            }
        }
        return time;
    }
};

int main() {
     // Input grid with 2 = rotten, 1 = fresh, 0 = empty
    vector<vector<int>> grid{{2, 1, 1}, 
                          {1, 1, 0}, 
                          {0, 1, 1}};
    
    // Call the function to calculate minimum time required
    Solution sol ;
    int rotting = sol.orangesRotting(grid);

    // Output the result
    cout << "Minimum Number of Minutes Required " << rotting << endl;

    return 0;
}