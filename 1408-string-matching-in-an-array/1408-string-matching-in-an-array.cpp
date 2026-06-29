class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string>vi;

        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(words[i].find(words[j])!=string::npos){
                    vi.insert(words[j]);
                }else if(words[j].find(words[i])!=string::npos ){
                    vi.insert(words[i]);
                }
            }
        }
        vector<string>ans(vi.begin() ,vi.end());
        return ans;
    }
};