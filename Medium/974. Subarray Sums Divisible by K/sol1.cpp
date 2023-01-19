// TLE
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();

        // Mod & Sum
        int sum = 0;
        for (int& num : nums) {
            num %= k;
            if(num < 0)
                num += k;
            sum += num;
            num = sum;
        }

        // O(n^2)
        for (int i = -1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum;
                if (i == -1) {
                    sum = nums[j];
                } else {
                    sum = nums[j] - nums[i];
                }
                if (sum % k == 0)
                    ans++;
            }
        }

        return ans;
    }
};