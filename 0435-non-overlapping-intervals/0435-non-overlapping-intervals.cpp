class Solution {
public:

    static bool cmp(pair<int,int>&a , pair<int,int>&b){
        return a.second < b.second;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>vi;

        for(int i=0;i<intervals.size();i++){
            vi.push_back({intervals[i][0] , intervals[i][1]});
        }

        sort(vi.begin() ,vi.end() , cmp);

        int endtime = INT_MIN;
        int cnt = 0;
        for(int i=0;i<intervals.size();i++){
            if(vi[i].first >= endtime){
                endtime = vi[i].second;
            }else{
                cnt++;
            }
        }
        return cnt;
    }
};