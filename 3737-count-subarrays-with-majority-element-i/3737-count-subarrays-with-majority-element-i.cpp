class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int cnt =0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target){
                    cnt++;
                }
                else{
                    cnt--;
                }
                if(cnt>0)sum++;
            }
        }
       return sum;
    }
};