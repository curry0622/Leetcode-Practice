class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        int openCnt = 0, closeCnt = 0;
        int res = 0;

        while (l < n) {
            if (s[l] == '[')
                openCnt++;
            else
                closeCnt++;
            if (closeCnt > openCnt) {
                while (r >= 0 && s[r] != '[') {
                    r--;
                }
                swap(s[l], s[r]);
                res++;
                r--;
                closeCnt--;
                openCnt++;
            }
            l++;
        }

        return res;
    }
};

// ]]][[[
// 012345

// []][[]
// 512340

// [][[]]
// 514320