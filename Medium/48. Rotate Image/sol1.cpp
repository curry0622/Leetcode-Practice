class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), tmp1, tmp2;
        int layer = (n + 1) / 2;
        for(int i = 0; i < layer; i++) {
            for(int j = i; j < n - i - 1; j++) {
                tmp1 = matrix[j][n - i -1];
                matrix[j][n - i - 1] = matrix[i][j];
                tmp2 = matrix[n - i - 1][n - 1 - j];
                matrix[n - i - 1][n - 1 - j] = tmp1;
                tmp1 = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = tmp2;
                matrix[i][j] = tmp1;
            }
        }
    }
};