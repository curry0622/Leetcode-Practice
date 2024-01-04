class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> res;
        vector<int> cnt(size+1, 0);
        for (const auto& n : nums) {
            if (cnt[n] == res.size())
                res.push_back({});
            res[cnt[n]].push_back(n);
            cnt[n]++;
        }
        return res;
    }
};