class Solution {
public:
    int mx = 0;
    int res = 0;
    int countMaxOrSubsets(vector<int>& nums) {
        for (int n : nums) {
            mx |= n;
        }

        int curr = 0;
        backtracking(nums, 0, curr);

        return res;
    }

    void backtracking(vector<int>& nums, int start, int curr) {
        if (curr == mx)
            res++;

        for (int i = start; i < nums.size(); i++) {
            backtracking(nums, i + 1, curr | nums[i]);
        }
    }
};