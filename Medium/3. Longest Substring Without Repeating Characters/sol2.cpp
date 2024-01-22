class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); // there are 256 symbols in ascii
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (lastIndex[s[i]] > start)
                start = lastIndex[s[i]];
            lastIndex[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};

// 1. Ascii code can represent 256 symbols.
// 2. Variable "start" represent the first index before the starting index of the current substr.
// 3. Vector "lastIndex" keeps track of the last occurence index of the current char.
// 4. if (lastIndex[s[i]] > start) means that the current char exists in current substr.
// 5. "i-start" means the current substr length.