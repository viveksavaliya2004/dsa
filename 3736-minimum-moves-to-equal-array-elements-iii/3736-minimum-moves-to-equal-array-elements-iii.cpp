class Solution {
public:
    int minMoves(vector<int>& v) {
        int maxVal = *max_element(v.begin(), v.end());
        int cnt = 0;
        for(int i=0;i<v.size();i++){
            cnt+=abs(maxVal-v[i]);
        }
    return cnt;
    }
};