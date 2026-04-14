class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>ans;
        vector<int>indeg(numCourses ,0);
         for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
            indeg[u]++;  
        }

        //kahn algo
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto &at : adj[node])
            {
                indeg[at]--;
                if(indeg[at] == 0){
                    q.push(at);
                }
            }
        }

        vector<int>temp;
        return (ans.size() == numCourses)?ans : temp;
    }
};