class Solution {
public:
    void fun(int idx, vector<int> nums, vector<int>& vi,
             vector<vector<int>>& ans) {

        ans.push_back(vi);

        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i - 1])
                continue;
            vi.push_back(nums[i]);
            fun(i + 1, nums, vi, ans);
            vi.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> vi;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        fun(0, nums, vi, ans);
        return ans;
    }
};