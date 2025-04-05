class Solution {
int res = 0;
public:
    int subsetXORSum(vector<int>& nums) {
        backtracking(nums, 0, 0);
        return res;
    }

    void backtracking(vector<int>& nums, int i, int curr) {
        if (i >= nums.size()) {
            res += curr;
            return;
        }
        backtracking(nums, i + 1, curr ^ nums[i]);
        backtracking(nums, i + 1, curr);
    }
};