class Solution {
using ll = long long;
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<ll> maxHeap;
        priority_queue<ll, vector<ll>, greater<ll>> minHeap;
        ll maxSum = 0, minSum = 0;
        for (int i = 0; i < weights.size() - 1; i++) {
            ll sum = weights[i] + weights[i + 1];
            maxHeap.push(sum);
            minHeap.push(sum);
            if (maxHeap.size() >= k) {
                maxHeap.pop();
            }
            if (minHeap.size() >= k) {
                minHeap.pop();
            }
        }
        while (!maxHeap.empty()) {
            minSum += maxHeap.top();
            maxHeap.pop();
        }
        while (!minHeap.empty()) {
            maxSum += minHeap.top();
            minHeap.pop();
        }
        return maxSum - minSum;
    }
};

// [1, 3, 5, 1, 2, 4, 6, 7], k = 2
//   3, 8, 6, 3, 6, 10, 6