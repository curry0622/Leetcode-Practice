class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = 0;
        double curr = 0;
        for (int i = 0; i <= nums.size()-k; i++) {
            if (i == 0) {
                for (int j = 0; j < k; j++)
                    curr += nums[j];
                maxAvg = curr;
            } else {
                curr -= nums[i-1];
                curr += nums[i+k-1];
                maxAvg = max(maxAvg, curr);
            }
        }
        return maxAvg / k;
    }
};
