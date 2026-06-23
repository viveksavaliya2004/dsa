class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }

    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid,
             vector<vector<bool>>& vi) {
        int x[4] = {-1, 1, 0, 0}; // {top , bottom , left , right} 
        int y[4] = {0, 0, -1, 1};

        vi[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];

            if (valid(row, col, n, m) && grid[row][col] == '1' &&
                vi[row][col] == 0) {
                dfs(row, col, n, m, grid, vi);
            }
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vi(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vi[i][j] == 0) {
                    dfs(i, j, n, m, grid, vi);
                    count++;
                }
            }
        }
        return count;
    }
};