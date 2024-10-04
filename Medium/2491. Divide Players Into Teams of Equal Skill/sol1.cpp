class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        int n = skill.size();
        for (int s : skill) {
            sum += s;
        }
        sum = sum * 2 / n;
        map<int, int> freq;
        for (int s : skill) {
            freq[s]++;
        }
        long long res = 0;
        for (long long i = 1; i < sum; i++) {
            if (i == sum - i) {
                if (freq[i] % 2) {
                    res = -1;
                    break;
                }
                res += freq[i] / 2 * i * i;
            } else if (freq[i] == freq[sum - i]) {
                res += freq[i] * i * (sum - i);
                freq[i] = 0;
                freq[sum - i] = 0;
            } else {
                res = -1;
                break;
            }
        }
        return res;
    }
};