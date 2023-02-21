class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int m = (l+r)/2;
            if ((m-1 >= 0 && nums[m-1] != nums[m]) && (m+1 < nums.size() && nums[m] != nums[m+1])) {
                return nums[m];
            }
            if (m-1 >= 0 && nums[m-1] == nums[m]) {
                if (m & 1) {
                    // m is odd
                    l = m+1;
                } else {
                    // m is even
                    r = m-2;
                }
            }
            if (m+1 < nums.size() && nums[m] == nums[m+1]) {
                if (m & 1) {
                    // m is odd
                    r = m-1;
                } else {
                    // m is even
                    l = m+2;
                }
            }
        }
        return nums[l];
    }
};

//  0,1,2,3,4,5,6,7,8
// [1,1,2,3,3,4,4,8,8]
// [even,odd]-[x]-[odd,even]