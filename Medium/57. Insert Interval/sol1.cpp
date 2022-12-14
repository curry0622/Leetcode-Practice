class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Special case
        if(intervals.size() == 0)
            return {newInterval};

        // Insert
        bool inserted = false;
        for(int i = 0; i < intervals.size(); i++) {
            if(newInterval[0] < intervals[i][0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
                break;
            }
        }
        if(!inserted)
            intervals.push_back(newInterval);

        // Merge
        for(int i = 0; i < intervals.size() - 1; i++) {
            int j;
            for(j = i + 1; j < intervals.size(); j++) {
                if(intervals[i][1] < intervals[j][0]) {
                    break;
                }
            }
            if(j > i + 1) {
                vector<int> merged = {intervals[i][0], max(intervals[i][1], intervals[j - 1][1])};
                intervals.erase(intervals.begin() + i, intervals.begin() + j);
                intervals.insert(intervals.begin() + i, merged);
                i--;
            }
        }

        // Return
        return intervals;
    }
};