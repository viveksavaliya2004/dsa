class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> map = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        result.push_back("");   
        for (char d : digits) {
            vector<string> temp;

            for (string s : result) {
                for (char ch : map[d - '0']) {
                    temp.push_back(s + ch);
                }
            }

            result = temp;
        }

        return result;
    }
};
