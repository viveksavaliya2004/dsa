class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char , int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        priority_queue<pair<int,char>>pq;

        for(auto it : mp){
            pq.push({it.second,it.first});
        }

        string result = "";

        pair<int,char>prv = {0,'#'};
        while(!pq.empty()){
            auto at = pq.top();
            pq.pop();

            result += at.second;
            at.first--;

            if(prv.first > 0)
            {
                pq.push(prv);
            }

            prv = at;

        }

        if(result.size()!=s.size()){
            return "";
        }

        return result;
    }
};