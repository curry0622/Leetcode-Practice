class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> used;
        vector<vector<int>> all;
        backtracking(n, k, 1, used, all);
        return all;
    }

    void backtracking(int n, int k, int curr, vector<int>& used, vector<vector<int>>& all) {
        if(used.size() == k) {
            all.push_back(used);
            return;
        }
        for(int i = curr; i <= n; i++) {
            used.push_back(i);
            backtracking(n, k, i + 1, used, all);
            used.pop_back();
        }
    }
};