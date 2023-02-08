class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, start = 0, end = 0;
        while (end < nums.size()-1) {
            step++;
            int new_end = end;
            for (int i = start; i <= end; i++) {
                new_end = max(new_end, i+nums[i]);
                if (new_end >= nums.size()-1)
                    return step;
            }
            start = end+1;
            end = new_end;
        }
        return step;
    }
};

// index: 0, 1, 2, 3, 4
//  nums: 2, 3, 1, 1, 4
// step0: [0]
// step1: [1, 2]
// step2: [2, 3, 4], [3]

// index: 0, 1, 2, 3, 4
//  nums: 2, 3, 0, 1, 4
// step0: [0]
// step1: [1, 2]
// step2: [2, 3, 4], []