class Solution {
public:

    bool check(int mid , vector<int>& bloomDay, int m, int k){
        int count = 0;
        int total =0;
        for(int i=0 ;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid){
                count++;
            }else{
                count = 0;
            }

            if(count == k){
                total++;
                count=0;
            }

            if(total >= m){
                return true;
            }
        }
        return false;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {

        //base case 
        if((long)m*k > bloomDay.size())return -1;
        
        //step 1 : find out range 
        int start = *min_element(bloomDay.begin() , bloomDay.end());
        int end = *max_element(bloomDay.begin() , bloomDay.end());
         int ans = 0;

        //step 2 : apply bs
        while(start <= end){
            int mid = start + (end - start)/2;
           
            //step 3 : check mid is answer or not?
            if(check(mid ,bloomDay , m , k )){
                ans = mid;
                end = mid-1;
            }else{
                start =mid+1;
            }
        }
        return ans;
    }
};