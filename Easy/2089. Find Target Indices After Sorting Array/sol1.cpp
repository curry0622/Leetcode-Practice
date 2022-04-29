class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> range = searchRange(nums, target);
        vector<int> ans;
        if(range[0] != -1) {
            for(int i = range[0]; i <= range[1]; i++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
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