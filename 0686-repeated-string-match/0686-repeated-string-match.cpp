class Solution {
public:
    

    int repeatedStringMatch(string a, string b) {
        int count=1;
        if(a==b)return 1;

        string temp = a;

        while(temp.size() < b.size())
        {
            temp +=a;
            count++;

        }
        if (temp.find(b) != -1)
            return count;

        temp += a;
        count++;

        if (temp.find(b) != -1)
            return count;

        return -1;
    }
};