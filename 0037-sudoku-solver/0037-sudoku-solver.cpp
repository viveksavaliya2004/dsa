class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch) return false;
            if (board[i][c] == ch) return false;
            if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == ch) return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> v;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.') v.push_back({i, j});

        vector<int> state(v.size(), 0); 
        int k = 0;

        while (k >= 0 && k < (int)v.size()) {
            int r = v[k].first, c = v[k].second;
            bool placed = false;

            for (int d = state[k] + 1; d <= 9; d++) {
                if (isValid(board, r, c, '0' + d)) {
                    board[r][c] = '0' + d;
                    state[k] = d;  
                    placed = true;
                    break;
                }
            }

            if (placed) {
                k++; 
            } else {
                board[r][c] = '.';
                state[k] = 0;
                k--; 
            }
        }
    }
};