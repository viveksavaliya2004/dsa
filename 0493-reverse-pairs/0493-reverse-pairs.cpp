class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int right = mid + 1;

        // Count reverse pairs
        for (int left = low; left <= mid; left++) {
            while (right <= high && (long long)nums[left] > 2LL * nums[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }

        // Merge two sorted halves
        vector<int> temp;
        int i = low;
        int j = mid + 1;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while (i <= mid)
            temp.push_back(nums[i++]);

        while (j <= high)
            temp.push_back(nums[j++]);

        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        int count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};