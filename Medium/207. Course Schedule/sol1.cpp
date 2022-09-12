class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>(0));

        for(auto p: prerequisites) {
            indeg[p[0]]++;
            graph[p[1]].push_back(p[0]);
        }

        while(true) {
            // stop condition
            for(int i = 0; i < indeg.size(); i++) {
                if(indeg[i] != -1) {
                    break;
                } else if(i == indeg.size() - 1) {
                    return true;
                }
            }

            // find indeg == 0
            int idx = -1;
            for(int i = 0; i < indeg.size(); i++) {
                if(indeg[i] == 0) {
                    idx = i;
                    indeg[idx] = -1;
                    break;
                }
            }

            // update indeg
            if(idx != -1) {
                for(int course: graph[idx]) {
                    indeg[course]--;
                }
            } else {
                break;
            }
        }

        return false;
    }
};