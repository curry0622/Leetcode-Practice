class Solution {
public:
    int numDecodings(string s) {
        int a = 1;
        int b = s[0] == '0' ? 0 : 1;
        for(int i = 2; i <= s.size(); i++) {
            int c = 0;
            if(s[i - 1] != '0')
                c += b;
            if(s[i - 2] != '0' && 10 * (s[i - 2] - '0') + (s[i - 1] - '0') <= 26)
                c += a;
            a = b;
            b = c;
        }
        return b;
    }
};