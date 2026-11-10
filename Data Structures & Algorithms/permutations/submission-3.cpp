class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        std::vector<int> curr{};
        std::vector<bool> used(nums.size(),false);
        dfs(curr,ret,nums,used);


        return ret;
    }
    void dfs(std::vector<int>& curr, std::vector<std::vector<int>>& ret, const std::vector<int>& nums,std::vector<bool>& used) {

        if (curr.size() == nums.size()) {
            ret.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) {continue;}
            curr.push_back(nums[i]);
            used[i] = true;
            dfs(curr,ret,nums,used);
            curr.pop_back();
            used[i] = false;
        }

    }
};
