class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int maxVal = nums.size();
        vector<vector<int>> res;
        vector<int> cnt(maxVal+1, 0);
        for (const int& n : nums) {
            cnt[n]++;
        }
        for (int i = 1; i <= maxVal; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                if (j >= res.size()) {
                    res.push_back({i});
                } else {
                    res[j].push_back(i);
                }
            }
        }
        return res;
    }
};