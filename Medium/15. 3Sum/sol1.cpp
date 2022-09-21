class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3)
            return {};
        if(nums[0] > 0)
            return {};

        unordered_map<int, int> ump;
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++)
            ump[nums[i]] = i;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] > 0)
                break;
            for(int j = i + 1; j < nums.size() - 1; j++) {
                int target = 0 - (nums[i] + nums[j]);
                if(ump.count(target) && ump.find(target) -> second > j) {
                    ans.push_back(vector<int>{nums[i], nums[j], target});
                }
                j = ump.find(nums[j]) -> second;
            }
            i = ump.find(nums[i]) -> second;
        }

        return ans;
    }
};