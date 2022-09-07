class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices.at(i) - prices.at(i - 1) > 0)
                ans += prices.at(i) - prices.at(i - 1);
        }
        return ans;
    }
};

/* TLE version with DP + Array recording */
// class Solution {
// public:
//     vector<vector<int>> record;
//     vector<int> prices;

//     int maxProfit(vector<int>& p) {
//         prices = p;
//         int n = p.size();
//         record = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
//         return profit(0, n);
//     }

//     int profit(int l, int r) {
//         if(record[l][r] != -1)
//             return record[l][r];
//         if(r - l <= 1) {
//             record[l][r] = 0;
//             return 0;
//         }
//         int max = prices[r - 1] - prices[l];
//         for(int i = l + 1; i < r; i++) {
//             int tmp = profit(l, i) + profit(i, r);
//             if(tmp > max)
//                 max = tmp;
//         }
//         record[l][r] = max;
//         return max;
//     }
// };