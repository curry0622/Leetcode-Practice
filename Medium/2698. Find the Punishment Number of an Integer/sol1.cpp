class Solution {
using vec = vector<int>;
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = calc(i);
            res += tmp;
        }
        return res;
    }

    int calc(int n) {
        vec v;
        int n2 = n * n;
        int curr = n2;
        while (curr > 0) {
            v.push_back(curr % 10);
            curr /= 10;
        }
        reverse(v.begin(), v.end());
        curr = 0;
        if (recur(v, 0, curr, n)) {
            return n2;
        }
        return 0;
    }

    bool recur(const vec& v, const int start, int& curr, const int& target) {
        if (start == v.size() && curr == target) {
            return true;
        }
        bool res = false;
        int sum = 0;
        for (int i = start; i < v.size(); i++) {
            sum += v[i];
            if (sum > target || curr + sum > target) {
                break;
            }
            curr += sum;
            res |= recur(v, i + 1, curr, target);
            curr -= sum;
            sum *= 10;
        }
        return res;
    }
};
