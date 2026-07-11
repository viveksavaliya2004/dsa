class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();
        int totalSubsets = 1 << n;      // 2^n

        vector<vector<int>> ans;

        for (int mask = 0; mask < totalSubsets; mask++) {

            vector<int> subset;

            for (int i = 0; i < n; i++) {

                // Check if ith bit is set
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};