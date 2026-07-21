class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int one = 0 , maxx = 0 ,prvsum = -1;

        int n = s.size();

        int i = 0;

        while(i<n){
            if(s[i] == '1'){
                one++;
                i++;
            }else{
                int cuu = 0;
                while(i < n && s[i] == '0'){
                    cuu++;
                    i++;
                }
                if(prvsum > 0){
                    maxx = max(maxx , prvsum + cuu);
                }

                prvsum = cuu;
            }
        }
        return one + maxx;
    }
};