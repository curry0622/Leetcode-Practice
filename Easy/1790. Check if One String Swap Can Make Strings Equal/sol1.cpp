class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i1 = -1, i2 = -1;
        int len = s1.size();
        for (int i = 0; i < len; i++) {
            if (s1[i] != s2[i]) {
                if (i1 == -1) {
                    i1 = i;
                } else if (i2 == -1) {
                    i2 = i;
                    break;
                }
            }
        }
        if (i1 != -1 && i2 != -1) {
            swap(s1[i1], s1[i2]);
            return s1 == s2;
        }
        if (i1 == -1 && i2 == -1) {
            return true;
        }
        return false;
    }
};