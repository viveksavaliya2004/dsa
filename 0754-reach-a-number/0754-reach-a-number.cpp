class Solution {
public:
    int reachNumber(int target)
    {
        //time complexity: O(sqrt(target))
        //space complexity: O(1)

        //to store total distance covered
        int sum=0;
        //to track number of moves taken
        int moves=0;

        //symmetric for negative targets
        target=abs(target);

        while(true)
        {
            //taking next move
            moves++;
            //adding steps of current move to 'sum'
            sum=sum+moves;

            //if we crossed target and difference is even, solution possible: returning 'moves'
            if((sum>=target) && ((sum-target)%2==0))
                return moves;
        }
        //never reached (theoretically unreachable)
        return -1;
    }
};