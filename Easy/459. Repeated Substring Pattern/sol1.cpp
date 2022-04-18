class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i <= s.length() / 2; i++) {
            // i: substring length
            string ss = s.substr(0, i);
            for(int j = 0; j <= s.length() - i; j += i) {
                string cut = s.substr(j, i);
                if(cut.compare(ss) != 0)
                    break;
                else if(j == s.length() - i)
                    return true;
            }
        }
        return false;
    }
};