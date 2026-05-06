class Twitter {
private:
    int time;
    unordered_map<int, set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
public:
    Twitter() : time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // tweets from user
        vector<pair<int, int>> feed = tweets[userId];

        // add all the tweets from the people the user follows too
        for (auto followeeId : following[userId]) {
            feed.insert(feed.end(), tweets[followeeId].begin(), tweets[followeeId].end());
        }

        // sort them with decreasing times
        sort(feed.begin(), feed.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        });

        vector<int> ans;
        for (auto [time, tweetId] : feed) {
            if (ans.size() == 10) break;

            ans.push_back(tweetId);
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
