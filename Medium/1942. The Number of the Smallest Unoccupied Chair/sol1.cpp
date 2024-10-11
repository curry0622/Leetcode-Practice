class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, 0);
        int targetArriveTime = times[targetFriend][0];
        sort(times.begin(), times.end());

        for (auto v : times) {
            int arrive = v[0], leave = v[1];
            for (int i = 0; i < n; i++) {
                if (arrive >= chairs[i]) {
                    chairs[i] = leave;
                    if (arrive == targetArriveTime) {
                        return i;
                    }
                    break;
                }
            }
        }

        return n-1;
    }
};