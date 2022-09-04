class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(!isValidRow(board, i) || !isValidCol(board, i))
                return false;
        }
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                if(!isValidBox(board, i, j))
                    return false;
            }
        }
        return true;
    }

    bool isValidRow(vector<vector<char>>& board, int idx) {
        vector<bool> used(9, false);
        for(int i = 0; i < 9; i++) {
            if(board[idx][i] == '.')
                continue;
            int num = board[idx][i] - '0';
            if(used[num - 1])
                return false;
            else
                used[num - 1] = true;
        }
        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int idx) {
        vector<bool> used(9, false);
        for(int i = 0; i < 9; i++) {
            if(board[i][idx] == '.')
                continue;
            int num = board[i][idx] - '0';
            if(used[num - 1])
                return false;
            else
                used[num - 1] = true;
        }
        return true;
    }

    bool isValidBox(vector<vector<char>>& board, int idx_i, int idx_j) {
        vector<bool> used(9, false);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[idx_i + i][idx_j + j] == '.')
                    continue;
                int num = board[idx_i + i][idx_j + j] - '0';
                if(used[num - 1])
                    return false;
                else
                    used[num - 1] = true;
            }
        }
        return true;
    }
};