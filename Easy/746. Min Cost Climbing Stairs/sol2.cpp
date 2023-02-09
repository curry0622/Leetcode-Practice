class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int l1 = 0, l2 = 0;
        for (int i = 2; i <= n; i++) {
            int tmp = l1;
            l1 = min(l2+cost[i-2], l1+cost[i-1]);
            l2 = tmp;
        }
        return l1;
    }
};

// index:      0, 1, 2
// cost:     [10,15,20]
// minCost:    0, 0,10, 15