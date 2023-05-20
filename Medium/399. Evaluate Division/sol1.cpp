class Solution {
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        int index = 0;
        map<string, int> vars;
        for (const auto &v : equations) {
            if (vars.find(v[0]) == vars.end()) {
                vars[v[0]] = index++;
            }
            if (vars.find(v[1]) == vars.end()) {
                vars[v[1]] = index++;
            }
        }

        int n = vars.size();
        vector<vector<double>> graph(n, vector<double>(n, DBL_MAX));
        for (int i = 0; i < equations.size(); i++) {
            int a = vars[equations[i][0]], b = vars[equations[i][1]];
            double val = values[i];
            graph[a][b] = val;
            graph[b][a] = 1 / val;
        }

        APSP(graph);

        vector<double> result;
        for (const auto &q: queries) {
            string a = q[0], b = q[1];
            if (vars.find(a) == vars.end() || vars.find(b) == vars.end())
                result.push_back(-1);
            else {
                double dist = graph[vars[a]][vars[b]];
                result.push_back(dist == DBL_MAX ? -1 : dist);
            }
        }

        return result;
    }

    void APSP(vector<vector<double>>& graph) {
        int n = graph.size();
        int i, j, k;
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (
                        graph[k][j] != DBL_MAX &&
                        graph[i][k] != DBL_MAX &&
                        graph[i][j] > graph[i][k] * graph[k][j]
                    )
                        graph[i][j] = graph[i][k] * graph[k][j];
                }
            }
        }
    }
};