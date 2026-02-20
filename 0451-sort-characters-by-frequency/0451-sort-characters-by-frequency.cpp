class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>>v(123);

        for(char &ch :s){
            int freq = v[ch].second;
            v[ch] ={ch,freq+1};
        }
        auto lambda = [&](pair<char, int>& a, const pair<char, int>& b){
            return a.second > b.second;
        };

        sort(v.begin() , v.end() ,lambda);

        string result ="";
        for(int i=0;i<=122;i++){
            if(v[i].second >0){
                char ch = v[i].first;
                int freq = v[i].second;
                string temp =string(freq , ch);
                result +=temp;
            }
        }
        return result;
    }
};