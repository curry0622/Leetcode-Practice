class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>(1, 1));
        if(numRows == 1)
            return ans;
        ans.push_back(vector<int>(2, 1));
        if(numRows == 2)
            return ans;
        for(int i = 3; i <= numRows; i++) {
            vector<int> last = ans[i - 2];
            vector<int> tmp(1, last[0]);
            for(int j = 1; j < last.size(); j++) {
                tmp.push_back(last[j - 1] + last[j]);
            }
            tmp.push_back(last.back());
            ans.push_back(tmp);
        }
        return ans;
    }
};