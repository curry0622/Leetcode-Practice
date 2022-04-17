class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int minLen = 200;
        int minIdx = 0;
        for(int i = 0; i < strs.size(); i++) {
            int tmpLen = strs.at(i).length();
            if (minLen > tmpLen) {
                minLen = tmpLen;
                minIdx = i;
            }
        }
        for(int i = 0; i < minLen; i++) {
            char c = strs.at(minIdx)[i];
            for(int j = 0; j < strs.size(); j++) {
                if (c != strs.at(j)[i]) {
                    return ans;
                } else if (j == strs.size() - 1) {
                    ans.push_back(c);
                }
            }
        }
        return ans;
    }
};