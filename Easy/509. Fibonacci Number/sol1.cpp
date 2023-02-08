class Solution {
public:
    vector<int> record;

    int fib(int n, bool first = true) {
        if (first)
            record = vector<int>(n+1, -1);
        if (n == 0) {
            record[0] = 0;
            return 0;
        }
        if (n == 1) {
            record[1] = 1;
            return 1;
        }
        int n1 = record[n-1];
        int n2 = record[n-2];
        if (n1 == -1)
            n1 = fib(n-1, false);
        if (n2 == -1)
            n2 = fib(n-2, false);
        return n1+n2;
    }
};