class Solution {
public:
bool checkIncreasing(const vector<int>& nums, int zero_idx, int n) {
        for (int i = 0; i < n; ++i) {
            if (nums[(zero_idx + i) % n] != i) return false;
        }
        return true;
    }

    
    bool checkDecreasing(const vector<int>& nums, int zero_idx, int n) {
        for (int i = 0; i < n; ++i) {
            if (nums[(zero_idx + i) % n] != (n - i) % n) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {

 int n = nums.size();
        if (n <= 1) return 0;

       
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }

        int ans = 1e9; // Initialize with a large number

      
        if (checkIncreasing(nums, idx, n)) {
            ans = min(ans, idx);
        }

      
        if (checkDecreasing(nums, idx, n)) {
            ans = min(ans, ((idx + 1) % n) + 1);
        }

      
        int new_idx = n - 1 - idx; 
        
      
        if (checkDecreasing(nums, idx, n)) { 
            
            ans = min(ans, 1 + new_idx);
        }
        
      
        if (checkIncreasing(nums, idx, n)) {
          
            ans = min(ans, 1 + ((new_idx + 1) % n) + 1);
        }

        return (ans == 1e9) ? -1 : ans;
    }
};