class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int freq[101] = {0};
        for (int num : nums) {
            freq[num]++;
        }
        int cnt = 0;
        for (int i = 1; i <= 100; i++) {
            if (i < k && freq[i] > 0) return -1;
            if (i > k && freq[i] > 0) cnt++;
        }
        return cnt;
    }
};