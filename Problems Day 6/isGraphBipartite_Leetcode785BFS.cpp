#include<bits/stdc++.h>
using namespace std ;

class Solution {
private:
    bool check(int node, vector<int>& color, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int it : graph[node]) {

                // if not yet coloured colour to opposite of node

                if (color[it] == -1) {
                    q.push(it);
                    color[it] = !color[node];
                }
                // someone coloured you before on some other path
                else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1); // for colouring the nodes

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (check(i, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}} ;
    Solution sol ;

    cout<< sol.isBipartite(graph) ;
}