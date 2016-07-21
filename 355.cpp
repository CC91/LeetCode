// 355. Design Twitter

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        stamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].insert({stamp++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        map<int, int> top10;
        for (auto it = connections[userId].begin(); it != connections[userId].end(); it++) {
            for (auto a = tweets[*it].begin(); a != tweets[*it].end(); a++) {
                if (top10.size() > 10 && top10.begin() -> first > a -> first) {
                    break;
                }
                top10.insert({a -> first, a -> second});
                if (top10.size() > 10) {
                    top10.erase(top10.begin());
                }
            }
        }
        for (auto it = top10.rbegin(); it != top10.rend(); it++) {
            res.push_back(it -> second);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        connections[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            connections[followerId].erase(followeeId);
        }
    }
    
private:
    int stamp;
    unordered_map<int, set<int>> connections;
    unordered_map<int, map<int, int>> tweets;
};



class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        stamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].push_back({stamp++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto it = connections[userId].begin(); it != connections[userId].end(); it++) {
            for (auto a = tweets[*it].begin(); a != tweets[*it].end(); a++) {
                if (q.size() > 10 && q.top().first > a -> first) {
                    break;
                }
                q.push(*a);
                if (q.size() > 10) {
                    q.pop();
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        connections[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            connections[followerId].erase(followeeId);
        }
    }

private:
    int stamp;
    unordered_map<int, set<int>> connections;
    unordered_map<int, vector<pair<int, int>>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */