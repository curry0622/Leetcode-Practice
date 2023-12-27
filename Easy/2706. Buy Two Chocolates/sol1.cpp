class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int orgMoney = money;
        int minVal = INT_MAX;
        int minIdx = -1;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minVal) {
                minVal = prices[i];
                minIdx = i;
            }
        }
        money -= minVal;

        int lastMinIdx = minIdx;
        minVal = INT_MAX;
        minIdx = -1;
        for (int i = 0; i < prices.size(); i++) {
            if (i != lastMinIdx && prices[i] < minVal) {
                minVal = prices[i];
                minIdx = i;
            }
        }
        money -= minVal;

        return money >= 0 ? money : orgMoney;
    }
};