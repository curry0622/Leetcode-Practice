class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0, high = n - 1;
        int max, maxIdx;

        while(low < high) {
            int mid = (low + high) / 2;
            max = mat[0][mid], maxIdx = 0;

            for(int i = 1; i < m; i++) {
                if(max < mat[i][mid]) {
                    max = mat[i][mid];
                    maxIdx = i;
                }
            }

            if(mat[maxIdx][mid] < mat[maxIdx][mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        max = mat[0][low], maxIdx = 0;
        for(int i = 1; i < m; i++) {
            if(max < mat[i][low]) {
                max = mat[i][low];
                maxIdx = i;
            }
        }

        return vector<int>{maxIdx, low};
    }
};