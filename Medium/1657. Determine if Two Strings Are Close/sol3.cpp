class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int freq1[26] = {0};
        int freq2[26] = {0};

        for (char c : word1) {
            freq1[c-'a']++;
        }
        for (char c : word2) {
            freq2[c-'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq1[i] == 0 && freq2[i] > 0)
                return false;
            if (freq2[i] == 0 && freq1[i] > 0)
                return false;
        }

        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                return false;
        }

        return true;
    }
};