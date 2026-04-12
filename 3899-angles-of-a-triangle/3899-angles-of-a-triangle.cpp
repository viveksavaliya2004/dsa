class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<int> arr = sides;
        
        double x = arr[0];
        double y = arr[1];
        double z = arr[2];

        if (x + y <= z || y + z <= x || x + z <= y) {
            return {};
        }

        double angle1 = acos((y*y + z*z - x*x) / (2*y*z));
        double angle2 = acos((x*x + z*z - y*y) / (2*x*z));
        double angle3 = acos((x*x + y*y - z*z) / (2*x*y));

        double pi = acos(-1);
        angle1 = angle1 * 180 / pi;
        angle2 = angle2 * 180 / pi;
        angle3 = angle3 * 180 / pi;

        vector<double> ans = {angle1, angle2, angle3};
        sort(ans.begin(), ans.end());

        return ans;
    }
};