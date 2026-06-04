class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long maxx = 0;
        unordered_map<int,int> frq;

        int count = 0; 

        for(int i = 0; i < k; i++) {
            frq[nums[i]]++;
            if(frq[nums[i]] == 2) count++;
            sum += nums[i];
        }

        if(count == 0) maxx = sum;

        for(int i = k; i < nums.size(); i++) {

            
            frq[nums[i-k]]--;
            if(frq[nums[i-k]] == 1) count--;
            if(frq[nums[i-k]] == 0) frq.erase(nums[i-k]);

            sum -= nums[i-k];

        
            frq[nums[i]]++;
            if(frq[nums[i]] == 2) count++;

            sum += nums[i];

            if(count == 0)
                maxx = max(maxx, sum);
        }

        return maxx;
    }
};