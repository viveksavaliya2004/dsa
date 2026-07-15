class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd = 0;
        int sumeven = 0;
        int i=1;
        int j = 2;
        while(n){
            sumodd+=i;
            sumeven+=j;
            i+=2;
            j+=2;
            n--;

        }

        return gcd(sumodd , sumeven);
    }
};