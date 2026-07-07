class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans;
        long long sum = 0;

       string str =  to_string(n);
        string st ="";
        for(int i=0;i<str.size();i++){
            if(str[i] == '0'){
                continue;
            }else{
                sum += (long long)(str[i] - '0');
                st+=str[i];
                
            }
        }
        if(st.empty())
        return 0;
        
        ans = stoll(st);
        return ans* sum;

    }
};