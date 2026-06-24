class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n =stones.size();
        if(n == 1)return stones[0];

        priority_queue<int>pq;

        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }

        while(!pq.empty()){
            int size = pq.size();

            if(size == 1){
                int ans = pq.top();
                pq.pop();
                return ans;
            }else{
                int f = pq.top();
                pq.pop();
                int s = pq.top();
                pq.pop();

                
                    int z = abs(f - s);
                    pq.push(z);
                
            }
        }
       int ans = pq.top();
                pq.pop();
                return ans;
    }
};