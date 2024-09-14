class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (maxVal < nums[i]) {
                maxVal = nums[i];
            }
        }
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxVal)
                cnt++;
            else {
                res = max(res, cnt);
                cnt = 0;
            }
        }
        res = max(res, cnt);
        return res;
    }
};