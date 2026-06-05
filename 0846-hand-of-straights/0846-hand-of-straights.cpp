class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> mp;
        for (int i : hand) {
            mp[i]++;
        }

        while (mp.size()) {
            int start = mp.begin()->first;

            for (int x = start; x < start + groupSize; x++) {
                if (mp.find(x) == mp.end()) return false;

                mp[x]--;
                if (mp[x] == 0) mp.erase(x);
            }
        }

        return true;
    }
};