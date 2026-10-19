class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            set<int>vi;
            for(int j=i;j<nums.size();j++){
                vi.insert(nums[j]);
                int a = vi.size();
                int insum = a*a;
                sum+=insum;
            }
        }
        return sum;
    }
};