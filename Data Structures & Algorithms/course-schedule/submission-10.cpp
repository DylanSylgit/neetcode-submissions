using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses); // i = course, adj[i] = prereqs

        for (int i = 0; i < prerequisites.size(); i ++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        unordered_set<int> hash;

        for (int course = 0; course < adj.size(); course++) {
            bool cheese = true;
            dfs(adj,hash,course,cheese);
            if (cheese == false) return false;
        }

        return true;
    }

    void dfs(vector<vector<int>>& adj, unordered_set<int>& hash, int course, bool& cheese) {
        if (hash.find(course) != hash.end()){
            cheese = false;
            return;
        }

        hash.insert(course);

        if (adj[course].size() == 0) {
            hash.erase(course);
            return;
        }

        for (int pre : adj[course]) {
            dfs(adj,hash,pre,cheese);
        }
        hash.erase(course);
        adj[course].clear();
    }
};
