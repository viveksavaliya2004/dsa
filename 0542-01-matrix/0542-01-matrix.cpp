class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vi(n, vector<bool>(m, 0));
        vector<vector<int>> di(n, vector<int>(m, 0));

        queue<pair<pair<int,int>, int>> q;

        // Push all 0s into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vi[i][j] = 1;
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            di[row][col] = dist;

            for(int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr >= 0 && nr < n &&nc >= 0 && nc < m &&!vi[nr][nc]) {
                    vi[nr][nc] = 1;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }

        return di;
    }
};