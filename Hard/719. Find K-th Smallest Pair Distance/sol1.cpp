class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n-1] - nums[0];
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (enough(nums, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool enough(vector<int>& nums, int k, int d) {
        int n = nums.size();
        int cnt = 0;
        int l = 0, r = 0;
        while (l < n || r < n) {
            while (r < n && nums[r] - nums[l] <= d)
                r++;
            cnt += r - l - 1;
            l++;
        }
        return cnt >= k;
    }
};