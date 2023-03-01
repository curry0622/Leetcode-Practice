class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        int size = max - min + 1;
        vector<int> freq(size, 0), sorted;

        for (const int& num : nums) {
            freq[num-min]++;
        }
        for (int i = 0; i < freq.size(); i++) {
            int val = min + i;
            int cnt = freq[i];

            for (int j = 0; j < cnt; j++)
                sorted.push_back(val);
        }

        return sorted;
    }
};