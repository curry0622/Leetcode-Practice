class Solution {
public:
    vector<vector<int>> costTable;
    int range;

    int getMoneyAmount(int n) {
        vector<int> vec(n + 1, -1);
        costTable = vector<vector<int>>(n + 1, vec);
        range = n;
        return costFunc(1, n);
    }

    int getCostTable(int a, int b) {
        if(a < 1 || a > range || b < 1 || b > range)
            return 0;
        return costTable[a][b];
    }

    void setCostTable(int a, int b, int val) {
        if(a < 1 || a > range || b < 1 || b > range)
            return;
        costTable[a][b] = val;
    }

    int costFunc(int min, int max) {
        if(min > max)
            return 0;
        if(min == max) {
            setCostTable(min, max, 0);
            return 0;
        }
        int minCost;
        for(int i = min; i <= max; i++) {
            // i is current root
            int cost = i, left, right;
            int getLeft = getCostTable(min, i - 1);
            int getRight = getCostTable(i + 1, max);

            if(getLeft != -1) {
                left = getLeft;
            } else {
                left = costFunc(min, i - 1);
            }
            if(getRight != -1) {
                right = getRight;
            } else {
                right = costFunc(i + 1, max);
            }

            cost += getMax(left, right);
            if(i == min) {
                minCost = cost;
            }
            else if(minCost > cost) {
                minCost = cost;
            }
        }
        setCostTable(min, max, minCost);
        return minCost;
    }

    int getMax(int a, int b) {
        if(a > b)
            return a;
        return b;
    }
};