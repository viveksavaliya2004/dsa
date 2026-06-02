class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int minx = INT_MAX;

        
        for (int i = 0; i < n; i++) {

            int time = landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++) {

                int currTime = time; 

                if (waterStartTime[j] <= currTime) {
                    currTime += waterDuration[j];
                } else {
                    currTime = waterStartTime[j] + waterDuration[j];
                }

                minx = min(minx, currTime);
            }
        }

        
        for (int a = 0; a < m; a++) {

            int time = waterStartTime[a] + waterDuration[a];

            for (int j = 0; j < n; j++) {

                int currTime = time; 

                if (landStartTime[j] <= currTime) {
                    currTime += landDuration[j];
                } else {
                    currTime = landStartTime[j] + landDuration[j];
                }

                minx = min(minx, currTime);
            }
        }

        return minx;
    }
};