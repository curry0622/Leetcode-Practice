class Solution {
public:
    int res;
    int maxLength(vector<string>& arr) {
        res = 0;
        vector<int> cnt(26, 0);
        genCombinations(arr, cnt, 0);
        return res;
    }

    void genCombinations(const vector<string>& arr, vector<int>& curr, int start) {
        int len = 0;
        for (int i = 0; i < 26; i++) {
            if (curr[i] <= 1)
                len += curr[i];
            else {
                len = 0;
                break;
            }
        }
        res = max(res, len);

        for (int i = start; i < arr.size(); i++) {
            for (char c : arr[i]) {
                curr[c-'a']++;
            }
            genCombinations(arr, curr, i+1);
            for (char c : arr[i]) {
                curr[c-'a']--;
            }
        }
    }
};
