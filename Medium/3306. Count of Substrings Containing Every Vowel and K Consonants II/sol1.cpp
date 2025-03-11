class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long res = 0;
        int n = word.size();
        int start = 0, end = 0;
        unordered_map<char, int> vowel;
        int consonant = 0;
        vector<int> nextC(n, n);
        int nextConsonantIndex = n;
        for (int i = n-1; i > 0; i--) {
            nextC[i] = nextConsonantIndex;
            if (!isVowel(word[i])) {
                nextConsonantIndex = i;
            }
        }
        while (end < n) {
            char lastC = word[end];
            if (isVowel(lastC)) {
                vowel[lastC]++;
            } else {
                consonant++;
            }
            while (consonant > k) {
                char startC = word[start];
                if (isVowel(startC)) {
                    vowel[startC]--;
                    if (vowel[startC] == 0) {
                        vowel.erase(startC);
                    }
                } else {
                    consonant--;
                }
                start++;
            }
            while (start < n && vowel.size() == 5 && consonant == k) {
                res += nextC[end] - end;
                char startC = word[start];
                if (isVowel(startC)) {
                    vowel[startC]--;
                    if (vowel[startC] == 0) {
                        vowel.erase(startC);
                    }
                } else {
                    consonant--;
                }
                start++;
            }
            end++;
        }
        return res;
    }

    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
};