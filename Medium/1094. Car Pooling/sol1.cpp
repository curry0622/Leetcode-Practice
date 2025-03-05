class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for (const auto& t : trips) {
            minHeap.push({t[1], 0-t[0]});
            minHeap.push({t[2], t[0]});
        }
        while (!minHeap.empty()) {
            const auto& top = minHeap.top();
            capacity += top.second;
            if (capacity < 0)
                return false;
            minHeap.pop();
        }
        return true;
    }
};