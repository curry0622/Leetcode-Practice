class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;
        string res = "";
        for (char c : s) {
            if (isdigit(c) && isalpha(stk.top())) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};