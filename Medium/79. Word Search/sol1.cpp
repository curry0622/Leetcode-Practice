class Solution {
public:
    vector<vector<char>> brd;
    string wrd;
    int m, n;

    bool exist(vector<vector<char>>& board, string word) {
        brd = board;
        wrd = word;

        m = board.size();
        n = board[0].size();

        if(m * n < wrd.length()) {
            return false;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(brd[i][j] == wrd[0]) {
                    char tmp = brd[i][j];
                    brd[i][j] = '*';
                    if(walk(i, j, 1))
                        return true;
                    else
                        brd[i][j] = tmp;
                }
            }
        }

        return false;
    }

    bool walk(const int& i, const int& j, const int& wIdx) {
        // cout << i << ' ' << j << ' ' << wIdx << endl;

        if(wIdx == wrd.length())
            return true;

        // up
        if(isValid(i, j - 1) && brd[i][j - 1] == wrd[wIdx]) {
            char tmp = brd[i][j - 1];
            brd[i][j - 1] = '*';
            if(walk(i, j - 1, wIdx + 1))
                return true;
            brd[i][j - 1] = tmp;
        }

        // down
        if(isValid(i, j + 1) && brd[i][j + 1] == wrd[wIdx]) {
            char tmp = brd[i][j + 1];
            brd[i][j + 1] = '*';
            if(walk(i, j + 1, wIdx + 1))
                return true;
            brd[i][j + 1] = tmp;
        }

        // left
        if(isValid(i - 1, j) && brd[i - 1][j] == wrd[wIdx]) {
            char tmp = brd[i - 1][j];
            brd[i - 1][j] = '*';
            if(walk(i - 1, j, wIdx + 1))
                return true;
            brd[i - 1][j] = tmp;
        }

        // right
        if(isValid(i + 1, j) && brd[i + 1][j] == wrd[wIdx]) {
            char tmp = brd[i + 1][j];
            brd[i + 1][j] = '*';
            if(walk(i + 1, j, wIdx + 1))
                return true;
            brd[i + 1][j] = tmp;
        }

        return false;
    }

    bool isValid(const int& i, const int& j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
};