class Solution {
public:
    bool isHappy(int n) {
        int slow = next_n(n);
        int fast = next_n(next_n(n));

        while(slow != fast) {
            slow = next_n(slow);
            fast = next_n(next_n(fast));
        }

        return fast == 1;
    }

    int next_n(int n) {
        int sum = 0;
        while(n > 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};