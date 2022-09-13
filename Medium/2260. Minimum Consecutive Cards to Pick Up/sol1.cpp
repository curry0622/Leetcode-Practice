class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, vector<int>> record;
        int ans = INT_MAX;

        for(int i = 0; i < cards.size(); i++) {
            if(record.find(cards[i]) == record.end()) {
                record[cards[i]] = vector<int>{i};
            } else {
                int tmp = record[cards[i]].back();
                record[cards[i]].push_back(i);
                if(ans > record[cards[i]].back() - tmp) {
                    ans = record[cards[i]].back() - tmp;
                }
            }
        }

        if(ans == INT_MAX)
            return -1;
        return ans + 1;
    }
};