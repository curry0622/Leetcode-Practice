class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int mx = pow(2, maximumBit)-1;
        vector<int> xors(n, 0);
        xors[0] = nums[0];
        for (int i = 1; i < n; i++) {
            xors[i] = nums[i] ^ xors[i-1];
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(mx ^ xors[n-1-i]);
        }
        return res;
    }
};