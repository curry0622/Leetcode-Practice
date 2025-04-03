class Solution {
using ll = long long;
public:
    ll maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMax(n, 0);
        vector<int> postMax(n, 0);
        int mx = 0;
        for (int i = 1; i < n; i++) {
            mx = max(mx, nums[i-1]);
            preMax[i] = mx;
        }
        mx = 0;
        for (int i = n - 2; i >= 0; i--) {
            mx = max(mx, nums[i+1]);
            postMax[i] = mx;
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, 1LL * (preMax[i] - nums[i]) * postMax[i]);
        }
        return res;
    }
};