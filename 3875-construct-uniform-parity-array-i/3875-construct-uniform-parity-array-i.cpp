class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool Odd = false;
        bool Even = false;

        for (int x : nums1) {
            if (x % 2 == 0)
                Even = true;
            else
                Odd = true;
        }

        
        if (Odd || Even)
            return true;

       
        return true;
    }
};