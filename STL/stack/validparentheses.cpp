// Link: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (int i = 0; i < s.size(); ++i) {
            if (parentheses.empty()) {
                parentheses.push(s[i]);
            }
            else {
                switch (s[i])
                {
                case ')':
                    if (parentheses.top() == '(')
                    {
                        parentheses.pop();
                    }
                    else parentheses.push(s[i]);
                    break;
                case '}':
                    if (parentheses.top() == '{')
                    {
                        parentheses.pop();
                    }
                    else parentheses.push(s[i]);
                    break;
                case ']':
                    if (parentheses.top() == '[')
                    {
                        parentheses.pop();
                    }
                    else parentheses.push(s[i]);
                    break;
                default:
                    parentheses.push(s[i]);
                    break;
                }
            }
        }
        return parentheses.empty();
    }
};