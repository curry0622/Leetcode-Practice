class Solution {
int n;
int len;
vector<int> res;
public:
    vector<int> constructDistancedSequence(int _n) {
        n = _n;
        len = 2 * n - 1;
        vector<int> curr(len, 0);
        vector<bool> used(n + 1, false); // don't use idx0
        backtracking(curr, 0, used);
        return res;
    }

    void backtracking(vector<int>& curr, int start, vector<bool>& used) {
        if (res.size() > 0 || start >= len) {
            if (res.size() == 0)
                res = curr;
            return;
        }
        if (curr[start] == 0) {
            for (int i = n; i > 0; i--) {
                if (used[i]) continue;
                if (i == 1) {
                    curr[start] = i;
                    used[i] = true;
                    backtracking(curr, start + 1, used);
                    curr[start] = 0;
                    used[i] = false;
                } else if (start + i < len && curr[start + i] == 0) {
                    curr[start] = i;
                    curr[start + i] = i;
                    used[i] = true;
                    backtracking(curr, start + 1, used);
                    curr[start] = 0;
                    curr[start + i] = 0;
                    used[i] = false;
                }
            }
        } else {
            backtracking(curr, start + 1, used);
        }
    }

    void print(vector<int> vec) {
        for (int v : vec) {
            cout << v << ", ";
        }
        cout << endl;
    }
};

// n=3, len=5
// 3,1,2,3,2,

// n=4, len=7
// 4,2,3,2,4,3,1,

// n=5, len=9
// 5,3,1,4,3,5,2,4,2,