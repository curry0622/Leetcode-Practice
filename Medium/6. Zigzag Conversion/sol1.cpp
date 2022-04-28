class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        vector<vector<char>> rows(numRows);
        int currRow = 0;
        bool back = false;
        for(int i = 0; i < s.length(); i++) {
            rows[currRow].push_back(s[i]);
            if(currRow == numRows - 1 && !back) {
                back = true;
            }
            if(currRow == 0 && back) {
                back = false;
            }
            if(numRows != 1) {
                if(back) {
                    currRow--;
                } else {
                    currRow++;
                }
            }
        }
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < rows[i].size(); j++) {
                ans.push_back(rows[i][j]);
            }
        }
        return ans;
    }
};