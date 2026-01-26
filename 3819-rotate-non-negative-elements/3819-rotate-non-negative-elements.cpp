class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>vp;
        for(int i=0 ; i<nums.size();i++){
            if(nums[i]>=0){
                vp.push_back(nums[i]);
            }
        }
        if(vp.empty()) return nums;
        k = k % vp.size();
        rotate(vp.begin(), vp.begin() + k, vp.end());

        int idx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >=0) {
                nums[i] = vp[idx++];
            }
        }
        return nums;
    }
};