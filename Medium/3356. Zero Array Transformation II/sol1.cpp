class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int left = 0, right = queries.size();
        if (!isValid(nums, queries, right)) return -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(nums, queries, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool isValid(const vector<int>& nums,
                    const vector<vector<int>>& queries,
                    int k) {
        int n = nums.size();
        vector<int> diffArr(n + 1, 0);
        for (int i = 0; i < k; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];
            diffArr[start] += val;
            diffArr[end+1] -= val;
        }
        int preSum = 0;
        for (int i = 0; i < n; i++) {
            preSum += diffArr[i];
            if (preSum < nums[i]) {
                return false;
            }
        }
        return true;
    }
};