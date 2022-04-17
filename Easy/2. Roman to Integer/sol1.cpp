class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int ans = 0;
        for(int i = 0; i < len; i++) {
            int tmpAns = singleSymbolToInt(s[i]);
            if (i < len - 1) {
                string tmpStr;
                tmpStr.push_back(s[i]);
                tmpStr.push_back(s[i + 1]);
                int doub = doubleSymbolsToInt(tmpStr);
                if (doub != 0) {
                    tmpAns = doub;
                    i++;
                }
            }
            ans += tmpAns;
        }
        return ans;
    }
    
    int singleSymbolToInt(char c) {
        if (c == 'I') 
            return 1;
        if (c == 'V')
            return 5;
        if (c == 'X')
            return 10;
        if (c == 'L')
            return 50;
        if (c == 'C')
            return 100;
        if (c == 'D')
            return 500;
        if (c == 'M')
            return 1000;
        return 0;
    }
    
    int doubleSymbolsToInt(string s) {
        char first = s[0];
        char second = s[1];
        if (first == 'I' && second == 'V')
            return 4;
        if (first == 'I' && second == 'X')
            return 9;
        if (first == 'X' && second == 'L')
            return 40;
        if (first == 'X' && second == 'C')
            return 90;
        if (first == 'C' && second == 'D')
            return 400;
        if (first == 'C' && second == 'M')
            return 900;
        return 0;
    }
};
