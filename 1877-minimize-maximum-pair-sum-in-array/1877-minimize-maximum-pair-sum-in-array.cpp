class Solution {
public:
    int minPairSum(vector<int>& nums) {
       
        sort(nums.begin() , nums.end());
        int right = nums.size()-1;
        int left = 0;
        int maxx = INT_MIN;
       
        while(left < right){
            maxx = max(maxx , nums[left] + nums[right]);
            left++;
            right--;
        }
        return maxx;
    }
};