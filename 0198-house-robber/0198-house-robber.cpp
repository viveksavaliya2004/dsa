class Solution {
public:
    int fun(int idx , vector<int>nums , vector<int>&dp){

        if(idx == 0) return nums[idx];
        if(idx < 0 ) return 0;
        if(dp[idx] != -1)return dp[idx];
        int peck = nums[idx] +  fun(idx - 2 ,nums , dp);
        int notpeck = 0 + fun(idx - 1  , nums , dp);

        return dp[idx] = max(peck , notpeck);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , -1);

        return fun( n-1 , nums , dp);

    }
};