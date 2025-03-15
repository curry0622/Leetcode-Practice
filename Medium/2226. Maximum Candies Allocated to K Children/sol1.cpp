class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = 1;
        for (auto c : candies) {
            right = max(right, c);
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(candies, k, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return isValid(candies, k, left-1) ? left-1 : 0;
    }

    bool isValid(const vector<int>& candies, long long k, int mid) {
        if (mid <= 0) return false;
        for (auto& c : candies) {
            k -= c / mid;
        }
        return k <= 0;
    }
};