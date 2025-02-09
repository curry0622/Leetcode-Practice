class Solution {
using ll = long long;
public:
    ll countBadPairs(vector<int>& nums) {
        ll n = nums.size();
        ll total = (n * n - n) / 2;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[nums[i]-i]++;
        }
        for (auto f : freq) {
            ll v = f.second;
            total -= (v * v - v) / 2;
        }
        return total;
    }
};