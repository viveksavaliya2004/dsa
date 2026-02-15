class Solution {
public:
    string addBinary(string a, string b) {
        int asize = a.size();
        int bsize = b.size();
        
        
        if(asize > bsize){
            b = string(asize - bsize, '0') + b;
        }
        else if(bsize > asize){
            a = string(bsize - asize, '0') + a;
        }

        int carry = 0;
        string ans = "";

        for(int i = a.size() - 1; i >= 0; i--){
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            ans = to_string(sum % 2) + ans;
            carry = sum / 2;
        }

        if(carry != 0) 
            ans = "1" + ans;

        return ans;
    }
};
