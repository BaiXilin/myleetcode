class Twitter {
public:
    // a map that maps userId to the following userId
    unordered_map<int, unordered_set<int>> following;
    // a map that maps userId to tweets posted
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> userTweets;
    // tweet id does not represent temporal order, keep a timestamp
    int timestamp = 0;
    // a map to map timestamp to a tweetId
    unordered_map<int, int> tweetTimeMap;

    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        // since getNewsFeed would only retrieve 10 posts
        // keep the num of tweets stored in the max heap at and below 10
        userTweets[userId].push(timestamp);
        tweetTimeMap[timestamp] = tweetId;
        timestamp++;

        if(userTweets[userId].size() > 10)
            userTweets[userId].pop(); // want to pop the oldest tweet (with smallest timestamp)
    }

    vector<int> getNewsFeed(int userId) {
        // traverse all following users + userId itself
        queue<int> tweetBuffer;
        priority_queue<int, vector<int>, greater<int>> newsFeed;

        following[userId].insert(userId);
        for(auto & it : following[userId]) {
            while(!userTweets[it].empty()) {
                newsFeed.push(userTweets[it].top());
                tweetBuffer.push(userTweets[it].top());
                userTweets[it].pop(); // want to pop the oldest tweet (with smallest timestamp)

                if(newsFeed.size() > 10)
                    newsFeed.pop();
            }

            // put the news feed from buffer back to heap
            while(!tweetBuffer.empty()) {
                userTweets[it].push(tweetBuffer.front());
                tweetBuffer.pop();
            }
        }

        // convert max heap to sorted vector for returning
        vector<int> sortedNewsFeed;
        while(!newsFeed.empty()) {
            sortedNewsFeed.push_back(tweetTimeMap[newsFeed.top()]);
            newsFeed.pop();
        }

        // note that newFeed is a min heap so it returns the least recent tweet first
        // but we want the order to be from most recent to least recent. have to reverse the vector
        reverse(sortedNewsFeed.begin(), sortedNewsFeed.end());

        return sortedNewsFeed;
    }

    void follow(int followerId, int followeeId) {
        // followerId starts following followeeId
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        // followerId unfollows followeeId
        following[followerId].erase(followeeId);
    }
};
