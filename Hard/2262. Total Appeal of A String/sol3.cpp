class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0;
        int n = s.size();
        vector<int> lastIndex(26, -1);

        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < n; j++) {
                if(s[j] == char(i + 97)) {
                    lastIndex[i] = j;
                }
                ans += lastIndex[i] + 1;
            }
        }

        return ans;
    }
};