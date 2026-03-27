class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> >>pq;

        for(auto i : mp){
            pq.push({i.second , i.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int>v;
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }

    return v;
    }
};