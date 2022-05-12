class Solution {
public:
    void filter(string& str) {
        for(int i = 0; i < str.size(); i++) {
            char c = str[i];
            if(!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'))) {
                str.erase(i, 1);
                i--;
            }
            if('A' <= c && c <= 'Z') {
                str[i] = tolower(c);
            }
        }
    }

    bool isPalindrome(string s) {
        filter(s);
        string r = s;
        reverse(r.begin(), r.end());
        return s.compare(r) == 0;
    }
};