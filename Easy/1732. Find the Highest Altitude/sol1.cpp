class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0, max = 0;
        for (const int& h : gain) {
            curr += h;
            if (curr > max)
                max = curr;
        }
        return max;
    }
};