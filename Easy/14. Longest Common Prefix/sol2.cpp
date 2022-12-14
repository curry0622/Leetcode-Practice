class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        int minLen = strs[0].size();
        for(int i = 1; i < strs.size(); i++) {
            if(minLen > strs[i].size()) {
                minLen = strs[i].size();
            }
        }

        for(int i = 0; i < minLen; i++) {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++) {
                if(c != strs[j][i]) {
                    return ans;
                }
            }
            ans += c;
        }

        return ans;
    }
};