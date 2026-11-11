class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        std::string curr;
        dfs(ret,curr,n,0,0);
        return ret;
    }
    void dfs(vector<string>& ret, string& curr, const int& n, int open, int close) {
        if (curr.size() == n*2) {ret.push_back(curr); return;}

        if (open < n) {
            curr.push_back('(');
            dfs(ret,curr,n,open+1,close);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            dfs(ret,curr,n,open,close+1);
            curr.pop_back();
        }


    }
};
