class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losts;
        for (auto match : matches) {
            int winner = match[0];
            int loser = match[1];
            if (losts.find(winner) == losts.end())
                losts[winner] = 0;
            losts[loser]++;
        }

        vector<int> lose0, lose1;
        for (auto iter = losts.begin(); iter != losts.end(); iter++) {
            int player = iter->first;
            int lostNum = iter->second;
            if (lostNum == 0)
                lose0.push_back(player);
            if (lostNum == 1)
                lose1.push_back(player);
        }

        return {lose0, lose1};
    }
};