class Solution {
public:
    int minPairSum(vector<int>& nums) {
       
        sort(nums.begin() , nums.end());
        int right = nums.size()-1;
        int left = 0;
        int maxx = INT_MIN;
        int sum = 0;
        while(left < right){
            sum = nums[left] + nums[right];
            maxx = max(maxx , sum);
            left++;
            right--;
        }
        return maxx;
    }
};