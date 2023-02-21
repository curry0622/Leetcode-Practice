class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m-1;

        while (l < r) {
            int mid = (l+r)/2;
            if (target <= matrix[mid].back()) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        int row = l;

        l = 0, r = n-1;
        while (l < r) {
            int mid = (l+r)/2;
            if (target <= matrix[row][mid]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return matrix[row][l] == target;
    }
};