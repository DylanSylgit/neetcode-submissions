class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        std::vector<int> v{};

        dfs(0,v, nums,ret);

        return ret;
        
    }

    void dfs(int i, std::vector<int>& curr, const std::vector<int>& nums,std::vector<std::vector<int>>& ret){
        ret.push_back(curr);
        for (i; i < nums.size(); i ++) {
            curr.push_back(nums[i]);
            dfs(i+1, curr, nums,ret);
            curr.pop_back();
        }
    }
};
