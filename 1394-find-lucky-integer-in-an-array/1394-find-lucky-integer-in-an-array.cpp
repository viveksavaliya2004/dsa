class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        int ans = -1;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        for(auto at : mp){
            int first = at.first;
            int s =at.second;

            if(first == s){
                ans = max(ans , first);
            }
        }
        return ans;
    }
};