class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> vi(n, vector<int>(m, 0));

        // First and last row
        for (int j = 0; j < m; j++) {

            if (grid[0][j] == 1 && !vi[0][j]) {
                q.push({0, j});
                vi[0][j] = 1;
            }

            if (grid[n - 1][j] == 1 && !vi[n - 1][j]) {
                q.push({n - 1, j});
                vi[n - 1][j] = 1;
            }
        }

        // First and last column
        for (int i = 0; i < n; i++) {

            if (grid[i][0] == 1 && !vi[i][0]) {
                q.push({i, 0});
                vi[i][0] = 1;
            }

            if (grid[i][m - 1] == 1 && !vi[i][m - 1]) {
                q.push({i, m - 1});
                vi[i][m - 1] = 1;
            }
        }

        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int rowx = row + x[i];
                int colx = col + y[i];

                if (rowx >= 0 && rowx < n && colx >= 0 && colx < m &&
                    !vi[rowx][colx] && grid[rowx][colx] == 1) {
                    q.push({rowx, colx});
                    vi[rowx][colx] = 1;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vi[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};