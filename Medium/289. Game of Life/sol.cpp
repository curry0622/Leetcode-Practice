class Solution {
public:
    vector<vector<int>> org;
    int m, n;

    void gameOfLife(vector<vector<int>>& board) {
        org = board;
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = update(i, j);
            }
        }
    }

    int cntLiveNum(int i, int j) {
        int liveNum = 0;
        // up left
        if(i > 0 && j < n - 1 && org[i - 1][j + 1] == 1)
            liveNum++;
        // up mid
        if(j < n - 1 && org[i][j + 1] == 1)
            liveNum++;
        // up right
        if(i < m - 1 && j < n - 1 && org[i + 1][j + 1] == 1)
            liveNum++;
        // left
        if(i > 0 && org[i - 1][j] == 1)
            liveNum++;
        // right
        if(i < m - 1 && org[i + 1][j] == 1)
            liveNum++;
        // down left
        if(i > 0 && j > 0 && org[i - 1][j - 1] == 1)
            liveNum++;
        // down mid
        if(j > 0 && org[i][j - 1] == 1)
            liveNum++;
        // down right
        if(i < m - 1 && j > 0 && org[i + 1][j - 1] == 1)
            liveNum++;
        return liveNum;
    }

    int update(int i, int j) {
        int liveNum = cntLiveNum(i, j);
        if(org[i][j] == 1 && (liveNum < 2 || liveNum > 3))
            return 0;
        if(org[i][j] == 1 && (liveNum == 2 || liveNum == 3))
            return 1;
        if(org[i][j] == 0 && liveNum == 3)
            return 1;
        return org[i][j];
    }
};