class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int low = 1, high = n, mid;

        while (low < high) {
            mid = low + (high - low) / 2;
            int cnt = 0;
            for (int n : nums)
                if (n <= mid)
                    cnt++;
            if (cnt <= mid)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};