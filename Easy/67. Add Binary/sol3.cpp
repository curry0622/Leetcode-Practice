class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int ia = a.size()-1, ib = b.size()-1;
        int sum = 0, carry = 0;

        while (ia >= 0 && ib >= 0) {
            sum = (a[ia]-'0') + (b[ib]-'0') + carry;
            carry = sum / 2;
            sum = sum % 2;
            ia--, ib--;
            res = char(sum+'0') + res;
        }
        while (ia >= 0) {
            sum = (a[ia]-'0') + carry;
            carry = sum / 2;
            sum = sum % 2;
            ia--;
            res = char(sum+'0') + res;
        }
        while (ib >= 0) {
            sum = (b[ib]-'0') + carry;
            carry = sum / 2;
            sum = sum % 2;
            ib--;
            res = char(sum+'0') + res;
        }

        return carry ? '1'+res : res;
    }
};