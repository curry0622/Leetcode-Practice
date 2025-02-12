class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int res = -1;
        vector<int> vec(100, 0);
        for (int n : nums) {
            if (vec[digitSum(n)] > 0) {
                res = max(res, n + vec[digitSum(n)]);
                vec[digitSum(n)] = max(vec[digitSum(n)], n);
            } else {
                vec[digitSum(n)] = n;
            }
        }
        return res;
    }

    int digitSum(int v) {
        int res = 0;
        while (v > 0) {
            res += v % 10;
            v /= 10;
        }
        return res;
    }
};
