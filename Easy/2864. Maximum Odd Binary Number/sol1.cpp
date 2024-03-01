class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string res = "";
        int oneCnt = 0;
        for (char c : s) {
            if (c == '1')
                oneCnt++;
        }
        if (oneCnt > 1)
            res += string(oneCnt-1, '1');
        res += string(s.size()-oneCnt, '0');
        if (oneCnt > 0)
            res += "1";
        return res;
    }
};