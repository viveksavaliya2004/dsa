class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> comp(n);
        int count = 0;

        comp[0] = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                count++;

            comp[i] = count;
        }

        vector<bool> ans;

        for (auto at : queries) {
            int i = at[0];
            int j = at[1];

            ans.push_back(comp[i] == comp[j]);
        }
        return ans;
    }
};