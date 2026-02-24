class Solution {
public:

    bool check(int mid ,vector<int>& weight, int days){
        int count = 1;
        int sum = 0;

        for(int i = 0; i < weight.size(); i++){

            if(sum + weight[i] <= mid){
                sum += weight[i];
            }
            else{
                count++;
                sum = weight[i];
            }
        }

        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        int ans = end;

        while(start <= end){

            int mid = start + (end - start)/2;

            if(check(mid ,weights , days )){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};