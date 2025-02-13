class Solution {
using ll = long long;
using min_heap = priority_queue<ll, vector<ll>, greater<ll>>;
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        min_heap mh;
        for (int n : nums) {
            mh.push(n);
        }
        while (mh.top() < k) {
            ll a = mh.top();
            mh.pop();
            ll b = mh.top();
            mh.pop();
            ll c = min(a, b) * 2 + max(a, b);
            mh.push(c);
            res++;
        }
        return res;
    }
};