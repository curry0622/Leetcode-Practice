class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans = 0, n = properties.size();
        sort(properties.begin(), properties.end(), cmp);
        int max = INT_MIN;
        for(auto p: properties) {
            if(p[1] < max)
                ans++;
            else
                max = p[1];
        }
        return ans;
    }

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if(a[0] != b[0])
            return a[0] > b[0];
        return a[1] < b[1];
    }
};