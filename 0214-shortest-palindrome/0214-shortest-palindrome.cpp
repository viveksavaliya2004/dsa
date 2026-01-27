class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        s += '$';
        s += rev;

        int size = s.size();
        int pre = 0, suf = 1;
        vector<int> vp(size, 0);

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

        string str;

        int n = rev.size() - vp[size - 1];

        
        for (int i = 0; i < n; i++) {
            str += rev[i];
        }

        
        for (int i = 0; i < (size - 1) / 2; i++) {
            str += s[i];
        }

        return str;
    }
};
