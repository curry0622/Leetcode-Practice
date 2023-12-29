class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c))
                vowels.push_back(c);
        }
        int len = s.length();
        for (int i = 0, j = vowels.size()-1; i < len; i++) {
            if (isVowel(s[i]))
                s[i] = vowels[j--];
        }
        return s;
    }

    bool isVowel(char c) {
        if (
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c =='U'
        )
            return true;
        return false;
    }
};