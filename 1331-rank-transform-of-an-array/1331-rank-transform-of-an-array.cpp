class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> arrs(arr.begin(), arr.end());

        sort(arrs.begin(), arrs.end());

        unordered_map<int,int> mp;

        int count = 1;

        for(int i = 0; i < arrs.size(); i++) {

            if(mp.find(arrs[i]) == mp.end()) {
                mp[arrs[i]] = count;
                count++;
            }
        }

        vector<int> ans;

        for(int x : arr) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};