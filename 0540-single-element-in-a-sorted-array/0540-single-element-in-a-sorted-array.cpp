class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int right = n -1;

        if(n == 1) return nums[0];

        while(left <= right){
            int mid = left + (right - left)/2;

            if(mid == 0 && nums[0] != nums[1]) return nums[mid];
            if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[mid];

           if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];


            if(mid%2 == 0){ //even
                if(nums[mid]==nums[mid-1]){
                    right = mid -1;
                }else{
                    left = mid+1;
                }
            }
            else{ //odd
                if(nums[mid]==nums[mid-1]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};