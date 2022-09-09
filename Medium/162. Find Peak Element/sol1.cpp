class Solution {
public:
    vector<int> nums;
    int n;

    int findPeakElement(vector<int>& numsVec) {
        nums = numsVec;
        n = nums.size();
        return findPeak(0, n - 1);
    }

    int findPeak(int l, int r) {
        int m = (l + r) / 2;
        if(l == r) {
            return l;
        }
        if(m == l) {
            if(nums[m] > nums[m + 1])
                return m;
            return r;
        }
        if(nums[m - 1] < nums[m] && nums[m] < nums[m + 1]) {
            return findPeak(m + 1, r);
        }
        if(nums[m - 1] > nums[m] && nums[m] > nums[m + 1]) {
            return findPeak(l, m - 1);
        }
        if(nums[m - 1] < nums[m] && nums[m] > nums[m + 1]) {
            return m;
        }
        return findPeak(m + 1, r);
    }
};