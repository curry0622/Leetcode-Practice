class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int freqT[1001] = {0};
        int freqA[1001] = {0};

        for (int t : target) {
            freqT[t]++;
        }
        for (int a : arr) {
            freqA[a]++;
        }
        for (int i = 1; i <= 1000; i++) {
            if (freqT[i] != freqA[i])
                return false;
        }
        return true;
    }
};