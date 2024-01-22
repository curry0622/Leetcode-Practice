class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res = {0, 0};
        vector<int> cnt(nums.size()+1, 0);
        for (int n : nums)
            cnt[n]++;
        for (int i = 1; i <= nums.size(); i++) {
            if (cnt[i] == 2)
                res[0] = i;
            if (cnt[i] == 0)
                res[1] = i;
        }
        return res;
    }
};