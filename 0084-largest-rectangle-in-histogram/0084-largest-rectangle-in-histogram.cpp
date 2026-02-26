class Solution {
public:
    void NSL( vector<int>&left , vector<int>& heights){
        int n = heights.size();
        stack<pair<int,int>>st;
          for(int i=0;i<n;i++){

            while(st.size() > 0 && st.top().first >= heights[i] ){
                st.pop();
            }
            if(st.size() == 0){
                left[i] = -1;
            }else{
                left[i]=st.top().second;
            }

            st.push({heights[i],i});
          }
    }

    void NSR( vector<int>&right , vector<int>& heights){
        int n = heights.size();
        stack<pair<int,int>>st;
          for(int i=n-1 ;i>=0;i--){

            while(st.size() > 0 && st.top().first >= heights[i] ){
                st.pop();
            }
            if(st.size() == 0){
                right[i] = n;
            }else{
                right[i]=st.top().second;
            }

            st.push({heights[i],i});
          }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n);
        vector<int>right(n);

        NSL(left ,heights );
        NSR(right , heights);

        vector<int>wehgit(n);

        for(int i=0;i<n;i++){
            wehgit[i] = right[i] - left[i] -1;
        }

        int maxx = INT_MIN;

        for(int i=0;i<n;i++){
            maxx = max(maxx , heights[i]*wehgit[i]);
        }

        return maxx;
    }
};