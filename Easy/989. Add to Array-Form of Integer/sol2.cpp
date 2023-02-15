class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int sum = k, carry = 0;
        for (int i = num.size()-1; i >= 0; i--) {
            sum += num[i] + carry;
            num[i] = sum % 10;
            carry = sum / 10;
            sum = 0;
        }
        while (carry > 0) {
            num.insert(num.begin(), carry % 10);
            carry /= 10;
        }
        return num;
    }
};