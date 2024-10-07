class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (char c : s) {
            char top = '-';
            if (stk.size() > 0) top = stk.top();
            if ((top == 'A' && c == 'B') || (top == 'C' && c == 'D')) {
                stk.pop();
                continue;
            }
            stk.push(c);
        }
        return stk.size();
    }
};