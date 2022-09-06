class Solution {
public:
    int r_num = 0, w_num = 0, b_num = 0;

    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int color: nums)
            addNum(color);
        int i = 0;
        for(; i < r_num; i++)
            nums[i] = 0;
        for(; i < r_num + w_num; i++)
            nums[i] = 1;
        for(; i < n; i++)
            nums[i] = 2;
    }

    void addNum(int color) {
        if(color == 0)
            r_num++;
        else if(color == 1)
            w_num++;
        else
            b_num++;
    }
};