class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int res = 0;
        unordered_map<int, vector<int>> record;
        for (auto p : pick) {
            record[p[0]].push_back(p[1]);
        }
        for (auto iter = record.begin(); iter != record.end(); iter++) {
            int num = iter->first;
            vector<int> balls = iter->second;
            sort(balls.begin(), balls.end());
            // cout << num << " -> ";
            // printVec(balls);
            int last = balls[0];
            int curr = 1;
            bool same = true;
            for (int i = 1; i < balls.size(); i++) {
                if (last == balls[i]) {
                    curr++;
                    same = true;
                } else {
                    last = balls[i];
                    if (curr > num) {
                        res++;
                        // cout << "add " << num << endl;
                        curr = 1;
                        same = false;
                        break;
                    }
                    curr = 1;
                    same = false;
                }
            }
            if (same && curr > num) {
                res++;
                // cout << "add " << num << endl;
            }
        }
        return res;
    }

    void printVec(vector<int> vec) {
        for (int n : vec)
            cout << n << " ";
        cout << endl;
    }
};