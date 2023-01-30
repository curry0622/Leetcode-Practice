class Solution {
public:
    vector<int> trib;

    int tribonacci(int n, bool first = true) {
        if(first)
            trib = vector<int>(n, -1);
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int a, b, c;
        if (trib[n-1] == -1) {
            a = tribonacci(n-1, false);
            trib[n-1] = a;
        } else {
            a = trib[n-1];
        }
        if (trib[n-2] == -1) {
            b = tribonacci(n-2, false);
            trib[n-2] = b;
        } else {
            b = trib[n-2];
        }
        if (trib[n-3] == -1) {
            c = tribonacci(n-3, false);
            trib[n-3] = c;
        } else {
            c = trib[n-3];
        }
        return a + b + c;
    }
};