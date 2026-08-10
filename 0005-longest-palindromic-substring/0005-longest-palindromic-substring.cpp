class Solution {
public:
    int fun(int i, int j, const string& s,
            vector<vector<char>>& dp) {

        if (i >= j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = fun(i + 1, j - 1, s, dp);
        }

        return dp[i][j] = 0;
    }

    string longestPalindrome(string s) {

        int n = s.size();

        vector<vector<char>> dp(n, vector<char>(n, -1));

        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (fun(i, j, s, dp)) {

                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};