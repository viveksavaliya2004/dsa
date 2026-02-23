class Solution {
public:

    bool check(int mid , vector<int>& nums, int maxOperations) {
        long long operation = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > mid){
                operation += (nums[i] - 1) / mid;
            }

            if(operation > maxOperations)
                return false;
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1;
        int end = *max_element(nums.begin() , nums.end());

        while(start <= end){
            int mid = start + (end - start)/2;

            if(check(mid , nums, maxOperations)){
                end = mid - 1;     // try smaller
            }else{
                start = mid + 1;   // increase size
            }
        }
        return start;
    }
};