class Solution {
using ll = long long;
public:
    ll repairCars(vector<int>& ranks, int cars) {
        ll left = 0;
        ll right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;
        ll res = right;
        while(left <= right) {
            ll mid = left + (right - left) / 2;
            if (isValid(ranks, cars, mid)) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }

    bool isValid(const vector<int>& ranks, int cars, ll time) {
        for (auto r : ranks) {
            cars -= int(sqrt(time / r));
            if (cars <= 0) return true;
        }
        return false;
    }
};