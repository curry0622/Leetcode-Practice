class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cddts, int target) {
        sort(cddts.begin(), cddts.end());
        vector<vector<int>> res;
        vector<int> comb;
        backtracking(cddts, 0, target, comb, res);
        return res;
    }

    void backtracking(const vector<int>& cddts, int start, int target, vector<int>& comb, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        for (int i = start; i < cddts.size(); i++) {
            if (i > start && cddts[i] == cddts[i-1])
                continue;
            if (cddts[i] > target)
                return;
            comb.push_back(cddts[i]);
            backtracking(cddts, i+1, target-cddts[i], comb, res);
            comb.pop_back();
        }
    }
};