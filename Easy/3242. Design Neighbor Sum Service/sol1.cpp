class neighborSum {
public:
    int n = 0;
    int total = 0;
    vector<vector<int>> grid;
    map<int, pair<int, int>> pos;

    neighborSum(vector<vector<int>>& g) {
        grid = g;
        n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
                total += grid[i][j];
            }
        }
    }

    int adjacentSum(int value) {
        pair<int, int> p = pos[value];
        int row = p.first, col = p.second;
        int sum = 0;
        if (row - 1 >= 0)
            sum += grid[row-1][col];
        if (row + 1 < n)
            sum += grid[row+1][col];
        if (col - 1 >= 0)
            sum += grid[row][col-1];
        if (col + 1 < n)
            sum += grid[row][col+1];
        return sum;
    }

    int diagonalSum(int value) {
        pair<int, int> p = pos[value];
        int row = p.first, col = p.second;
        int sum = 0;
        if (row - 1 >= 0 && col - 1 >= 0)
            sum += grid[row-1][col-1];
        if (row - 1 >= 0 && col + 1 < n)
            sum += grid[row-1][col+1];
        if (row + 1 < n && col - 1 >= 0)
            sum += grid[row+1][col-1];
        if (row + 1 < n && col + 1 < n)
            sum += grid[row+1][col+1];
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */