class Solution {
public:
    int fun(int row, int col, int n, int m,
            const vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {

        if (col < 0 || col >= m)
            return 1e9;

        if (row == n - 1)
            return matrix[row][col];

        if (dp[row][col] != 1e9)
            return dp[row][col];

        int left = fun(row + 1, col - 1, n, m, matrix, dp);
        int down = fun(row + 1, col, n, m, matrix, dp);
        int right = fun(row + 1, col + 1, n, m, matrix, dp);

        return dp[row][col] = matrix[row][col] + min({left, down, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 1e9));

        int ans = 1e9;

        for (int j = 0; j < m; j++) {
            ans = min(ans, fun(0, j, n, m, matrix, dp));
        }

        return ans;
    }
};