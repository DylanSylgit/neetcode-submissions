class Solution {
public:
    std::unordered_map<char,string> m{
        {'1', " "}, {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"},
        {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        std::vector<string> ret;
        if (digits.size() == 0) {return ret;}
        string curr;
        dfs(ret,digits,curr,0);
        return ret;
    }

    void dfs(std::vector<string>& ret, string& digits, string& curr, int idx) {
        if (curr.size() == digits.size()) {
            ret.push_back(curr);
        }

        string candidates = m[digits[idx]];

        for (char ch : candidates) {
            curr.push_back(ch);
            dfs(ret,digits,curr,idx+1); // next character instead
            curr.pop_back();
        }
    }
};
