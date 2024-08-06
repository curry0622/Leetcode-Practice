class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int res = 0;
        int cnt = 0;
        int times = 1;
        for (int f : freq) {
            if (cnt == 8) {
                times++;
                cnt = 0;
            }
            res += f * times;
            cnt++;
        }
        return res;
    }
};