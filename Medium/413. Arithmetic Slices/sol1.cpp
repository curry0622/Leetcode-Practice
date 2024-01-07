class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        int dist = nums[1] - nums[0];
        int cnt = 2;
        int res = 0;

        for (int i = 2; i < nums.size(); i++) {
            if (dist == nums[i] - nums[i-1]) {
                cnt++;
            } else {
                res += getNum(cnt);
                dist = nums[i] - nums[i-1];
                cnt = 2;
            }
        }

        return res + getNum(cnt);
    }

    int getNum(int cnt) {
        if (cnt < 3)
            return 0;
        return (cnt-1)*(cnt-2)/2;
    }
};