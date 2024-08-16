class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = INT_MIN;
        int minSoFar = arrays[0][0], maxSoFar = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++) {
            res = max(res, abs(arrays[i][0] - minSoFar));
            res = max(res, abs(arrays[i][0] - maxSoFar));
            res = max(res, abs(arrays[i].back() - minSoFar));
            res = max(res, abs(arrays[i].back() - maxSoFar));
            minSoFar = min(minSoFar, arrays[i][0]);
            maxSoFar = max(maxSoFar, arrays[i].back());
        }
        return res;
    }
};