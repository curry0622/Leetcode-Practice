class Solution {
public:
    // dir: 0(up), 1(down), 2(left), 3(right)
    void traverse(vector<vector<int>>& matrix, vector<int>& ans, int i, int j, int dir) {
        ans.push_back(matrix[i][j]);
        matrix[i][j] = -101;
        switch(dir) {
            // up
            case 0:
                if(i - 1 >= 0 && matrix[i - 1][j] != -101) {
                    traverse(matrix, ans, i - 1, j, 0);
                } else if(j + 1 <= matrix[i].size() - 1 && matrix[i][j + 1] != -101) {
                    // go right
                    traverse(matrix, ans, i, j + 1, 3);
                }
                break;
            // down
            case 1:
                if(i + 1 <= matrix.size() - 1 && matrix[i + 1][j] != -101) {
                    traverse(matrix, ans, i + 1, j, 1);
                } else if(j - 1 >= 0 && matrix[i][j - 1] != -101) {
                    // go left
                    traverse(matrix, ans, i, j - 1, 2);
                }
                break;
            // left
            case 2:
                if(j - 1 >= 0 && matrix[i][j - 1] != -101) {
                    traverse(matrix, ans, i, j - 1, 2);
                } else if(i - 1 >= 0 && matrix[i - 1][j] != -101) {
                    // go up
                    traverse(matrix, ans, i - 1, j, 0);
                }
                break;
            // right
            case 3:
                if(j + 1 <= matrix[i].size() - 1 && matrix[i][j + 1] != -101) {
                    traverse(matrix, ans, i, j + 1, 3);
                } else if(i + 1 <= matrix.size() - 1 && matrix[i + 1][j] != -101) {
                    // go down
                    traverse(matrix, ans, i + 1, j, 1);
                }
                break;
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        traverse(matrix, ans, 0, 0, 3);
        return ans;
    }
};
