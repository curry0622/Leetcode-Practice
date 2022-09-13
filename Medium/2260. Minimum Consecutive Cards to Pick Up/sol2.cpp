class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> record;
        int ans = INT_MAX;

        for(int i = 0; i < cards.size(); i++) {
            if(record.find(cards[i]) == record.end()) {
                record[cards[i]] = i;
            } else {
                int last = record[cards[i]];
                record[cards[i]] = i;
                if(ans > record[cards[i]] - last) {
                    ans = record[cards[i]] - last;
                }
            }
        }

        if(ans == INT_MAX)
            return -1;
        return ans + 1;
    }
};