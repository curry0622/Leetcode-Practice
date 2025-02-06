class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                freq[nums[i] * nums[j]]++;
            }
        }
        for (auto iter = freq.begin(); iter != freq.end(); iter++) {
            int f = iter->second;
            if (f > 1) {
                res += f * (f - 1) / 2 * 8;
            }
        }
        return res;
    }
};