class Solution {
public:
    string addBinary(string a, string b) {
        int sum, carry = 0;
        int i = a.length() - 1, j = b.length() - 1;
        string ans = "";
        while(i >= 0 || j >= 0) {
            sum = carry;
            if(i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            if(sum >= 2) {
                sum -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            ans = to_string(sum) + ans;
        }
        if(carry == 1)
            ans = to_string(1) + ans;
        return ans;
    }
};