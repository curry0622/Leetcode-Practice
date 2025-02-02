class Solution {
public:
    bool check(vector<int>& nums) {
        bool found = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                if (found) {
                    return false;
                } else {
                    found = true;
                }
            }
        }
        return found ? nums.back() <= nums[0] : true;
    }
};