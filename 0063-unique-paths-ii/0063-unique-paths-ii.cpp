class Solution {
public:
    int fun(int row , int col ,vector<vector<int>>obstacleGrid , int n , int m ,vector<vector<int>>&dp ){
        if(row == 0 && col==0 && obstacleGrid[row][col] != 1)return 1;
        if(row < 0 || col < 0)return 0;
        if(obstacleGrid[row][col] == 1)return 0;
        if(dp[row][col] != -1 ) return dp[row][col];

        int top = fun(row-1 , col ,obstacleGrid , n , m , dp);
        int left = fun(row, col-1, obstacleGrid , n , m ,dp);

        return dp[row][col] = top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        return fun(n-1 , m-1 , obstacleGrid , n , m , dp);
    }
};