class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int res = 0;
        stack<int> stk;
        for (int i = 0; i < nums.size(); i++) {
            if (stk.empty() || nums[stk.top()] > nums[i])
                stk.push(i);
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] >= nums[stk.top()]) {
                res = max(res, i - stk.top());
                stk.pop();
            }
        }
        return res;
    }
};