class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {

        unordered_map<string, int> mp;     
        unordered_map<char, int> st;      
        int count = 0;
        int ans = 0;

        
        for(int i = 0; i < minSize; i++) {
            st[s[i]]++;
        }

        if(st.size() <= maxLetters) {
            string sub = s.substr(0, minSize);
            ans = max(ans, ++mp[sub]);
        }

       
        for(int i = minSize; i < s.size(); i++) {

           
            st[s[i - minSize]]--;
            if(st[s[i - minSize]] == 0)
                st.erase(s[i - minSize]);

            
            st[s[i]]++;

            if(st.size() <= maxLetters) {
                string sub = s.substr(i - minSize + 1, minSize); //Fix 
                ans = max(ans, ++mp[sub]);
            }
        }

        return ans;
    }
};
