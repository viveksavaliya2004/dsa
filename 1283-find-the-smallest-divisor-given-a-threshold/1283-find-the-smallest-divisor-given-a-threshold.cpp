class Solution {
public:
    bool check(vector<int> nums, int threshold , int mid){
        long long count = 0;
        for(int i=0;i<nums.size();i++){
            count+=ceil((double)nums[i]/mid);
        }
        if(count > threshold){
            return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin() , nums.end());
        int ans ; 

        while(low <= high){
            int mid = low + (high - low)/2;

            if(check(nums ,threshold , mid )){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};