class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<int> curr;
        std::vector<std::vector<int>> ret;
        std::sort(candidates.begin(),candidates.end());
        dfs(candidates,curr,ret,target,0,0);

        return ret;
    }
    void dfs(std::vector<int>& candidates, std::vector<int>& curr, std::vector<std::vector<int>>& ret, int target, int add, int idx) {
        if (add > target) {return;}
        if (add == target) {
            ret.push_back(curr);
        }

        for (int i = idx; i < candidates.size(); i ++) {
            if (i > idx and candidates[i] == candidates[i-1]) {continue;}
            curr.push_back(candidates[i]);
            dfs(candidates,curr,ret,target,add+candidates[i],i+1);
            curr.pop_back();
        }
    }
};
