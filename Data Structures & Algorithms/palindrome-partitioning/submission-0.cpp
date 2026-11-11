class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<vector<string>> ret;
        std::vector<string> curr;

        backTrack(ret,curr,s,0);
        return ret;
    }

    void backTrack(std::vector<vector<string>>& ret, std::vector<string>& curr, string& s, int start) {
        if (start == s.size()) {
            ret.push_back(curr);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPali(s,start,end)) {
                curr.push_back(s.substr(start,end-start +1));
                backTrack(ret,curr,s,end+1);
                curr.pop_back();
            }
        }

    }

    bool isPali (string& str, int l, int r) {
        while (l <= r) {
            if (str[l] != str[r]) {
                return false;
            }
            l ++;
            r --;
        }
        return true;
    }
};
