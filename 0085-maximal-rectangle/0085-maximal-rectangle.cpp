class Solution {
public:

    void NSL(vector<int>& left , vector<int>& heights){
        int n = heights.size();
        stack<pair<int,int>> st;

        for(int i=0;i<n;i++){

            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }

            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top().second;

            st.push({heights[i], i});
        }
    }

    void NSR(vector<int>& right , vector<int>& heights){
        int n = heights.size();
        stack<pair<int,int>> st;

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }

            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top().second;

            st.push({heights[i], i});
        }
    }

    int MAH(vector<int>& heights){

        int n = heights.size();

        vector<int> left(n);
        vector<int> right(n);

        NSL(left, heights);
        NSR(right, heights);

        int maxx = 0;

        for(int i=0;i<n;i++){
            int width = right[i] - left[i] - 1;
            maxx = max(maxx, heights[i] * width);
        }

        return maxx;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> v(m);

        // First row
        for(int i=0;i<m;i++){
            v[i] = matrix[0][i] - '0';   // FIXED
        }

        int maxx = MAH(v);

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){

                if(matrix[i][j] == '0')   // FIXED
                    v[j] = 0;
                else
                    v[j] += 1;            // FIXED
            }

            maxx = max(maxx , MAH(v));
        }

        return maxx;
    }
};