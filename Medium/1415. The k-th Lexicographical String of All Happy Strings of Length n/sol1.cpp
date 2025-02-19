class Solution {
string res = "";

public:
    string getHappyString(int n, int k) {
        string curr(n, ' ');
        backtracking(curr, 0, k);
        return k <= 0 ? res : "";
    }

    void backtracking(string& curr, int start, int& k) {
        if (start == curr.size()) {
            if (--k == 0) {
                res = curr;
            }
            return;
        }

        for (int i = 0; i < 3; i++) {
            char ch = char('a' + i);
            if (start - 1 >= 0 && curr[start - 1] == ch) continue;
            curr[start] = ch;
            backtracking(curr, start + 1, k);
            curr[start] = ' ';
        }
    }
};