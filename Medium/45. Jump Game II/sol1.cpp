class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = min(i+nums[i], n-1);
        }
        int target = n-1, step = 0;
        while (target != 0) {
            for (int i = 0; i <= target; i++) {
                if (nums[i] >= target) {
                    step++;
                    target = i;
                    break;
                }
            }
        }
        return step;
    }
};