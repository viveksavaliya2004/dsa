class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int sum = 0;
        int count= 0;
        for(int i=cost.size()-1;i>=0;i--){
            if(count<2){
                sum+=cost[i];
                count++;
            }else{
                count=0;
            }
        }
        return sum;
    }
};