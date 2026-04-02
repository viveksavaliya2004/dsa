class Solution {
public:


    void dfs(vector<vector<int>>& g, vector<int>& vi, int node){
        vi[node] = 1;   

        for(int nei : g[node]){
            if(!vi[nei]){
                dfs(g, vi, nei);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

       
        vector<vector<int>> g(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    g[i].push_back(j);
                }
            }
        }

    
        vector<int> vi(n, 0);

        int cnt = 0;

        
        for(int i = 0; i < n; i++){
            if(!vi[i]){
                dfs(g, vi, i);
                cnt++;  
            }
        }

        return cnt;
    }
};