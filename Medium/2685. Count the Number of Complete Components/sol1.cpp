class DSU {
public:
    vector<int> par;

    DSU(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int find(int i) {
        if (i != par[i])
            par[i] = find(par[i]);
        return par[i];
    }

    void unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri != rj)
            par[ri] = rj;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int, int> nodeCnt;
        for (auto e : edges) {
            dsu.unite(e[0], e[1]);
        }
        for (int i = 0; i < n; i++) {
            nodeCnt[dsu.find(i)]++;
        }
        for (auto it = nodeCnt.begin(); it != nodeCnt.end(); it++) {
            it->second = it->second * (it->second - 1) / 2;
        }
        for (auto e : edges) {
            int p = dsu.find(e[0]);
            nodeCnt[p]--;
        }
        int res = 0;
        for (auto it = nodeCnt.begin(); it != nodeCnt.end(); it++) {
            if (it->second == 0) res++;
        }
        return res;
    }
};