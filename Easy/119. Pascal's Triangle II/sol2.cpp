class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int size = rowIndex + 1;
        vector<int> res(size, 0);
        res[0] = 1;

        for (int i = 1; i <= rowIndex; i++) {
            int last = 1;
            for (int j = 1; j <= i; j++) {
                int tmp = res[j];
                res[j] += last;
                last = tmp;
            }
        }

        return res;
    }
};