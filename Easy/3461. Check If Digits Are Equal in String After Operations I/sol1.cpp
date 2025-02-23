class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string tmp = "";
            for (int i = 1; i < s.size(); i++) {
                int sum = ((s[i] - '0') + (s[i - 1] - '0')) % 10;
                tmp += to_string(sum);
            }
            s = tmp;
        }
        return s[0] == s[1];
    }
};