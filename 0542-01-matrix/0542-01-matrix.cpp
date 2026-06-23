class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        queue<pair<pair<int,int>, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int d = q.front().second;
            q.pop();

            dist[row][col] = d;

            // UP
            if(row - 1 >= 0 && !vis[row - 1][col]) {
                vis[row - 1][col] = true;
                q.push({{row - 1, col}, d + 1});
            }

            // RIGHT
            if(col + 1 < m && !vis[row][col + 1]) {
                vis[row][col + 1] = true;
                q.push({{row, col + 1}, d + 1});
            }

            // DOWN
            if(row + 1 < n && !vis[row + 1][col]) {
                vis[row + 1][col] = true;
                q.push({{row + 1, col}, d + 1});
            }

            // LEFT
            if(col - 1 >= 0 && !vis[row][col - 1]) {
                vis[row][col - 1] = true;
                q.push({{row, col - 1}, d + 1});
            }
        }

        return dist;
    }
};