class Solution {
public:
    vector<string> restoreIpAddresses(string str) {
        vector<string> ans;
        stack<string> stk;
        cut(str, stk, ans);
        return ans;
    }

    void cut(const string& str, stack<string>& stk, vector<string>& ans) {
        if (stk.size() == 4) {
            if (str.size() == 0) {
                stack tmp_stk = stk;
                string tmp_str = "";
                for (int i = 0; i < 3; i++) {
                    tmp_str = "." + tmp_stk.top() + tmp_str;
                    tmp_stk.pop();
                }
                tmp_str = tmp_stk.top() + tmp_str;
                tmp_stk.pop();
                ans.push_back(tmp_str);
            }
            return;
        }

        int max = str[0] == '0' ? 1 : 3;
        for (int i = 1; i < str.size() + 1 && i <= max; i++) {
            string sub = str.substr(0, i);
            if (stoi(sub) <= 255) {
                stk.push(sub);
                cut(str.substr(i), stk, ans);
                stk.pop();
            }
        }
    }
};