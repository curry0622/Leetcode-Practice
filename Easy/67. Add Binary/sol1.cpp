class Solution {
public:
    string addBinary(string a, string b) {
        int sum, carry = 0;
        string ans = "";
        while(a.compare("") != 0 || b.compare("") != 0) {
            sum = carry;
            if(a.compare("") != 0) {
                sum += a[a.length() - 1] - '0';
                a = a.substr(0, a.length() - 1);
            }
            if(b.compare("") != 0) {
                sum += b[b.length() - 1] - '0';
                b = b.substr(0, b.length() - 1);
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