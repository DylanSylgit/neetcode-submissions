class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        dfs(nums,ret,0);
        return ret;
    }
    void dfs(std::vector<int>& nums, std::vector<std::vector<int>>& res, int idx) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            std::swap(nums[i],nums[idx]);
            dfs(nums,res,idx+1);
            std::swap(nums[i],nums[idx]);
        }

    }
};
