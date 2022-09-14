class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0;
        int n = s.size();
        vector<vector<int>> lastIndex = vector<vector<int>>(26, vector<int>(n, -1));

        calcLastIndex(s, lastIndex);

        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < n; j++) {
                ans += lastIndex[i][j] + 1;
            }
        }

        return ans;
    }

    void calcLastIndex(string s, vector<vector<int>>& lastIndex) {
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == char(i + 97)) {
                    lastIndex[i][j] = j;
                } else if(j > 0 && lastIndex[i][j - 1] != -1) {
                    lastIndex[i][j] = lastIndex[i][j - 1];
                }
            }
        }
    }
};