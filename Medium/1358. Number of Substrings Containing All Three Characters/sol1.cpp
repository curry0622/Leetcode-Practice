class Solution {
public:
    int numberOfSubstrings(string str) {
        int n = str.size();
        int start = 0, end = 0;
        int res = 0;
        unordered_map<char, int> freq;
        while (end < n) {
            freq[str[end]]++;
            while (isValid(freq)) {
                res += n - end;
                freq[str[start]]--;
                start++;
            }
            end++;
        }
        return res;
    }

    bool isValid(unordered_map<char, int>& freq) {
        return freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0;
    }
};