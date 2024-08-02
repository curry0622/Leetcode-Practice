class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int numOnes = 0;
        for (int n : nums)
            numOnes += n;
        vector<int> newNums = nums;
        newNums.insert(newNums.end(), nums.begin(), nums.end());

        int res = 0, curr = 0;
        for (int i = 0; i <= newNums.size() - numOnes; i++) {
            if (i == 0) {
                for (int j = 0; j < numOnes; j++)
                    if (newNums[j] == 0)
                        res++;
                curr = res;
            } else {
                if (newNums[i - 1] == 0)
                    curr--;
                if (newNums[i + numOnes - 1] == 0)
                    curr++;
                res = min(res, curr);
            }
        }

        return res;
    }
};
