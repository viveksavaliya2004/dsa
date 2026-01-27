class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
         int size = s.size();
        int pre = 0, suf = 1;
        vector<int> vp(size, 0);
        string str;
        while (suf < size) {
            if (s[pre] == s[suf]) {
                vp[suf] = pre + 1;
                pre++;
                suf++;

            } else {
                if (pre == 0) {
                    vp[suf] = 0;
                    suf++;
                } else {
                    pre = vp[pre - 1];
                }
            }
        }
        int lps = vp[size - 1];
        return (lps > 0 && size % (size - lps) == 0);
      
    }
};
