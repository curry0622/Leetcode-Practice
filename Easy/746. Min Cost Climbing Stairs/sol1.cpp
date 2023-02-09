class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minCost(n+1, 0);
        for (int i = 2; i <= n; i++) {
            minCost[i] = min(minCost[i-2]+cost[i-2], minCost[i-1]+cost[i-1]);
        }
        return minCost.back();
    }
};

// index:      0, 1, 2
// cost:     [10,15,20]
// minCost:    0, 0,10, 15