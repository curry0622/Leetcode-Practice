class Solution {
using ll = long long;
public:
    int numberOfArrays(vector<int>& diffs, int lower, int upper) {
        ll minDiff = 0, maxDiff = 0;
        ll currDiff = 0;
        for (auto d : diffs) {
            currDiff += d;
            minDiff = min(minDiff, currDiff);
            maxDiff = max(maxDiff, currDiff);
        }
        ll minNum = lower - minDiff, maxNum = upper - maxDiff;
        return minNum <= maxNum ? maxNum - minNum + 1 : 0;
    }
};

// 1,-3,4 -> 1,6
// a,a+1,a-2,a+2 -> a-2>=1 && a+2<=6 -> a>=3 && a<=4