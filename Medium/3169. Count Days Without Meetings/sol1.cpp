class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> record;
        for (auto m : meetings) {
            record[m[0]]++;
            record[m[1]+1]--;
        }
        int sum = 0, res = 0, prev = 1;
        for (auto r : record) {
            int curDay = r.first;
            int diff = r.second;
            if (sum == 0) {
                res += curDay - prev;
            }
            sum += diff;
            prev = curDay;
        }
        if (sum == 0) {
            res += days - prev + 1;
        }
        return res;
    }
};