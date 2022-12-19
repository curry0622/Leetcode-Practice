class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        vector<int> parent(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for(auto& e : edges) {
            parent[find(e[1], parent)] = find(e[0], parent);
        }
        return find(dst, parent) == find(src, parent);
    }

    int find(int v, vector<int>& parent) {
        if(v != parent[v]) {
            parent[v] = find(parent[v], parent);
        }
        return parent[v];
    }
};