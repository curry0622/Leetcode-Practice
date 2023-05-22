class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> freq;
        for (const int &n : nums) {
            freq[n]++;
        }

        vector<vector<int>> buckets(n, vector<int>{});
        for (auto iter = freq.begin(); iter != freq.end(); iter++) {
            int val = iter->first, cnt = iter->second;
            buckets[cnt - 1].push_back(val);
        }

        vector<int> res;
        int i = buckets.size() - 1;
        while (k > 0) {
            if (buckets[i].size() > 0) {
                for (const auto &num : buckets[i])
                    res.push_back(num);
                k -= buckets[i].size();
            }
            i--;
        }

        return res;
    }
};