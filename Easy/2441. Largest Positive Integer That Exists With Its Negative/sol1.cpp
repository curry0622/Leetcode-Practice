class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<bool> v(2001, false);
        for (int n : nums) {
            v[n+1001] = true;
        }
        for (int i = 1000; i >= 1; i--) {
            if (v[1001+i] && v[1001-i]) {
                return i;
            }
        }
        return -1;
    }
};