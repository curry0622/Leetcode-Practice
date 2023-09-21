class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;
        int i = 0;
        for (auto row : mat) {
            heap.push({i++, numSoldier(row)});
            if (heap.size() > k)
                heap.pop();
        }

        vector<int> res;
        while(heap.size() > 0) {
            int row = heap.top().first;
            res.push_back(row);
            heap.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }

    int numSoldier(const vector<int>& row) {
        int num = 0;
        for (int n : row)
            num += n;
        return num;
    }
};