class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0;
        int n = s.size(), curr = 0;
        vector<int> lastIndex(26, -1);

        for(int i = 0; i < n; i++) {
            curr += i - lastIndex[s[i] - 'a'];
            lastIndex[s[i] - 'a'] = i;
            ans += curr;
        }

        return ans;
    }
};