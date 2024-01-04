class Solution {
public:
    string decodeString(string str) {
        string res = "";
        stack<char> stk;
        for (const auto& c : str) {
            if (c == ']') {
                string subStr = "";
                while (stk.top() != '[') {
                    subStr = stk.top() + subStr;
                    stk.pop();
                }
                stk.pop(); // stk.top() = '['
                string num = "";
                while(!stk.empty() && isdigit(stk.top())) {
                    num = stk.top() + num;
                    stk.pop();
                }
                string tmpStr = copyStrNumTimes(subStr, stoi(num));
                for (const auto& tmpC : tmpStr) {
                    stk.push(tmpC);
                }
            } else {
                stk.push(c);
            }
        }
        while(!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }

    string copyStrNumTimes(const string& str, const int& num) {
        string res = "";
        for (int i = 0; i < num; i++) {
            res += str;
        }
        return res;
    }
};