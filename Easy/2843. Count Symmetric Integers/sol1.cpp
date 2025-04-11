class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int i = low; i <= high; i++) {
            if (isValid(i)) res++;
        }
        return res;
    }

    bool isValid(int num) {
        int nDigit = (int)log10(abs(num)) + 1;
        if (nDigit & 1) return false;
        int sum = 0;
        for (int i = 0; i < nDigit/2; i++) {
            sum += num % 10;
            num /= 10;
        }
        for (int i = 0; i < nDigit/2; i++) {
            sum -= num % 10;
            num /= 10;
        }
        return sum == 0;
    }
};