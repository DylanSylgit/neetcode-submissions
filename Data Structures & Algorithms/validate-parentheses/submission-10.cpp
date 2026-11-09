class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char,char> m = {
            {'}','{'}, {']','['}, {')','('}
        };
        std::stack<char> st;
        for (char c : s) {
            if (!m.contains(c)) {
                st.push(c);
            }
            else {
                if (st.empty() or st.top() != m[c]){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
