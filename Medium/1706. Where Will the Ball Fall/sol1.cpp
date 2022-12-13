class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int j = 0; j < grid[0].size(); j++)
            ans.push_back(traverse(0, j, grid));
        return ans;
    }

    int traverse(int i, int j, const vector<vector<int>>& grid) {
        if(grid[i][j] == 1) {
            // turn right
            if(j == grid[0].size() - 1 || grid[i][j + 1] == -1)
                return -1;
            else if(i < grid.size() - 1)
                return traverse(i + 1, j + 1, grid);
            else
                return j + grid[i][j];
        } else {
            // turn left
            if(j == 0 || grid[i][j - 1] == 1)
                return -1;
            else if(i < grid.size() - 1)
                return traverse(i + 1, j - 1, grid);
            else
                return j + grid[i][j];
        }
        return -1;
    }
};