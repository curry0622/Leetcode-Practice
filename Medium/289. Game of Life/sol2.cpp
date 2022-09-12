class Solution {
public:
    int m, n;

    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int currState = board[i][j];
                int nextState = update(board, i, j);
                if(currState == 0 && nextState == 1) {
                    board[i][j] = INT_MAX;
                }
                if(currState == 1 && nextState == 0) {
                    board[i][j] = INT_MIN;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == INT_MAX)
                    board[i][j] = 1;
                if(board[i][j] == INT_MIN)
                    board[i][j] = 0;
            }
        }
    }

    int cntLiveNum(const vector<vector<int>>& board, int i, int j) {
        int liveNum = 0;
        // up left
        if(i > 0 && j < n - 1 && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == INT_MIN))
            liveNum++;
        // up mid
        if(j < n - 1 && (board[i][j + 1] == 1 || board[i][j + 1] == INT_MIN))
            liveNum++;
        // up right
        if(i < m - 1 && j < n - 1 && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == INT_MIN))
            liveNum++;
        // left
        if(i > 0 && (board[i - 1][j] == 1 || board[i - 1][j] == INT_MIN))
            liveNum++;
        // right
        if(i < m - 1 && (board[i + 1][j] == 1 || board[i + 1][j] == INT_MIN))
            liveNum++;
        // down left
        if(i > 0 && j > 0 && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == INT_MIN))
            liveNum++;
        // down mid
        if(j > 0 && (board[i][j - 1] == 1 || board[i][j - 1] == INT_MIN))
            liveNum++;
        // down right
        if(i < m - 1 && j > 0 && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == INT_MIN))
            liveNum++;
        return liveNum;
    }

    int update(const vector<vector<int>>& board, int i, int j) {
        int liveNum = cntLiveNum(board, i, j);

        if(board[i][j] == 0) {
            if(liveNum == 3)
                return 1;
        } else {
            if(liveNum < 2)
                return 0;
            if(liveNum == 2 || liveNum == 3)
                return 1;
            if(liveNum > 3)
                return 0;
        }

        return board[i][j];
    }
};