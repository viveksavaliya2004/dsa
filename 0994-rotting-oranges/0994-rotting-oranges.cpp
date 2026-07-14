class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vi(n, vector<int>(m, 0));
        queue<pair<pair<int, int> , int >> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j} , 0});
                    vi[i][j] = 2;
                }
            }
        }

        int time = 0;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;

            q.pop();

            time = max(time , tm);

            for(int i=0;i<4;i++){
                int rowx = row + dx[i];
                int colx = col + dy[i];

                if(rowx>=0 && rowx<n && colx>=0 && colx<m && grid[rowx][colx]==1 && vi[rowx][colx]!=2){
                    q.push({{rowx,colx} , tm+1});
                    vi[rowx][colx] = 2;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vi[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};