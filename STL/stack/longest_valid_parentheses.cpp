// Link: https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    inline int longestValidParentheses(string s) {
        int res = 0;
        stack<int> pos;
        pos.push(-1);
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                pos.push(i);
            else {
                pos.pop();
                if (pos.empty())
                    pos.push(i);
                else
                    res = max(res, (int)i - pos.top());
            }
        }
        return res;
    }
};