class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        stack<int>st;
        vector<int>ans;
        for(int i=tem.size()-1 ;i>=0 ;i--){
            if(st.empty()){
                ans.push_back(0);
                cout<<i;
            }
            else{
                while(!st.empty() && tem[st.top()] <= tem[i]){
                    st.pop();

                }
                if(st.empty()){
                    ans.push_back(0);
                }else{
                    ans.push_back(st.top()-i);
                }
            }
            st.push(i);
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};