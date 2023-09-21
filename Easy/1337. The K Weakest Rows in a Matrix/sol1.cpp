class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> record;
        int i = 0;
        for (auto row : mat) {
            record.push_back({i++, soldierNum(row)});
        }
        sort(record.begin(), record.end(), cmp);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(record[i].first);
        }
        return res;
    }

    int soldierNum(const vector<int>& row) {
        int num = 0;
        for (int n : row)
            num += n;
        return num;
    }

    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }
};