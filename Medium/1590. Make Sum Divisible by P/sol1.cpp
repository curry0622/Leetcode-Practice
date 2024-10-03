class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<int> preSum(n, 0);
        vector<int> postSum(n, 0);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            preSum[i] = sum;
            sum += nums[i] % p;
            sum %= p;
        }
        if (sum % p == 0) return 0;
        for (int i = 0; i < n; i++) {
            postSum[i] = sum - preSum[i] - nums[i];
        }

        for (int len = 1; len < n; len++) {
            int remain = 0;
            for (int i = 0; i <= n - len; i++) {
                remain = preSum[i] + postSum[i + len - 1];
                if (remain % p == 0) return len;
            }
        }
        return -1;
    }
};

// 6,3,5,2
// 6: [][6][3,5,2]
// 3: [6][3][5,2]
// 5: [6,3][5][2]
// 2: [6,3,5][2][]