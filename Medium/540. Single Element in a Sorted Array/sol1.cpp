class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l < r) {
            int m = (l + r) / 2;
            if(nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) {
                return nums[m];
            }
            if(nums[m] == nums[m - 1]) {
                if(m % 2 == 0) {
                    r = m - 2;
                } else {
                    l = m + 1;
                }
            }
            if(nums[m] == nums[m + 1]) {
                if(m % 2 == 0) {
                    l = m + 2;
                } else {
                    r = m - 1;
                }
            }
        }

        return nums[l];
    }
};