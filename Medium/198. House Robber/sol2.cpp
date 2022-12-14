class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            nums[i] = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = nums[i];
        }

        return nums.back();
    }
};