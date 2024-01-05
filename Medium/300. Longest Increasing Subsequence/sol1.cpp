class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> sortedNums(st.begin(), st.end());
        sort(sortedNums.begin(), sortedNums.end());
        return lengthOfLCS(nums, sortedNums);
    }

    int lengthOfLCS(const vector<int>& nums1, const vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<vector<int>> dp(len1, vector<int>(len2, 0));

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (nums1[i] == nums2[j]) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                } else {
                    if (i == 0 && j == 0) {
                        dp[i][j] = 0;
                    } else if(i == 0) {
                        dp[i][j] = dp[i][j-1];
                    } else if(j == 0) {
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }

        return dp[len1-1][len2-1];
    }
};