class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curr(rowIndex + 1);
        vector<int> prev(rowIndex + 1);

        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    curr[j] = 1;
                else
                    curr[j] = prev[j-1] + prev[j];
            }
            prev = curr;
        }

        return curr;
    }
};