typedef pair<int,int> pi;
class Twitter {
    unordered_map<int,unordered_set<int>> following;
    unordered_map<int,vector<pi>> tweets;
    int k,t;
public:
    Twitter() {
        k=10;
        t=0;
        following.clear();
        tweets.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        t++;
        tweets[userId].push_back({t,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        //User's Tweets
        int n=tweets[userId].size();
        for(int i=n-1;i>=max(0,n-k);i--) pq.push(tweets[userId][i]);
        //Followee Tweets
        for(int f:following[userId]){
            n=tweets[f].size();
            for(int i=n-1;i>=max(0,n-k);i--) pq.push(tweets[f][i]);
            while(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            feed.push_back(pq.top().second);
            pq.pop();
        }
        reverse(feed.begin(),feed.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following[followerId].find(followeeId)==following[followerId].end()) return;
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */