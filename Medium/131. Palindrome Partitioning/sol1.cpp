class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        stack<string> stk;
        func(s, stk, ans);
        return ans;
    }

    void func(const string& str, stack<string>& stk, vector<vector<string>>& ans) {
        if (str.size() == 0) {
            vector<string> vec;
            stack<string> tmp = stk;
            while(!tmp.empty()) {
                vec.push_back(tmp.top());
                tmp.pop();
            }
            reverse(vec.begin(), vec.end());
            ans.push_back(vec);
            return;
        }

        for (int i = 1; i < str.size() + 1; i++) {
            string sub = str.substr(0, i);
            string rev = sub;
            reverse(rev.begin(), rev.end());
            cout << sub << " " << rev << endl;

            if (sub == rev) {
                stk.push(sub);
                func(str.substr(i), stk, ans);
                stk.pop();
            }
        }
    }
};