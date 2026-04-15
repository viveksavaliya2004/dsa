class Solution {
public:

   // DFS function jo check karega ki node safe hai ya cycle me hai
   bool dfs(int node , vector<vector<int>>& graph ,
            vector<int> &visited ,
            vector<int> &path,
            vector<int> &check){

    // mark node as visited
    visited[node] = 1;

    // mark node as current DFS path me present
    path[node] = 1;

    // ab current node ke saare neighbours visit karo
    for(int i : graph[node]){

        // agar neighbour visit nahi hua hai
        if(visited[i] == 0){

            // DFS call karo
            if(dfs(i , graph , visited , path , check) == true){

                // agar cycle mil gayi to ye safe node nahi hai
                check[node] = 0;
                return true;
            }
        }

        // agar neighbour already path me hai
        // matlab cycle mil gayi
        else if(path[i] == 1){

            check[node] = 0;
            return true;
        }
    }

    // agar yaha tak aaye matlab cycle nahi mili
    // to node safe hai
    check[node] = 1;

    // path se remove karo (backtracking)
    path[node] = 0;

    return false;
   }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        // visited -> node visited hai ya nahi
        vector<int> visited(n , 0);

        // path -> current DFS path track karega
        vector<int> path(n , 0);

        // check -> safe node hai ya nahi
        vector<int> check(n , 0);

        vector<int> ans;

        // har node se DFS start karo
        // kyunki graph disconnected ho sakta hai
        for(int i = 0 ; i < n ; i++){

            if(visited[i] == 0){
                dfs(i , graph , visited , path , check);
            }
        }

        // jo nodes safe hain unko answer me daalo
        for(int i = 0 ; i < n ; i++){

            if(check[i] == 1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};