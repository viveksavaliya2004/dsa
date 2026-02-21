class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>v;
        priority_queue<pair<int , pair<int,int>>>pq;

        for(int i=0;i<points.size();i++){

            pq.push({(points[i][0]*points[i][0] + points[i][1]*points[i][1]),{points[i][0] , points[i][1]}});

            if(pq.size() > k){
                pq.pop();
            } 
        }

         while(!pq.empty()){
            auto p = pq.top().second;
            pq.pop();
            v.push_back({p.first, p.second});
        }

        return v;
    }
};