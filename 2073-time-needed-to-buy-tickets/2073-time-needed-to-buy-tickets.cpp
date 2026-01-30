class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        for(int i=0;i<tickets.size();i++){
            q.push(i);
        }
        int count = 0;

        while(tickets[k]!=0){
            if(tickets[q.front()]){
                tickets[q.front()]-=1;
                
                count++;
            }
            int x = q.front();
                q.pop();
                q.push(x);
            
        }
        return count;
    }
    
};