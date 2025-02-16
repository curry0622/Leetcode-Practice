class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (((i-k<0) || ((i-k>=0) && (nums[i]>nums[i-k]))) &&
                ((i+k>=n) || ((i+k<n) && (nums[i]>nums[i+k])))) {
                sum += nums[i];
            }
        }
        return sum;
    }
};