class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int> mp;

        // count frequency
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        // store distinct numbers
        vector<int> values;
        for(auto &p : mp){
            values.push_back(p.first);
        }

        // sort values
        sort(values.begin(), values.end());

        int m = values.size();

        // check pairs
        for(int i = 0; i < m; i++){
            for(int j = i + 1; j < m; j++){
                int x = values[i];
                int y = values[j];

                if(mp[x] != mp[y]){
                    return {x, y};
                }
            }
        }

        return {-1, -1};
    }
};