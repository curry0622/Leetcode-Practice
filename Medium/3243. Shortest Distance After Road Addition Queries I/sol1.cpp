class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                dist[i][j] = j - i;
            }
        }

        vector<int> res;
        for (auto q : queries) {
            int from = q[0], to = q[1];
            // cout << from << ", " << to << endl;
            dist[from][to] = 1;
            for (int i = from; i >= 0; i--) {
                for (int j = to; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][from] + 1 + dist[to][j]);
                }
            }
            // print(dist);

            res.push_back(dist[0][n-1]);
        }

        return res;
    }

    void print(vector<vector<int>> g) {
        for (auto row : g) {
            for (auto val : row) {
                if (val == INT_MAX)
                    cout << "x ";
                else
                    cout << val << " ";
            }
            cout << endl;
        }
    }
};