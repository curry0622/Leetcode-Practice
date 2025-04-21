class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; i++) {
            char curr = res[0];
            int cnt = 1;
            string tmp = "";
            for (int j = 1; j < res.size(); j++) {
                if (res[j] == curr) cnt++;
                else {
                    tmp += to_string(cnt) + string(1, curr);
                    curr = res[j];
                    cnt = 1;
                }
            }
            tmp += to_string(cnt) + string(1, curr);
            res = tmp;
        }
        return res;
    }
};