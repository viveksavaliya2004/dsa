class Solution {
public:
    string processStr(string s) {
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&& s[i]<='z'){
                str+=s[i];
            }
            else if(s[i]=='#'){
                str+=str;
            }
            else if(s[i]=='%'){
                reverse(str.begin() , str.end());
            }else{
                int n =str.size();
                if(n > 0){
                    str.erase(n-1,1);
                }
            }
        }
        return str;
    }
};