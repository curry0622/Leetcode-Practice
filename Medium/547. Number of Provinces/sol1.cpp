class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    int p = findParent(parent, j);
                    parent[p] = findParent(parent, i);
                }
            }
        }

        map<int, int> record;
        for (int i = 0; i < n; i++) {
            record[findParent(parent, i)]++;
        }

        return record.size();
    }

    int findParent(vector<int>& parent, int i) {
        if (i != parent[i])
            parent[i] = findParent(parent, parent[i]);
        return parent[i];
    }
};