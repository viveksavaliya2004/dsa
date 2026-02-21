class Solution {
public:

    int findMin(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        int end = n-1;

        while(start <= end){

            if (nums[start] <= nums[end])
                return start;

            int mid = start + (end - start)/2;

            int next = (mid + 1)%n;
            int pre = (mid + n-1)%n;

            if(nums[mid] <= nums[pre] && nums[mid] <= nums[next]){
                return mid;
            }
            
            if(nums[start] <= nums[mid]){
                start = mid +1;
            }
            else{
                end = mid -1;
            }
        }
        return -1;
    }
    int bs(vector<int>& nums, int start , int end , int target){
        while(start <= end){
            int mid = start +(end - start)/2;

            if(nums[mid] == target)return mid;
            else if(target <= nums[mid]){
                end = mid -1;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int index = findMin(nums);
        int a = bs(nums , start , index-1 ,target);
        int b = bs(nums , index , end , target);

        if(a> -1)return a;
        if(b > -1)return b;

        return -1;
    }
};