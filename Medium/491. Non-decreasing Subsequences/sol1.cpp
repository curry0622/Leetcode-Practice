class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> seq;
        dfs(nums, 0, seq, ans);
        return ans;
    }

    void dfs(vector<int>& nums, int pos, vector<int>& seq, vector<vector<int>>& ans) {
        if (seq.size() >= 2)
            ans.push_back(seq);
        unordered_set<int> record;
        for (int i = pos; i < nums.size(); i++) {
            if ((seq.empty() || nums[i] >= seq.back()) && record.find(nums[i]) == record.end()) {
                seq.push_back(nums[i]);
                dfs(nums, i + 1, seq, ans);
                seq.pop_back();
                record.insert(nums[i]);
            }
        }
    }
};