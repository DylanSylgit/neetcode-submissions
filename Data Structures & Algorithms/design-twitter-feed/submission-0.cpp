#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Twitter {
private:
    // pair: first = set of followeeIds, second = list of tweets {time, tweetId}
    using UserData = pair<unordered_set<int>, vector<pair<int, int>>>;
    
    unordered_map<int, UserData> info;
    int time_stamp;

public:
    Twitter() : time_stamp(0) {}

    void postTweet(int userId, int tweetId) {
        info[userId].second.push_back({time_stamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        using Tweet = pair<int, int>;
        priority_queue<Tweet, vector<Tweet>, greater<Tweet>> min_heap;

        unordered_set<int> authors = info[userId].first;
        authors.insert(userId);

        for (int authorId : authors) {
            const auto& posts = info[authorId].second;
            // Only need at most the last 10 tweets from each author
            int start = max(0, static_cast<int>(posts.size()) - 10);
            for (int i = start; i < posts.size(); ++i) {
                min_heap.push(posts[i]);
                if (min_heap.size() > 10) {
                    min_heap.pop();
                }
            }
        }

        vector<int> feed;
        while (!min_heap.empty()) {
            feed.push_back(min_heap.top().second);
            min_heap.pop();
        }

        reverse(feed.begin(), feed.end());
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        info[followerId].first.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        info[followerId].first.erase(followeeId);
    }
};