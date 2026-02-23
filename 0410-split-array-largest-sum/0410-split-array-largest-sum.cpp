class Solution {
public:

    bool check(int mid, vector<int>& nums, int k){
        int count = 1;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(sum > mid){
                count++;
                sum = nums[i];
            }

            if(count > k)
                return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {

        int start = *max_element(nums.begin(), nums.end());
        long long end = accumulate(nums.begin(), nums.end(), 0LL);

        while(start <= end){
            int mid = start + (end - start)/2;

            if(check(mid , nums , k)){
                end = mid - 1;   
            }else{
                start = mid + 1; 
            }
        }
        return start;
    }
};