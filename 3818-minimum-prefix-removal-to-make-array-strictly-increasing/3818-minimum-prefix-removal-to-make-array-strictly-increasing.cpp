class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        int maxx = 1;   

      
        for(int i = n - 1; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                count++;
                maxx = max(maxx, count);
            } else {
                break;   
            }
        }

        return n - maxx;
    }
};
