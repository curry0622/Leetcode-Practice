class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
            parent[rootX] = rootY; // Just link one root to another
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for (auto e : edges) {
            dsu.unite(e[0], e[1]);
        }
        unordered_map<int, int> comp;
        for (auto e : edges) {
            int root = dsu.find(e[0]);
            if (comp.find(root) == comp.end()) {
                comp[root] = e[2];
            } else {
                comp[root] &= e[2];
            }
        }
        vector<int> res;
        for (auto q : query) {
            int cost = -1;
            if (dsu.find(q[0]) == dsu.find(q[1])) {
                cost = comp[dsu.find(q[0])];
            }
            res.push_back(cost);
        }
        return res;
    }
};