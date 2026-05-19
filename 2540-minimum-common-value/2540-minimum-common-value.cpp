class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int ,int>mp;
        set<int>st1;
        set<int>st2;
        for(int i=0;i<nums1.size();i++){
           st1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            st2.insert(nums2[i]);
        }

        for(auto &it : st1){
           mp[it]++;
        }
        for(auto &it : st2){
           mp[it]++;
        }
        for(auto &it : mp){
            int count = it.second;
            if(count>=2){
                return it.first;
            }
        }
        return -1;
    }
};