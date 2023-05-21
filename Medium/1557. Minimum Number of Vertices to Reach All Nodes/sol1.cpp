class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDeg(n, 0);
        for (const auto &e: edges) {
            inDeg[e[1]]++;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};