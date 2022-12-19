class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        if(n == 1)
            return true;

        stack<int> stk;
        vector<bool> inStk(n, false);
        unordered_map<int, vector<int>> adj;

        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        stk.push(src);
        while(!stk.empty()) {
            int u = stk.top();
            stk.pop();
            for(auto& v : adj[u]) {
                if(v == dst) {
                    return true;
                }
                if(!inStk[v]) {
                    inStk[v] = true;
                    stk.push(v);
                }
            }
        }

        return false;
    }
};