class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> memo;
        for (const string& str : strs) {
            vector<int> freq(26, 0);
            for (const char& c : str) {
                freq[c-'a']++;
            }
            memo[freq].push_back(str);
        }
        vector<vector<string>> res;
        for (auto iter = memo.begin(); iter != memo.end(); iter++) {
            res.push_back(iter->second);
        }
        return res;
    }
};
