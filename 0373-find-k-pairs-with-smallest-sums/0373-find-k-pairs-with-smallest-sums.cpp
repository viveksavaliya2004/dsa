class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        // max heap
        priority_queue<pair<int, pair<int,int>>> pq;

        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {

                int sum = nums1[i] + nums2[j];

                if(pq.size() < k) {
                    pq.push({sum, {i, j}});
                }
                else if(sum < pq.top().first) {
                    pq.pop();
                    pq.push({sum, {i, j}});
                }
                else {
                    break; // optimization
                }
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});
        }

        return ans;
    }
};