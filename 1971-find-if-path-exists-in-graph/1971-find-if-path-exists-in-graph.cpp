class Solution {
public:

    // DFS function to visit all connected nodes
    void dfs(int node, vector<int>& vi, vector<vector<int>>& g) {
        vi[node] = 1;

        for (int at : g[node]) {   
            if (!vi[at]) {
                dfs(at, vi, g);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

       
        vector<vector<int>> g(n);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);  
        }

        vector<int> vi(n, 0);

       
        dfs(source, vi, g);

     
        return vi[destination];
    }
};