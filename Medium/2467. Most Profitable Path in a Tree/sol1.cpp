class Solution {
    int res = INT_MIN;
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size();
            unordered_map<int, vector<int>> adjList;
            for (auto e : edges) {
                adjList[e[0]].push_back(e[1]);
                adjList[e[1]].push_back(e[0]);
            }

            // first DFS from root to each node
            // to record dist from root to each node
            // beacuse Bob needs this info
            vector<int> distFromRoot(n, -1);
            // cout << "dist: " << endl;
            dfsRecordDistFromRoot(adjList, distFromRoot, 0, 0);

            // Bob moves toward the root and record the arrived time
            vector<int> bobTime(n, -1);
            // cout << "time: " << endl;
            moveBob(adjList, distFromRoot, bobTime, bob, 0);

            // Alice moves
            vector<bool> visited(n, false);
            // cout << "income: " << endl;
            moveAlice(adjList, amount, bobTime, visited, 0, 0, 0);
            return res;
        }

        void dfsRecordDistFromRoot(
            unordered_map<int, vector<int>>& adjList,
            vector<int>& distFromRoot,
            int start, int dist) {
            distFromRoot[start] = dist;
            // cout << "node: " << start << " -> " << dist << endl;
            for (int node : adjList[start]) {
                if (distFromRoot[node] == -1)
                    dfsRecordDistFromRoot(adjList, distFromRoot, node, dist + 1);
            }
        }

        void moveBob(
            unordered_map<int, vector<int>>& adjList,
            vector<int>& distFromRoot,
            vector<int>& bobTime,
            int start, int time) {
            bobTime[start] = time;
            // cout << "node: " << start << " -> " << time << endl;
            if (start == 0) return;
            int minDist = INT_MAX;
            int minNode = -1;
            for (int node : adjList[start]) {
                if (minDist > distFromRoot[node]) {
                    minNode = node;
                    minDist = distFromRoot[node];
                }
            }
            moveBob(adjList, distFromRoot, bobTime, minNode, time + 1);
        }

        void moveAlice(
            unordered_map<int, vector<int>>& adjList,
            vector<int>& amount,
            vector<int>& bobTime,
            vector<bool>& visited,
            int start, int time, int income) {
            if (time == bobTime[start]) {
                income += amount[start] / 2;
                // cout << "arrived " << start << " same" << endl;
            } else if (time < bobTime[start] || bobTime[start] == -1) {
                income += amount[start];
                // cout << "arrived " << start << " slower" << endl;
            }
            // cout << "node: " << start << " -> " << income << endl;
            visited[start] = true;
            bool toLeaf = true;
            for (int node : adjList[start]) {
                if (!visited[node]) {
                    toLeaf = false;
                    moveAlice(adjList, amount, bobTime, visited, node, time + 1, income);
                }
            }
            if (toLeaf) {
                res = max(res, income);
                // cout << "res= " << res << endl;
            }
        }
    };

    // Bob's path is fixed
    // For each node on Bob's path, record what time does Bob arrive
    // Do DFS from root to leaf,
        // if Alice arrived time == Bob's arrived time, split the income or cost
        // if Alice arrived time > Bob's arrived time, no income or cost for Alice
    // Record the max score