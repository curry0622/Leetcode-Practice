// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int l = 1, r = n;
        while(l <= r) {
            long long int m = (l + r) / 2;
            if(l < m && m < r) {
                if(!isBadVersion(l) && isBadVersion(m)) {
                    r = m;
                    continue;
                }
                if(!isBadVersion(m) && isBadVersion(r)) {
                    l = m;
                    continue;
                }
                if(isBadVersion(l) && isBadVersion(m))
                    return l;
            } else {
                if(l == m) {
                    if(isBadVersion(m))
                        return m;
                    if(isBadVersion(r))
                        return r;
                } else {
                    if(isBadVersion(l))
                        return l;
                    if(isBadVersion(m))
                        return m;
                }
            }
        }
        return 0;
    }
};