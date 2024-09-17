class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        map<string, vector<int>> mp;
        istringstream ss1(s1), ss2(s2);
        string w;
        while (ss1 >> w) {
            mp[w].push_back(1);
        }
        while (ss2 >> w) {
            mp[w].push_back(2);
        }
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            if ((iter->second).size() == 1)
                res.push_back(iter->first);
        }
        return res;
    }
};