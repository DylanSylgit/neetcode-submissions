class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        std::vector<int> curr;
        std::sort(nums.begin(),nums.end());
        dfs(nums,ret,curr,0);
        return ret;
    }
    void dfs(std::vector<int>& nums, std::vector<std::vector<int>>& ret, std::vector<int>& curr, int idx) {
        ret.push_back(curr);

        for (int i = idx; i < nums.size(); i ++) {
            if (i > idx and nums[i] == nums[i - 1]) {continue;}
            curr.push_back(nums[i]);
            dfs(nums,ret,curr,i+1);
            curr.pop_back();
        }
    }
};
