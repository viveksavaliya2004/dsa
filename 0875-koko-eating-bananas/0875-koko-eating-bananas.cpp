class Solution {
public:

    bool check(int mid ,vector<int>& piles, int h){
        long long  count = 0;
        for(int i=0;i<piles.size();i++){
            count += ceil((double)piles[i] / mid);
        }
        if(count > h)return false;
        else return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin() ,piles.end());
          int ans =0;

        while(start <=end){

            int mid = start + (end -start)/2;
          
            if(check(mid ,piles ,h)){
                ans = mid;
                end =mid-1;
            }else{
                start =mid+1;
            }
        }
        return ans;
    }
};