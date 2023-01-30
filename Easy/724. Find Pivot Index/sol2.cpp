class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rSum = accumulate(nums.begin(), nums.end(), 0);
        int lSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            rSum -= nums[i];
            if (rSum == lSum)
                return i;
            lSum += nums[i];
        }
        return -1;
    }
};