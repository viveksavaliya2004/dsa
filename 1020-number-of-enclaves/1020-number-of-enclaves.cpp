class Solution {
public:

    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }

    void dfs(int i, int j, int n, int m,
             vector<vector<int>>& grid,
             vector<vector<bool>>& vis) {

        vis[i][j] = true;

        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {

            int row = i + x[k];
            int col = j + y[k];

            if (valid(row, col, n, m) &&
                grid[row][col] == 1 &&
                vis[row][col] == false) {

                dfs(row, col, n, m, grid, vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // First and Last Column
        for (int row = 0; row < n; row++) {

            if (grid[row][0] == 1 && !vis[row][0]) {
                dfs(row, 0, n, m, grid, vis);
            }

            if (grid[row][m - 1] == 1 && !vis[row][m - 1]) {
                dfs(row, m - 1, n, m, grid, vis);
            }
        }

        // First and Last Row
        for (int col = 0; col < m; col++) {

            if (grid[0][col] == 1 && !vis[0][col]) {
                dfs(0, col, n, m, grid, vis);
            }

            if (grid[n - 1][col] == 1 && !vis[n - 1][col]) {
                dfs(n - 1, col, n, m, grid, vis);
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && vis[i][j] == false) {
                    count++;
                }
            }
        }

        return count;
    }
};