class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        stack<char> stk;
        for (char c : s) {
            if (stk.size() == 0) {
                stk.push(c);
            } else if (stk.top() == '(' && c == ')') {
                stk.pop();
            } else if (stk.top() == '(' && c == '(') {
                stk.push(c);
            } else if (stk.top() == ')' && c == '(') {
                while (stk.size() > 0 && stk.top() == ')') {
                    stk.pop();
                    res++;
                }
                stk.push(c);
            } else {
                stk.push(c);
            }
        }
        res += stk.size();
        return res;
    }
};