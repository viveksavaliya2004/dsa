class Solution {
public:
    int maxVowels(string s, int k) {
        int vo = 0;

        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'u' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'e') {
                vo++;
            }
        }

        int ans = vo;

        for (int i = k; i < s.size(); i++) {

            if (s[i] == 'a' || s[i] == 'u' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'e') {
                vo++;
            }

            if (s[i - k] == 'a' || s[i - k] == 'u' || s[i - k] == 'i' ||
                s[i - k] == 'o' || s[i - k] == 'e') {
                vo--;
            }

            ans = max(ans, vo);
        }

        return ans;
    }
};