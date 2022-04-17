class Solution {
public:
    bool isPalindrome(int x) {
        string xStr = to_string(x);
        string xReverse;
        for(int i = xStr.length() - 1; i >= 0; i--) {
            xReverse.push_back(xStr[i]);
        }
        return xStr.compare(xReverse) == 0;
    }
};