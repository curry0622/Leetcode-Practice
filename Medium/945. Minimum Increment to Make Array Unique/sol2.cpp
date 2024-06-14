class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int target = 0;
        for (int n : nums) {
            res += max(target-n, 0);
            target = max(n, target)+1;
        }
        return res;
    }
};