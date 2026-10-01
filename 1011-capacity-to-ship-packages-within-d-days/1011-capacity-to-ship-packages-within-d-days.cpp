class Solution {
public:
   bool check(vector<int>& weights, int days, int mid) {
    int daysUsed = 1;
    int sum = 0;

    for(int i = 0; i < weights.size(); i++) {

        if(sum + weights[i] <= mid) {
            sum += weights[i];
        }
        else {
            daysUsed++;
            sum = weights[i];

            if(daysUsed > days)
                return false;
        }
    }

    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {

    int start = *max_element(weights.begin(), weights.end());
    int end = accumulate(weights.begin(), weights.end(), 0);

    int ans = end;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(check(weights, days, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return ans;
}
};