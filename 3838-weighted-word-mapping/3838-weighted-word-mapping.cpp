class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& w) {
       string ans="";
        for(string str : words){
             int sum = 0 ;
            for(char ch : str){
                sum += w[ch - 'a'];
            }
            int k = sum%26;
            char mp = 'z' - k;
            ans+=mp;    
        }
        return ans;
    }
};