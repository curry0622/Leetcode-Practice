class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> color(numCourses, 0); // 0: white, 1: gray, 2: black

        // construct gragh
        for(auto p: prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        // detect cycle
        for(int i = 0; i < numCourses; i++) {
            if(color[i] == 0) {
                bool hasCycle = dfs(graph, color, i);
                if(hasCycle)
                    return false;
            }
        }

        return true;
    }

    bool dfs(const vector<vector<int>>& graph, vector<int>& color, int u) {
        color[u] = 1;
        for(int v: graph[u]) {
            if(color[v] == 0) {
                if(dfs(graph, color, v)) {
                    return true;
                }
            } else if(color[v] == 1) {
                return true;
            }
        }
        color[u] = 2;
        return false;
    }
};