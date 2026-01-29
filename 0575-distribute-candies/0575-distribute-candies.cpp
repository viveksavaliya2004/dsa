class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;

        for (int x : candyType) {
            st.insert(x);
        }

        int n = candyType.size();
        int m = st.size();

        return (m >= n / 2) ? (n / 2) : m;
    }
};