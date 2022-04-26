class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int len = num.size();
        int sum;
        for(int i = len - 1; i >= 0; i--) {
            sum = k + num[i];
            k = sum / 10;
            sum %= 10;
            ans.push_back(sum);
        }
        while(k != 0) {
            ans.push_back(k % 10);
            k /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};