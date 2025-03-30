class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> idx(26, {-1, -1});
        for (int i = 0; i < s.size(); i++) {
            if (idx[s[i] - 'a'][0] == -1) {
                idx[s[i] - 'a'][0] = i;
            }
            idx[s[i] - 'a'][1] = i;
        }
        sort(idx.begin(), idx.end());
        cout << endl;
        vector<int> res;
        int l = -1, r = -1;
        for (int i = 0; i < 26; i++) {
            if (idx[i][0] == -1) continue;
            if (l == -1 || r == -1) {
                l = idx[i][0];
                r = idx[i][1];
            } else if (idx[i][0] <= r) {
                r = max(r, idx[i][1]);
            } else {
                res.push_back(r - l + 1);
                l = idx[i][0];
                r = idx[i][1];
            }
        }
        if (l != -1 && r != -1) {
            res.push_back(r - l + 1);
        }
        return res;
    }
};