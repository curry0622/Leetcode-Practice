class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (i + 2 >= nums.size()) return -1;
                int newi = i + 3;
                for (int j = 0; j < 3; j++) {
                    nums[i + j] = !nums[i + j];
                    if (nums[i + j] == 0 && newi == i + 3) {
                        newi = i + j;
                    }
                }
                res++;
                i = newi - 1;
            }
        }
        return res;
    }
};