class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int prevStart = meetings[0][0], prevEnd = meetings[0][1];
        int res = prevStart - 1;
        for (int i = 1; i < meetings.size(); i++) {
            int curStart = meetings[i][0], curEnd = meetings[i][1];
            if (curStart <= prevEnd) {
                prevEnd = max(prevEnd, curEnd);
            } else {
                res += curStart - prevEnd - 1;
                prevStart = curStart;
                prevEnd = curEnd;
            }
        }
        if (prevEnd < days) {
            res += days - prevEnd;
        }
        return res;
    }
};