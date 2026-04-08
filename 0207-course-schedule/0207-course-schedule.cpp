class Solution {
public:
    bool dfs(int node , vector<vector<int>>& adj , vector<int>& vi, vector<int>& path){
        vi[node] = 1;
        path[node] = 1;

        for(auto &nbr : adj[node]){
            if(!vi[nbr]){
                if(dfs(nbr , adj , vi, path) == true){
                    return true;
                }
            }
            else if(path[nbr]){   
                return true;
            }
        }

        path[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        vector<int> vi(numCourses , 0);
        vector<int> path(numCourses , 0);

        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        for(int i = 0; i < numCourses; i++){
            if(!vi[i]){
                if(dfs(i, adj, vi, path)){
                    return false; 
                }
            }
        }

        return true; 
    }
};