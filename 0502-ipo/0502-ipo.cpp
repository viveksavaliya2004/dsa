class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();

        // Step 1: store (capital, profit)
        vector<pair<int,int>> projects;
        for(int i = 0; i < n; i++){
            projects.push_back({capital[i], profits[i]});
        }

        // Step 2: sort by capital
        sort(projects.begin(), projects.end());

        // Step 3: max heap for profits
        priority_queue<int> pq;

        int i = 0;

        for(int j = 0; j < k; j++){

            // add all affordable projects
            while(i < n && projects[i].first <= w){
                pq.push(projects[i].second);
                i++;
            }

            // if no project available
            if(pq.empty()) break;

            // pick max profit
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};