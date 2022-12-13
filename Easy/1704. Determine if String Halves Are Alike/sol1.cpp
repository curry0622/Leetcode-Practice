class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.size();
        int l_cnt = 0, r_cnt = 0;

        for(int i = 0; i < len; i++) {
            if(i < len / 2) {
                l_cnt += isVowel(s[i]) ? 1 : 0;
            } else {
                r_cnt += isVowel(s[i]) ? 1 : 0;
            }
        }

        return l_cnt == r_cnt;
    }

    bool isVowel(char c) {
        if(c == 'a' || c == 'A')
            return true;
        if(c == 'e' || c == 'E')
            return true;
        if(c == 'i' || c == 'I')
            return true;
        if(c == 'o' || c == 'O')
            return true;
        if(c == 'u' || c == 'U')
            return true;
        return false;
    }
};