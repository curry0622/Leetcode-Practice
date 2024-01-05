class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for (int n : nums) {
            if (LIS.empty() || LIS.back() < n)
                LIS.push_back(n);
            else {
                auto iter = lower_bound(LIS.begin(), LIS.end(), n);
                *iter = n;
            }
        }
        return LIS.size();
    }
};