class Solution {
string res = "";
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int done = pow(2, n) - 1;
        string curr(n, 'x');
        int status = 0;
        backtracking(0, status, nums, done, curr);
        for (int i = 0; i < n; i++) {
            if (res[i] == 'x') {
                res[i] = '0';
            }
        }
        return res;
    }

    void backtracking(int start, int& status, const vector<string>& nums,
                      const int& done, string& curr) {
        if (status == done || res != "" || start >= nums.size()) {
            if (res == "" && status == done) {
                res = curr;
            }
            return;
        }

        int ci = 0;
        int n = nums.size();
        int oldStat = status;
        while (ci < 2) {
            status = oldStat;
            char ch('0' + ci);
            for (int i = 0; i < n; i++) {
                if (nums[i][start] != ch) {
                    status |= (1 << i);
                }
            }
            curr[start] = ch;
            backtracking(start + 1, status, nums, done, curr);
            ci++;
        }
    }
};

// 0: 111
// 1: 011
// 2: 001

// idx= 0
// 0-> 0
// 1-> 1,2

// idx= 1
// 00-> [0],1
// 01-> [0],2
// 10-> [1,2],0
// 11-> [1,2]