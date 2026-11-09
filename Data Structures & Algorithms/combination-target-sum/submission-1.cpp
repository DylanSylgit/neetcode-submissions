class Solution {
private:
    int target;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        this->target = target;
        std::vector<int> curr;
        dfs(0,0,nums,res,curr);

        return res;
    }

    void dfs(int start, int add, std::vector<int>& nums,
    std::vector<std::vector<int>>& res, std::vector<int> curr) {
        if (add == target) {
            res.push_back(curr);
        }

        for (; start < nums.size(); start++) {
            if (add < target) {
                curr.push_back(nums[start]);
                dfs(start,add+nums[start],nums,res,curr);
            }
            curr.pop_back();
        }
    }
};
