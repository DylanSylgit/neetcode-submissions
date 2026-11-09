class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ret;
        std::vector<int> curr;
        std::sort(candidates.begin(),candidates.end());
        dfs(0,target,candidates,ret,curr,0);
        return ret;
    }
    void dfs(int i, int& target, std::vector<int>&candidates, std::vector<std::vector<int>>& ret, std::vector<int>& curr, int add) {
        if (add == target) {
            ret.push_back(curr);
            return;
        }

        for (int idx = i; idx < candidates.size(); idx++) {
            if (add + candidates[idx] > target) {break;}

            if (idx > i and candidates[idx] == candidates[idx-1]) {continue;}

            if (add < target) {
                curr.push_back(candidates[idx]);
                dfs(idx+1,target,candidates,ret,curr,add+candidates[idx]);
                curr.pop_back();
            }
        }
    }
};
