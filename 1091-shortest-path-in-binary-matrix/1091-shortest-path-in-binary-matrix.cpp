class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<pair<int, int>, int>> q;

        q.push({{0, 0}, 1});
        visited[0][0] = true;

        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            if (r == n - 1 && c == n - 1)
                return dist;

            for (int k = 0; k < 8; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && !visited[nr][nc]) {

                    visited[nr][nc] = true;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }

        return -1;
    }
};