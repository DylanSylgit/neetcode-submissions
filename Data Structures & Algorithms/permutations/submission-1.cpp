class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        std::vector<int> curr{};
        for (int i = 0; i < nums.size(); i ++) {
            curr.push_back(nums[i]);
            dfs(curr,ret,nums,0);
            curr.pop_back();
        }

        return ret;
    }
    void dfs(std::vector<int>& curr, std::vector<std::vector<int>>& ret, const std::vector<int> nums,int idx) {

        if (curr.size() == nums.size()) {
            ret.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (std::find(curr.begin(),curr.end(),nums[i]) != curr.end()) {
                continue;
            }
            curr.push_back(nums[i]);
            dfs(curr,ret,nums,i);
            curr.pop_back();
        }

    }
};
