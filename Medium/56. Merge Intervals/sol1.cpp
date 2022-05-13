class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        for(auto itv: intervals) {
            bool found = false;
            for(int i = 0; i < ans.size(); i++) {
                if(itv[0] <= ans[i][1]) {
                    if(itv[1] > ans[i][1])
                        ans[i] = vector<int>{ans[i][0], itv[1]};
                    found = true;
                    break;
                }
            }
            if(!found)
                ans.push_back(itv);
        }
        return ans;
    }
};