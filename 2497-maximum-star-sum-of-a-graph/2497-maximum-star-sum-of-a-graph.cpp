class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int v = vals.size();
        vector<vector<int>> adj(v);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int vv = edges[i][1];

            adj[u].push_back(vv);
            adj[vv].push_back(u);
        }

        int ans = INT_MIN;

        for (int i = 0; i < adj.size(); i++) {

            priority_queue<int, vector<int>, greater<int>> pq;

           
            for (int j = 0; j < adj[i].size(); j++) {
                int at = adj[i][j];

                if (vals[at] > 0) {
                    pq.push(vals[at]);

                    if (pq.size() > k) { 
                        pq.pop();
                    }
                }
            }

            int sum = vals[i]; 

            while (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};