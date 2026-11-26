using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);

        vector<bool> inAlready(numCourses,false);

        unordered_set<int> seen;
        vector<int> ret;

        for (int i = 0; i < prerequisites.size(); i++) {
            courses[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int course = 0; course < courses.size(); course++) {
            bool loop = false;
            dfs(prerequisites,courses,ret,seen,course,inAlready,loop);
            if (loop == true) return {};
        }

        return ret;


    }

    void dfs(vector<vector<int>>& prerequisites, vector<vector<int>>& courses, vector<int>& ret, unordered_set<int>& seen, int course, vector<bool>& inAlready, bool& loop) {

        // Check if loop
        if (seen.find(course) != seen.end()){
            loop = true;
            return;
        }

        if (inAlready[course] == true) {
            return;
        }

        seen.insert(course);

        if (courses[course].size() == 0 ) {
            ret.push_back(course);
            inAlready[course] = true;
            seen.erase(course);
            return;
        }


        for (int i = 0; i < courses[course].size(); i++) {
            dfs(prerequisites,courses,ret,seen,courses[course][i],inAlready,loop);
        }

        if (loop == false) {
            ret.push_back(course);
            courses[course].clear();
            inAlready[course] = true;
            seen.erase(course);
        }

    }
};
