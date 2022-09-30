class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1; i < 10; i++)
            genNum(n - 1, k, i, i, ans);
        return ans;
    }

    void genNum(int n, int& k, int sum, int last, vector<int>& ans) {
        if(n == 0) {
            ans.push_back(sum);
            return;
        }
        for(int i = 0; i < 10; i++) {
            if(abs(i - last) == k) {
                genNum(n - 1, k, sum * 10 + i, i, ans);
            }
        }
    }
};