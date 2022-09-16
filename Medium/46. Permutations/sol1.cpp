class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all;
        func(nums, {}, all);
        return all;
    }

    void func(vector<int> nums, vector<int> walked, vector<vector<int>>& all) {
        if(walked.size() == nums.size()) {
            all.push_back(walked);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != INT_MIN) {
                vector<int> new_nums = nums;
                vector<int> new_walked = walked;
                new_nums[i] = INT_MIN;
                new_walked.push_back(nums[i]);
                func(new_nums, new_walked, all);
            }
        }
    }
};