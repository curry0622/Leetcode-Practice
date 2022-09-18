class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;

        for(int i = 0; i < nums.size(); i++) {
            int tg = target - nums[i];
            if(ump.find(tg) != ump.end()) {
                return vector<int>{i, ump.find(tg) -> second};
            }
            ump[nums[i]] = i;
        }

        return {};
    }
};