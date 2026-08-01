class Solution {
public:

    void fun(int idx ,vector<int> nums ,vector<int>&vi , vector<vector<int>>&ans){
        if(idx == nums.size()){
            ans.push_back(vi);
            return ;
        }

        vi.push_back(nums[idx]);
        fun(idx+1 , nums , vi , ans);

        vi.pop_back();
        fun(idx+1 , nums , vi , ans);
    }
    

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>vi;
        vector<vector<int>>ans;
        int idx = 0;
        fun(idx , nums , vi , ans );
        return ans;
    }
};