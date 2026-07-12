class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str = "";

        for (int i = 0; i < s.size(); i++) {

            // Space found
            if (str.size() > 0 && s[i] == ' ') {
                st.push(str);
                str = "";
            }

            // Character
            if (s[i] != ' ') {
                str += s[i];
            }
        }

        // Push the last word
        if (str.size() > 0)
            st.push(str);

        str = "";

        while (!st.empty()) {
            str += st.top();
            st.pop();

            if (!st.empty())
                str += ' ';
        }

        return str;
    }
};