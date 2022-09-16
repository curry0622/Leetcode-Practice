class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all;
        backtracking(nums, {}, all);
        return all;
    }

    void backtracking(vector<int> nums, vector<int> walked, vector<vector<int>>& all) {
        if(walked.size() == nums.size()) {
            all.push_back(walked);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if(n != INT_MIN) {
                nums[i] = INT_MIN;
                walked.push_back(n);
                backtracking(nums, walked, all);
                nums[i] = n;
                walked.pop_back();
            }
        }
    }
};