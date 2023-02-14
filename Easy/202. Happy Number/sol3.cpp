class Solution {
public:
    bool isHappy(int n) {
        set<int> record;
        int new_n = n;
        while (new_n != 1) {
            int sum = 0;
            while (new_n > 0) {
                sum += pow(new_n % 10, 2);
                new_n /= 10;
            }
            new_n = sum;
            if (record.find(new_n) == record.end()) {
                record.insert(new_n);
            } else {
                return false;
            }
        }
        return true;
    }
};