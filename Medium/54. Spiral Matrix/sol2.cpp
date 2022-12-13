class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mtx) {
        vector<int> ans;
        traverse(0, 0, 0, mtx, ans);
        return ans;
    }

    void traverse(int i, int j, int dir, vector<vector<int>>& mtx, vector<int>& ans) {
        ans.push_back(mtx[i][j]);
        mtx[i][j] = INT_MAX;
        if(dir == 0) {
            // right
            if(valid(i, j + 1, mtx))
                traverse(i, j + 1, 0, mtx, ans);
            else if(valid(i + 1, j, mtx))
                traverse(i + 1, j, 1, mtx, ans);
            else
                return;
        } else if(dir == 1) {
            // down
            if(valid(i + 1, j, mtx))
                traverse(i + 1, j, 1, mtx, ans);
            else if(valid(i, j - 1, mtx))
                traverse(i, j - 1, 2, mtx, ans);
            else
                return;
        } else if(dir == 2) {
            // left
            if(valid(i, j - 1, mtx))
                traverse(i, j - 1, 2, mtx, ans);
            else if(valid(i - 1, j, mtx))
                traverse(i - 1, j, 3, mtx, ans);
            else
                return;
        } else {
            // up
            if(valid(i - 1, j, mtx))
                traverse(i - 1, j, 3, mtx, ans);
            else if(valid(i, j + 1, mtx))
                traverse(i, j + 1, 0, mtx, ans);
            else
                return;
        }
    }

    bool valid(int i, int j, vector<vector<int>>& mtx) {
        if(i < 0 || i >= mtx.size())
            return false;
        if(j < 0 || j >= mtx[0].size())
            return false;
        if(mtx[i][j] == INT_MAX)
            return false;
        return true;
    }
};