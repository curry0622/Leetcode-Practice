class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        vector<int> freq(26, 0);
        for (char c : s1) {
            freq[c - 'a']++;
        }

        int start = -1, end = -1;
        vector<int> tmp = freq;
        for (int i = 0; i < s2.size(); i++) {
            if (tmp[s2[i] - 'a'] > 0) {
                if (start >= end) {
                    start = i;
                }
                end = i + 1;
                tmp[s2[i] - 'a']--;
            } else if (freq[s2[i] - 'a'] > 0) {
                for (int j = start; j <= end; j++) {
                    if (s2[i] == s2[j]) {
                        start = j + 1;
                        break;
                    }
                    tmp[s2[j] - 'a']++;
                }
                end = i + 1;
            } else {
                start = end;
                tmp = freq;
            }

            if (end - start == s1.size()) {
                return true;
            }
        }

        return false;
    }
};

// abbc
// eecbbbca