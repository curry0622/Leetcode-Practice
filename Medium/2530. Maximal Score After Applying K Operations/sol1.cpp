class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for (int n : nums) pq.push(n);
        long long res = 0;
        for (int i = 0; i < k; i++) {
            int top = pq.top();
            res += top;
            pq.pop();
            pq.push(ceil((double)top / 3));
        }
        return res;
    }
};