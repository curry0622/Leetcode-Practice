class Solution {
using ll = long long;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& r : roads) {
            int u = r[0], v = r[1], t = r[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        // Dijkstra's Algorithm
        vector<ll> minTime(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        minTime[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [curTime, node] = pq.top();
            pq.pop();

            if (curTime > minTime[node]) continue;

            for (auto& [adjNode, time] : graph[node]) {
                ll newTime = curTime + time;

                if (newTime < minTime[adjNode]) {
                    minTime[adjNode] = newTime;
                    ways[adjNode] = ways[node];
                    pq.push({newTime, adjNode});
                }
                else if (newTime == minTime[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
