class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501, 0);
        for (int n : nums) {
            freq[n]++;
        }
        for (int i = 1; i <= 500; i++) {
            if (freq[i] & 1) {
                return false;
            }
        }
        return true;
    }
};