class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        while (i < m && j >= 0) {
            if (target < matrix[i][j])
                j--;
            else if (target > matrix[i][j])
                i++;
            else
                break;
        }
        if (i < m && j >= 0)
            return true;
        return false;
    }
};

// ref: https://leetcode.com/problems/search-a-2d-matrix/solutions/1895837/c-binary-search-tree-explained-with-img/?envType=study-plan&id=level-2&orderBy=most_votes