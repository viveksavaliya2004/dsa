class Solution {
public:
    int fun(int row, int col, int m, int n, vector<vector<int>>& dp) {
        if (row == m - 1 && col == n - 1)
            return 1;

        if (row >= m || col >= n)
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        int down = fun(row + 1, col, m, n, dp);
        int right = fun(row, col + 1, m, n, dp);

        return dp[row][col] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fun(0, 0, m, n, dp);
    }
};