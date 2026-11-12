using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ret;
        dfs(curr,ret,nums,0);

        return ret;
    }
    void dfs (vector<int>& curr, vector<vector<int>>& ret, vector<int>& nums, int idx) {
        ret.push_back(curr);

        for (int i = idx; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            dfs(curr,ret,nums,i+1);
            curr.pop_back();
        }
    }
};
