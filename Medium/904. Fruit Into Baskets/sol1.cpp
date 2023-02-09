class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int currLen = 0, maxLen = 0;
        int a = -1, b = -1, bCnt = 0;
        for (const int& c : fruits) {
            // case1
            if (c == b) {
                currLen++;
                bCnt++;
            }
            // case2
            else if (c == a) {
                currLen++;
                a = b, b = c;
                bCnt = 1;
            }
            // case 3
            else {
                currLen = bCnt + 1;
                a = b, b = c;
                bCnt = 1;
            }
            // update
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};


// aaabbbc
// - a: last 2nd fruit type
// - b: last fruit type
// - c: current fruit type

// case1: c == b
// - currLen += 1
// - bCnt += 1

// case2: c == a
// - currLen += 1
// - a = b, b = c
// - bCnt = 1

// case3: c != a && c != b
// - currLen = bCnt + 1
// - a = b, b = c
// - bCnt = 1

// maxLen = max(maxLen, currLen)
