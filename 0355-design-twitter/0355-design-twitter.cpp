class MaxHeap{
        public:
            int time;
            int tweetId;
            int followeeId;
            int index;
        MaxHeap(int t, int tId,int fId,int i){
            this->time = t;
            this->tweetId = tId;
            this->followeeId = fId;
            this->index = i;
        }
        bool operator<(const MaxHeap& other) const {
        return time < other.time;
        }
    };

class Twitter {
public:
    map<int,set<int>>followMap;
    map<int,vector<pair<int,int>>>tweetMap;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweetMap[userId].push_back({tweetId,time});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<MaxHeap>pq;
        unordered_set<int> userIds(followMap[userId].begin(), followMap[userId].end());
        userIds.insert(userId); // <--- User sees their own tweets

    for (int followee : userIds) {
        if (!tweetMap[followee].empty()) {
            int index = tweetMap[followee].size() - 1;
            int tTime = tweetMap[followee][index].second;
            int tId = tweetMap[followee][index].first;
            pq.push(MaxHeap{tTime, tId, followee, index - 1});
        }
    }
        while(!pq.empty() && result.size()<10){
            int tweetId = pq.top().tweetId;
            int index = pq.top().index;
            int followeeId = pq.top().followeeId;
            int time = pq.top().time;
            result.push_back(tweetId);
            pq.pop();
            if(index>=0){
                time = tweetMap[followeeId][index].second;
                tweetId = tweetMap[followeeId][index].first;
                pq.push(MaxHeap{time,tweetId,followeeId,index-1});
            }
        }
        return result;
        
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (followMap[followerId].find(followeeId) != followMap[followerId].end()) {
            followMap[followerId].erase(followeeId);
        }
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