class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        int ans = 0;
        for(int i = 1; i < t.size(); i++) {
            int diff = t[i] - t[i - 1];
            if(diff > d) {
                ans += d;
            } else {
                ans += diff;
            }
        }
        return ans + d;
    }
};