class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 1;
        int l = 0, r = 0;
        for (int i = 1; i < nums.size(); i++) {
            bool isValid = true;
            int lastInvalidIndex = l;
            for (int j = l; j <= r; j++) {
                if (nums[i] & nums[j]) {
                    isValid = false;
                    lastInvalidIndex = j;
                }
            }
            if (isValid) {
                r = i;
                res = max(res, r - l + 1);
            } else {
                l = lastInvalidIndex + 1;
                r = i;
            }
        }
        return res;
    }
};