class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cd;
    int tg;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cd = candidates;
        tg = target;
        vector<int> used;
        backtracking(0, 0, used);
        return ans;
    }

    void backtracking(int idx, int sum, vector<int>& used) {
        if(sum > tg) {
            return;
        } else if(sum == tg) {
            ans.push_back(used);
            return;
        } else {
            for(int i = idx; i < cd.size(); i++) {
                sum += cd[i];
                used.push_back(cd[i]);
                backtracking(i, sum, used);
                sum -= cd[i];
                used.pop_back();
            }
        }
    }
};