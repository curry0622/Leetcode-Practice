class Solution {
public:
    int maximumSwap(int num) {
        int res = num;
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());

        for (int i = 0; i < digits.size(); i++) {
            int mx = digits[i];
            int mxi = i;
            for (int j = i + 1; j < digits.size(); j++) {
                mx = max(mx, digits[j]);
                if (mx == digits[j])
                    mxi = j;
            }
            if (mxi != i) {
                vector<int> tmp = digits;
                swap(tmp[i], tmp[mxi]);
                res = max(vtoi(tmp), res);
            }
        }

        return res;
    }

    int vtoi(vector<int> digits) {
        int res = 0;
        for (int i = 0; i < digits.size(); i++) {
            res += digits[i] * pow(10, digits.size() - i - 1);
        }
        return res;
    }
};