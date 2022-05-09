class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        while(n != 0) {
            if(n % 2 == 1) {
                ans *= x;
            }
            if(n % 2 == -1) {
                ans /= x;
            }
            x = x * x;
            n /= 2;
        }
        return ans;
    }
};