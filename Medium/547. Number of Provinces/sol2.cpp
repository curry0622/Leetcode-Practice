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
                    int i_p = findParent(parent, i);
                    int j_p = findParent(parent, j);
                    if (i_p != j_p)
                        parent[j_p] = i_p;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (i == parent[i])
                cnt++;

        return cnt;
    }

    int findParent(vector<int>& parent, int i) {
        if (i != parent[i])
            parent[i] = findParent(parent, parent[i]);
        return parent[i];
    }
};