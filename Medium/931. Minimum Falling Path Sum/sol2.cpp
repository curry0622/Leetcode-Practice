class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mtx) {
        vector<vector<int>> visited = vector<vector<int>>(mtx.size(), vector<int>(mtx.size(), 0));
        int ans = INT_MAX;
        for(int x = 0; x < mtx.size(); x++) {
            traverse(x, 0, mtx, visited);
            int tmp = mtx[0][x];
            if(ans > tmp)
                ans = tmp;
        }
        return ans;
    }

    void traverse(int x, int y, vector<vector<int>>& mtx, vector<vector<int>>& visited) {
        if(y >= mtx.size() - 1) {
            return;
        }
        int l = INT_MAX, m = INT_MAX, r = INT_MAX;
        if(x > 0) {
            if(!visited[y + 1][x - 1]) {
                traverse(x - 1, y + 1, mtx, visited);
                visited[y + 1][x - 1] = 1;
            }
            l = mtx[y + 1][x - 1];
        }
        if(!visited[y + 1][x]) {
            traverse(x, y + 1, mtx, visited);
            visited[y + 1][x] = 1;
        }
        m = mtx[y + 1][x];
        if(x < mtx.size() - 1) {
            if(!visited[y + 1][x + 1]) {
                traverse(x + 1, y + 1, mtx, visited);
                visited[y + 1][x + 1] = 1;
            }
            r = mtx[y + 1][x + 1];
        }
        mtx[y][x] += min3(l, m, r);
    }

    int min3(const int& a, const int& b, const int& c) {
        if(a <= b && a <= c)
            return a;
        if(b <= a && b <= c)
            return b;
        if(c <= a && c <= b)
            return c;
        return INT_MAX;
    }
};