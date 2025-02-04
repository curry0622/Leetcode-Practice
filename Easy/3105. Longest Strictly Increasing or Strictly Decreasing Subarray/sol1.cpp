class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() >= 2) {
            int lastStat = status(nums[0], nums[1]);
            int len = lastStat == 0 ? 1 : 2;
            int maxLen = len;
            for (int i = 2; i < nums.size(); i++) {
                int currStat = status(nums[i-1], nums[i]);
                if (currStat == lastStat && lastStat != 0) {
                    len++;
                } else if (currStat == 0) {
                    len = 1;
                } else {
                    len = 2;
                }
                lastStat = currStat;
                maxLen = max(len, maxLen);
            }
            return maxLen;
        }
        return 1;
    }

    int status(int prev, int curr) {
        if (prev < curr)
            return -1;
        if (prev == curr)
            return 0;
        return 1;
    }
};