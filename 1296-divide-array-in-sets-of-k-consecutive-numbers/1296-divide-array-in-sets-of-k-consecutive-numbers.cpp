class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        if (nums.size() % k != 0)
            return false;

        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : nums) {
            mp[x]++;
            pq.push(x);
        }

        while (!pq.empty()) {

            int start = pq.top();
            pq.pop();

            if (mp[start] == 0)
                continue;

            for (int i = 0; i < k; i++) {

                int card = start + i;

                if (mp[card] == 0)
                    return false;

                mp[card]--;
            }
        }

        return true;
    }
};