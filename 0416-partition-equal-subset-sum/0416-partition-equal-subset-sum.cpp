class Solution {
public:

    bool fun(int idx,
             vector<int>& nums,
             int target,
             vector<vector<int>>& dp)
    {
        if(target == 0)
            return true;

        if(idx == nums.size())
            return false;

        if(dp[idx][target] != -1)
            return dp[idx][target];

        bool take = false;

        if(nums[idx] <= target)
            take = fun(idx + 1,
                       nums,
                       target - nums[idx],
                       dp);

        bool notTake = fun(idx + 1,
                           nums,
                           target,
                           dp);

        return dp[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int totalSum = 0;

        for(int x : nums)
            totalSum += x;

        if(totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;

        int n = nums.size();

        vector<vector<int>> dp(n,
                               vector<int>(target + 1, -1));

        return fun(0, nums, target, dp);
    }
};