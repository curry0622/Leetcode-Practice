class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto first0 = lower_bound(nums.begin(), nums.end(), 0);
        auto firstPos = upper_bound(nums.begin(), nums.end(), 0);
        return max((first0 - nums.begin()), (nums.end() - firstPos));
    }
};