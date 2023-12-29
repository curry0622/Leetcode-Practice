class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        int lp = 0, rp = len-1;

        while (lp < rp) {
            while (lp < len && !isVowel(s[lp]))
                lp++;
            while (rp >= 0 && !isVowel(s[rp]))
                rp--;
            if (lp >= rp)
                break;
            swap(s[lp], s[rp]);
            lp++, rp--;
        }
        return s;
    }

    bool isVowel(char c) {
        if (
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
        )
            return true;
        return false;
    }
};