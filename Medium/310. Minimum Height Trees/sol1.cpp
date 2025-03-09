class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<int> deg(n, 0);
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        queue<int> deg1Nodes;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                deg1Nodes.push(i);
            }
        }

        int numDel = 0;
        while (n - numDel > 2) {
            int num = deg1Nodes.size();
            while (num > 0) {
                int node = deg1Nodes.front();
                for (const auto& adjNode : graph[node]) {
                    deg[adjNode]--;
                    if (deg[adjNode] == 1) {
                        deg1Nodes.push(adjNode);
                    }
                }
                deg[node] = 0;
                deg1Nodes.pop();
                num--;
                numDel++;
            }
        }

        vector<int> res;
        while (!deg1Nodes.empty()) {
            res.push_back(deg1Nodes.front());
            deg1Nodes.pop();
        }
        return n == 1 ? vector<int>{0} : res;
    }
};

// 0-1-2-3
// 1-2-2-1, 2

// 1-2
// 1-1, 0