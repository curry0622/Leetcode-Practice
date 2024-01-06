class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n, 0);
        dp[n-1] = jobs.back()[2];

        for (int i = n-2; i >= 0; i--) {
            int endTime = jobs[i][1];
            int profit = jobs[i][2];

            auto iter = lower_bound(jobs.begin(), jobs.end(), vector<int>{endTime, endTime, 0});
            if (iter != jobs.end()) {
                int j = distance(jobs.begin(), iter);
                dp[i] = max(dp[i+1], profit+dp[j]);
            } else {
                dp[i] = max(dp[i+1], profit);
            }
        }

        return dp[0];
    }
};