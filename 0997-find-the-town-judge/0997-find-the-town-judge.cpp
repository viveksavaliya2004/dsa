class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.empty() && n == 1) return 1;
        
        vector<int> netTrust(n + 1, 0);
        
        for (auto& relation : trust) {
            netTrust[relation[0]]--;
            netTrust[relation[1]]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (netTrust[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};