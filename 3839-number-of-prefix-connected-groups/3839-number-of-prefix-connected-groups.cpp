class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> mp;

        for(auto w : words){
            int j = w.size();
            if(j >= k){
                string str = w.substr(0 , k);
                mp[str]++;
            }
        }

        int count = 0;


        for(auto p : mp){
            if(p.second >= 2){
                count++;
            }
        }
        return count;
    }
};