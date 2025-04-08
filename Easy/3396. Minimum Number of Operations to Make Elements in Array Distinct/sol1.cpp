class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int freq[101] = {0};
        int index = -1;
        for (int i = nums.size()-1; i >= 0; i--) {
            freq[nums[i]]++;
            nums[i] = freq[nums[i]];
            if (nums[i] > 1) {
                index = i;
                break;
            }
        }
        return (index + 3)/3;
    }
};