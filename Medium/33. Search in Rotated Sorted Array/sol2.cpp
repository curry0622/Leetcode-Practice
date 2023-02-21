class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int m = (l+r)/2;
            if ((target < nums[0]) == (nums[m] < nums[0])) {
                if (target < nums[m]) {
                    r = m;
                } else if (target > nums[m]) {
                    l = m+1;
                } else {
                    return m;
                }
            } else if (target < nums[0]) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return nums[l] == target ? l : -1;
    }
};