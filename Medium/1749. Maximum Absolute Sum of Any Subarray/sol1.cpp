class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            return max(abs(maxSubarraySum(nums)), abs(minSubarraySum(nums)));
        }

        int maxSubarraySum(vector<int>& nums) {
            int maxSum = 0;
            int currSum = 0;
            for (int n : nums) {
                currSum += n;
                maxSum = max(maxSum, currSum);
                currSum = max(currSum, 0);
            }
            return maxSum;
        }

        int minSubarraySum(vector<int>& nums) {
            int currSum = 0;
            int minSum = 0;
            for (int n : nums) {
                currSum += n;
                minSum = min(minSum, currSum);
                currSum = min(currSum, 0);
            }
            return minSum;
        }
};