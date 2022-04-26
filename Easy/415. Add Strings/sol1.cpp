class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.length() - 1, j = num2.length() - 1;
        int sum, carry = 0;
        while(i >= 0 || j >= 0) {
            sum = carry;
            if(i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            if(j >= 0) {
                sum += num2[j] - '0';
                j--;
            }
            if(sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            char c = sum + '0';
            ans.push_back(c);
        }
        if(carry != 0) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};