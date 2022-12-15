class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1 = -1, idx2 = nums.size() - 1;

        // Find the first num that cause non-descending order
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                idx1 = i;
                break;
            }
        }

        // If couldn't find, it means it's the largest
        if(idx1 == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the first num that is <=
        for(int i = idx1 + 1; i < nums.size(); i++) {
            if(nums[i] <= nums[idx1]) {
                idx2 = i - 1;
                break;
            }
        }

        // Swap and reverse
        swap(nums[idx1], nums[idx2]);
        reverse(nums.begin() + idx1 + 1, nums.end());
    }
};