class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        vector<int> cnt(k);
        cnt[0] = 1;
        for (const int& num : nums) {
            sum = (sum + num % k + k) % k;
            ans += cnt[sum];
            cnt[sum]++;
        }
        return ans;
    }
};