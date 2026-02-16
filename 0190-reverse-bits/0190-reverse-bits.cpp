#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        vector<int> v(32, 0);

        
        for(int i = 31; i >= 0; i--) {
            v[i] = n % 2;
            n = n / 2;
        }

        reverse(v.begin(), v.end());

        
        int result = 0;
        for(int i = 0; i < 32; i++) {
            result = result * 2 + v[i];
        }

        return result;
    }
};
