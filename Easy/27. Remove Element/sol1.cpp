
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int k = 0;

        for (int i = 0; i < size - k; i++) {
            if (nums[i] == val) {
                k++;
                swap(nums[i--], nums[size - k]);
            }
        }

        return size - k;
    }
};