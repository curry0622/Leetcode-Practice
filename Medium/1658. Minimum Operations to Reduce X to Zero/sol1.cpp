class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int n : nums)
            totalSum += n;

        int targetSum = totalSum - x;
        int currSum = 0;
        int maxLen = -1;
        // cout << "total: " << totalSum << ", target: " << targetSum << endl;

        for (int l = 0, r = 0; r < nums.size(); r++) {
            currSum += nums[r];
            while (l <= r && currSum > targetSum) {
                currSum -= nums[l];
                l++;
            }
            // cout << "L: " << l << ", R: " << r << ", curr: " << currSum << endl;
            if (currSum == targetSum) {
                maxLen = max(maxLen, r - l + 1);
            }
        }

        if (maxLen == -1)
            return -1;
        return nums.size() - maxLen;
    }
};