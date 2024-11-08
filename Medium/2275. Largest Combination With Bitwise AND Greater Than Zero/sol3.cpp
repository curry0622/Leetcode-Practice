class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int mx = (1 << maximumBit)-1;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            mx ^= nums[i];
            res[n-1-i] = mx;
        }
        return res;
    }
};