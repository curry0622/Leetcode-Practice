// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long left = 1, right = n;
        while (left < right) {
            long mid = (left+right)/2;
            bool isBad = isBadVersion(mid);
            if (isBad)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};