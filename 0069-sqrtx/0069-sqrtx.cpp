class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long sq = 1LL * mid * mid;
            if(sq == x){
                return mid;
            }
            else if( sq > x){
                high = mid -1;
            }else{
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};