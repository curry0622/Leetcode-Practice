class Solution {
public:
    int num;

    vector<string> generateParenthesis(int n) {
        num = n;
        vector<string> ans;
        func(1, 0, "(", ans);
        return ans;
    }

    void func(int open, int close, string str, vector<string>& vec) {
        if(close == num) {
            vec.push_back(str);
            return;
        }
        if(open > 0) {
            func(open - 1, close + 1, str + ")", vec);
        }
        if(open + close < num) {
            func(open + 1, close, str + "(", vec);
        }
    }
};