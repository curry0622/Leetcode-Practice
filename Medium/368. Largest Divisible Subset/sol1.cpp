class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = 0;
        int maxLen = 1;
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        maxIdx = i;
                    }
                }
            }
        }
        vector<int> res;
        res.push_back(nums[maxIdx]);
        int len = maxLen - 1;
        int idx = maxIdx - 1;
        int lastIdx = maxIdx;
        while (len > 0) {
            if (dp[idx] == len && nums[lastIdx] % nums[idx] == 0) {
                res.push_back(nums[idx]);
                lastIdx = idx;
                len--;
            }
            idx--;
        }
        return res;
    }
};