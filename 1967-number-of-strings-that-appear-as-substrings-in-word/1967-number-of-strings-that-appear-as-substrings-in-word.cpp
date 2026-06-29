class Solution {
public:
    int numOfStrings(vector<string>& patterns, string s) {
        unordered_set<string>st;
        for (int i = 0; i < s.size(); i++) {
            string temp = "";

            for (int j = i; j < s.size(); j++) {
                temp += s[j];
                st.insert(temp);
            }
        }
        int cnt = 0;
        for(int i=0;i<patterns.size();i++){
            if(st.find(patterns[i])!=st.end()){
                cnt++;
            }
        }

        return cnt;
    }
};