class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxlength = 0;
        unordered_map<char, int> mp;

        int i = 0;

        for (int j = 0; j < s.size(); j++) {
            mp[s[j]]++;

            while (mp[s[j]] > 2) {
                mp[s[i]]--;
                i++;
            }

            maxlength = max(maxlength, j - i + 1);
        }

        return maxlength;
    }
};