#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution
{
private:
    void dfs(vector<vector<int>> &ans, vector<vector<int>> &image, int row, int col, int newColor , int initialColor)
    {
        ans[row][col] = newColor ;

        for(int i = 0 ; i < 4 ; i++) {
            int nRow = row + directions[i][0] ;
            int nCol = col + directions[i][1] ;

            if(nRow >= 0 && nCol >= 0 && nRow < image.size() && nCol < image.size() && image[nRow][nCol] == initialColor && ans[nRow][nCol] != newColor) {

                dfs(ans,image,nRow,nCol,newColor,initialColor) ;
            }
        }
    }


public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();

        int initialColor = image[sr][sc];

        vector<vector<int>> ans = image;

        dfs(ans, image, sr, sc, color , initialColor);
    }
};

int main()
{

    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;

    Solution sol;

    vector<vector<int>> ans = sol.floodFill(image, sr, sc, color);
}
