class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        vector<int> ans = {-1, -1};
        while(l <= r) {
            int m = (l + r) / 2;
            if(target < nums[m]) {
                r = m - 1;
                continue;
            } else if(target > nums[m]) {
                l = m + 1;
                continue;
            } else {
                while(target != nums[l]) {
                    l++;
                }
                while(target != nums[r]) {
                    r--;
                }
                ans[0] = l;
                ans[1] = r;
                break;
            }
        }
        return ans;
    }
};