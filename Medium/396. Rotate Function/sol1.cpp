class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int f = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += i * nums[i];
        }
        int res = f;
        for (int i = 1; i < n; i++) {
            f = f + sum - n * nums[n - i];
            res = max(res, f);
        }
        return res;
    }
};

// nums= 4,3,2,6, sum= 15
// f0 = 0*4 + 1*3 + 2*2 + 3*6 = 25
// f1 = 1*4 + 2*3 + 3*2 + 0*6 = f0 + sum - n*nums[n-1] = 25 + 15 - 24 = 16