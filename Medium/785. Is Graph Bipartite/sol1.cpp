class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> s(n, -1);
        queue<int> q;
        vector<bool> pushed (n, false);

        for (int i = 0; i < n; i++) {
            if (!pushed[i]) {
                s[i] = 0;
                q.push(i);
                pushed[i] = true;
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int v : graph[curr]) {
                        if (s[v] == s[curr])
                            return false;
                        if (s[v] == -1)
                            s[v] = !s[curr];
                        if (!pushed[v]) {
                            q.push(v);
                            pushed[v] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};