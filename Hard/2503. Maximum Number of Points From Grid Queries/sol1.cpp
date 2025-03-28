struct Compare {
    bool operator()(const tuple<int, int, int>& x, const tuple<int, int, int>& y) {
        return get<2>(x) > get<2>(y); // Compare based on 'c' (third element)
    }
};
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), k = queries.size();
        vector<int> res(k, 0);
        vector<vector<int>> visited(m, vector<int>(n, 0));
        unordered_map<int, deque<int>> idx;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> minHeap;
        minHeap.push({0, 0, grid[0][0]});
        visited[0][0] = true;
        for (int i = 0; i < k; i++) {
            idx[queries[i]].push_back(i);
        }
        sort(queries.begin(), queries.end());
        int pt = 0;
        for (auto q : queries) {
            if (!minHeap.empty()) {
                while (!minHeap.empty() && get<2>(minHeap.top()) < q) {
                    auto [i, j, val] = minHeap.top();
                    pt++;
                    minHeap.pop();
                    if (i-1 >= 0 && !visited[i-1][j]) {
                        visited[i-1][j] = true;
                        minHeap.push({i-1, j, grid[i-1][j]});
                    }
                    if (j-1 >= 0 && !visited[i][j-1]) {
                        visited[i][j-1] = true;
                        minHeap.push({i, j-1, grid[i][j-1]});
                    }
                    if (i+1 < m && !visited[i+1][j]) {
                        visited[i+1][j] = true;
                        minHeap.push({i+1, j, grid[i+1][j]});
                    }
                    if (j+1 < n && !visited[i][j+1]) {
                        visited[i][j+1] = true;
                        minHeap.push({i, j+1, grid[i][j+1]});
                    }
                }
            }
            res[idx[q].front()] = pt;
            idx[q].pop_front();
        }
        return res;
    }
};