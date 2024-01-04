class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (const auto& num : nums) {
            cnt[num]++;
        }
        for (const auto& iter : cnt) {
            if (iter.second == 1)
                return -1;
            res += getMinOpNum(iter.second);
        }
        return res;
    }

    int getMinOpNum(int num) {
        if (num == 2 || num == 3)
            return 1;
        int res = 0;
        while(num % 3 != 0) {
            num -= 2;
            res++;
        }
        return res + num/3;
    }
};