class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> players;

        // Init players
        for (int i = 0; i < n; i++) {
            players.push_back({ages[i], scores[i]});
        }

        // Sort players by score
        sort(players.begin(), players.end(), less<>());

        // DP
        int ans = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int score = players[i].second;
            dp[i] = score;

            for (int j = 0; j < i; j++) {
                if (players[j].second <= score) {
                    dp[i] = max(dp[i], dp[j] + score);
                }
            }

            ans = max(dp[i], ans);
        }

        return ans;
    }
};