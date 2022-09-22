class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string tmp;

        for(int i = 0; i < s.size(); i++) {
            if(i == s.size() - 1) {
                tmp += s[i];
                for(int j = tmp.size() - 1; j >= 0; j--) {
                    ans += tmp[j];
                }
            } else if(s[i] == ' ') {
                for(int j = tmp.size() - 1; j >= 0; j--) {
                    ans += tmp[j];
                }
                ans += " ";
                tmp = "";
            } else {
                tmp += s[i];
            }
        }

        return ans;
    }
};