class Solution {
public:
    int minPartitions(string n) {
        char maxx = '0';
        for(auto i : n){
            maxx =max(i , maxx); 
        }
        return maxx - '0';
    }
};