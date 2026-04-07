class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int V = edges.size() +1 ;
        int e = edges.size();
        vector<vector<int>>adj(V+1);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1;i<=adj.size();i++){
            int size = adj[i].size();
            if(size == e){
                return i;
            }
        }
    return 0;
    }
};