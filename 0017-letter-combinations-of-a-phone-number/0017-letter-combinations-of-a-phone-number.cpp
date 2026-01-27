class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> mapp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> r;
        r.push_back("");   
        for (char d : digits) {
            vector<string> temp;

            for (string s : r) {
                for (char ch : mapp[d - '0']) {
                    temp.push_back(s + ch);
                }
            }

            r = temp;
        }

        return r;
    }
};
