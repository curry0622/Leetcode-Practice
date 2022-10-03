class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<int> vec1(target + 1, 0), vec2;
        for(int i = 1; i <= k && i <= target; i++)
            vec1[i] = 1;
        vec2 = vec1;

        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                int sum = 0;
                for(int m = 1; m <= k; m++) {
                    if(j - m >= 0)
                        sum = (sum + vec1[j - m]) % mod;
                }
                vec2[j] = sum;
            }
            vec1 = vec2;
        }

        return vec1[target];
    }
};