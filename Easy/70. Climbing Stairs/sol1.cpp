class Solution {
public:
    vector<int> record;

    Solution() {
        record = vector<int>(46, -1);
        record[1] = 1;
        record[2] = 2;
    }

    int climbStairs(int n) {
        if(record[n] != -1)
            return record[n];
        record[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return record[n];
    }
};