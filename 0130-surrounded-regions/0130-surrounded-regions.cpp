class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Out of bounds or not O
        if(row < 0 || row >= m || col < 0 || col >= n ||
           board[row][col] != 'O') {
            return;
        }

        // Mark as safe
        board[row][col] = '#';

        // Visit all 4 directions
        dfs(row + 1, col, board);
        dfs(row - 1, col, board);
        dfs(row, col + 1, board);
        dfs(row, col - 1, board);
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        // First row
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') {
                dfs(0, j, board);
            }
        }

        // Last row
        for(int j = 0; j < n; j++) {
            if(board[m - 1][j] == 'O') {
                dfs(m - 1, j, board);
            }
        }

        // First column
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                dfs(i, 0, board);
            }
        }

        // Last column
        for(int i = 0; i < m; i++) {
            if(board[i][n - 1] == 'O') {
                dfs(i, n - 1, board);
            }
        }

        // Convert cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};