class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int range = 2 * k + 1;
        vector<int> res(n, -1);

        if (n < range)
            return res;

        if (k == 0)
            return nums;

        long sum = 0;
        for (int i = 0; i < range; i++) {
            sum += nums[i];
        }
        res[k] = sum / range;

        for (int i = 0; i + range < n; i++) {
            sum -= nums[i];
            sum += nums[range + i];
            res[k + 1 + i] = sum / range;
        }

        return res;
    }
};