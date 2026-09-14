class Solution {
public:
    bool checkDivisibility(int ni) {
        int sum = 0;
        int pro = 1;
        int n = ni;

        while (n > 0) {
            int digit = n % 10;

            sum += digit;
            pro *= digit;

            n /= 10;
        }

        return ni % (sum + pro) == 0;
    }
};