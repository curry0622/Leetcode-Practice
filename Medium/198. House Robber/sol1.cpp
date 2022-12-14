class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<bool> selected = vector<bool>(nums.size(), false);
        selected[nums.size() - 1] = true;
        if(nums[nums.size() - 2] < nums[nums.size() - 1]) {
            nums[nums.size() - 2] = nums[nums.size() - 1];
            selected[nums.size() - 2] = false;
        } else {
            selected[nums.size() - 2] = true;
        }

        for(int i = nums.size() - 3; i >= 0; i--) {
            if(selected[i + 1]) {
                if(nums[i] + nums[i + 2] > nums[i + 1]) {
                    nums[i] += nums[i + 2];
                    selected[i] = true;
                } else {
                    nums[i] = nums[i + 1];
                    selected[i] = false;
                }
            } else {
                nums[i] += nums[i + 2];
                selected[i] = true;
            }
        }

        return nums[0];
    }
};