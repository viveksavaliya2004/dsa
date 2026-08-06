class Solution {
public:
    int fun(int row, int col1, int col2,
        int n, int m,
        vector<vector<int>>& grid,
        vector<vector<vector<int>>>& dp)
{
    if(col1 < 0 || col2 < 0 || col1 >= m || col2 >= m)
        return -1e8;

    if(row == n - 1)
    {
        if(col1 == col2)
            return grid[row][col1];
        else
            return grid[row][col1] + grid[row][col2];
    }

    if(dp[row][col1][col2] != -1)
        return dp[row][col1][col2];

    int maxi = -1e8;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int value;

            if(col1 == col2)
                value = grid[row][col1];
            else
                value = grid[row][col1] + grid[row][col2];

            value += fun(row + 1, col1 + i, col2 + j, n, m, grid,dp);

            maxi = max(maxi, value);
        }
    }

    return dp[row][col1][col2] = maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(m , vector<int>(m , -1)));
        return fun(0 , 0 , m-1 , n , m , grid , dp );
    }
};