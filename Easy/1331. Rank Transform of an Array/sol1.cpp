class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0);
        vector<int> sorted = arr;
        map<int, int> mp;
        sort(sorted.begin(), sorted.end());

        int index = 1;
        for (int num : sorted) {
            if (mp.find(num) == mp.end()) {
                mp[num] = index++;
            }
        }

        for (int i = 0; i < n; i++) {
            res[i] = mp[arr[i]];
        }

        return res;
    }
};