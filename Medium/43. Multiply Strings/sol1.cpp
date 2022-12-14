class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";

        string result = "";
        int len1 = num1.size(), len2 = num2.size();
        vector<int> mul = vector<int>(len1 + len2 - 1, 0);

        for(int i = 0; i < len1; i++) {
            for(int j = 0; j < len2; j++) {
                mul[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int carry = 0;
        for(int i = mul.size() - 1; i >= 0; i--) {
            mul[i] += carry;
            carry = mul[i] / 10;
            mul[i] %= 10;
            result += (char)(mul[i] + '0');
        }
        if(carry != 0)
            result += (char)(carry + '0');

        reverse(result.begin(), result.end());
        return result;
    }
};