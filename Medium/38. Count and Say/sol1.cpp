class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string str = countAndSay(n - 1);
        string res = "";
        int len = 1;
        char curr = str[0];
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == curr) {
                len++;
            } else {
                res += to_string(len) + str[i - 1];
                len = 1;
                curr = str[i];
            }
        }
        res += to_string(len) + str.back();
        return res;
    }
};

// dp[1] = 1
// dp[2] = 11
// dp[3] = 21
// dp[4] = 1211
// dp[5] = 111221
// dp[6] = 312211