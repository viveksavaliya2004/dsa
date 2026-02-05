class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                
                ans.push_back(0);
            }else{
                int x = ((i+nums[i])%n + n )%n;
                ans.push_back(nums[x]);
            }
        }
        return ans;
    }
};