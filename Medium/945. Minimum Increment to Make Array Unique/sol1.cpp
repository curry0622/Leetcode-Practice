#define MAX_VAL 200000
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int res = 0;
        int arr[MAX_VAL+1] = {0};
        for (const int& num : nums) {
            if (arr[num]) {
                for (int i = 1; num+i <= MAX_VAL; i++) {
                    if (num+i <= MAX_VAL && !arr[num+i]) {
                        arr[num+i] = 1;
                        res += i;
                        break;
                    }
                }
            } else {
                arr[num] = 1;
            }
        }
        return res;
    }
};