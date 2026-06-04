class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int count =0 ;
        int maxx = INT_MIN;
        for(int i=0;i<k;i++){
            count+=cardPoints[i];
        }

        maxx = max(count , maxx);
        int j = cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            count = count -cardPoints[i]+cardPoints[j];
            maxx = max(maxx , count);
            j--;
        }
        return maxx;
    }
};