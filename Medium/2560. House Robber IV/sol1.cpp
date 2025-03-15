class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = nums[0], right = nums[0];
        for (auto n : nums) {
            left = min(left, n);
            right = max(right, n);
        }

        int res;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(nums, k, mid)) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }

    bool isValid(const vector<int>& nums, int k, int maxValue) {
        int count = 0;
        bool lastPicked = false;

        for (int num : nums) {
            if (num <= maxValue && !lastPicked) {
                count++;
                lastPicked = true;
                if (count == k) return true;
            } else {
                lastPicked = false;
            }
        }

        return false;
    }
};
