class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<vector<int>> arr;
        for (auto v : intervals) {
            arr.push_back({v[0], 1});
            arr.push_back({v[1]+1, -1});
        }
        sort(arr.begin(), arr.end());
        int res = 0, curr = 0;
        for (auto a : arr) {
            res = max(res, curr += a[1]);
        }
        return res;
    }
};