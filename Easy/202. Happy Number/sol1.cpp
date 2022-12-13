class Solution {
public:
    bool isHappy(int n) {
        vector<int> record;
        while(n != 1) {
            int sum = 0;
            while(n > 0) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            n = sum;
            if(find(record.begin(), record.end(), n) == record.end()) {
                record.push_back(n);
            } else {
                return false;
            }
        }
        return true;
    }
};