class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int count = 0;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                count += arr[i] - arr[i - 1];
            }
        }

        return count;
    }
};
