class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> lScore(n, 0);
        vector<int> rScore = lScore;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt++;
            }
            lScore[i] = cnt;
        }
        cnt = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '1') {
                cnt++;
            }
            rScore[i] = cnt;
        }
        int maxScore = INT_MIN;
        for (int i = 0; i < n-1; i++) {
            maxScore = max(maxScore, lScore[i] + rScore[i+1]);
        }
        return maxScore;
    }
};