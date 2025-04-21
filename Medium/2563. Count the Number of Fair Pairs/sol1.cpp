class Solution {
using ll = long long;
public:
    ll countFairPairs(vector<int>& nums, int lower, int upper) {
        ll res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int currL = lower - nums[i], currU = upper - nums[i];
            auto itL = lower_bound(nums.begin() + i + 1, nums.end(), currL);
            auto itU = upper_bound(nums.begin() + i + 1, nums.end(), currU);
            res += (itU - itL);
        }
        return res;
    }
};