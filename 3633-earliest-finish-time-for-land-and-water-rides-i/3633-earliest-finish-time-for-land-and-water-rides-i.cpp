class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int minx = INT_MAX;

        // Land -> Water
        for (int i = 0; i < n; i++) {

            int landFinish = landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++) {

                int startWater = max(landFinish, waterStartTime[j]);
                int finish = startWater + waterDuration[j];

                minx = min(minx, finish);
            }
        }

        // Water -> Land
        for (int i = 0; i < m; i++) {

            int waterFinish = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < n; j++) {

                int startLand = max(waterFinish, landStartTime[j]);
                int finish = startLand + landDuration[j];

                minx = min(minx, finish);
            }
        }

        return minx;
    }
};