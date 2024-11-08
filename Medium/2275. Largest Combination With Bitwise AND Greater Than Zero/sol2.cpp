class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int mx = pow(2, maximumBit)-1;
        int xorVal = 0;
        for (int i = 0; i < n; i++) {
            xorVal ^= nums[i];
        }
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            res[i] = mx ^ xorVal;
            xorVal ^= nums[n-1-i];
        }
        return res;
    }
};